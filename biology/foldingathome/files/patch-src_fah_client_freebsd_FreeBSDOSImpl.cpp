--- src/fah/client/freebsd/FreeBSDOSImpl.cpp.orig	2026-09-18 23:19:24 UTC
+++ src/fah/client/freebsd/FreeBSDOSImpl.cpp
@@ -0,0 +1,119 @@
+/******************************************************************************\
+
+                  This file is part of the Folding@home Client.
+
+          The fah-client runs Folding@home protein folding simulations.
+                    Copyright (c) 2001-2024, foldingathome.org
+                               All rights reserved.
+
+       This program is free software; you can redistribute it and/or modify
+       it under the terms of the GNU General Public License as published by
+        the Free Software Foundation; either version 3 of the License, or
+                       (at your option) any later version.
+
+         This program is distributed in the hope that it will be useful,
+          but WITHOUT ANY WARRANTY; without even the implied warranty of
+          MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+                   GNU General Public License for more details.
+
+     You should have received a copy of the GNU General Public License along
+     with this program; if not, write to the Free Software Foundation, Inc.,
+           51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
+
+                  For information regarding this software email:
+                                 Joseph Coffland
+                          joseph@cauldrondevelopment.com
+
+\******************************************************************************/
+
+#include "FreeBSDOSImpl.h"
+
+#include <fah/client/App.h>
+
+#include <cbang/os/PowerManagement.h>
+#include <cbang/log/Logger.h>
+
+#include <array>
+#include <cstdio>
+
+#include <sys/socket.h>
+#include <netlink/netlink.h>
+#include <netlink/netlink_route.h>
+#include <unistd.h>
+#include <sys/utsname.h>
+
+using namespace FAH::Client;
+using namespace std;
+using namespace cb;
+
+
+namespace {
+  int open_uevent_netlink() {
+    sockaddr_nl sa {};
+    sa.nl_family = AF_NETLINK;
+    sa.nl_pid    = getpid();
+    sa.nl_groups = -1; // receive all broadcasted uevents
+
+    int sock = socket(AF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT);
+    if (sock < 0) return -1;
+    if (::bind(sock, (sockaddr *)&sa, sizeof(sa)) < 0) {
+      close(sock);
+      return -1;
+    }
+
+    return sock;
+  }
+}
+
+
+FreeBSDOSImpl::FreeBSDOSImpl(App &app) : OS(app), sock(open_uevent_netlink()) {
+  if (sock == -1) LOG_WARNING("Failed to open udev netlink socket, "
+    "may not be able to detect GPUs");
+  else {
+    auto flags = Event::EventFlag::EVENT_READ | Event::EventFlag::EVENT_PERSIST;
+    event = app.getEventBase().newEvent
+      (sock, this, &FreeBSDOSImpl::ueventMsg, flags);
+    event->add();
+  }
+}
+
+
+FreeBSDOSImpl::~FreeBSDOSImpl() {
+  if (sock != -1) close(sock);
+}
+
+
+const char *FreeBSDOSImpl::getName() const {return "freebsd";}
+
+
+const char *FreeBSDOSImpl::getCPU() const {
+  struct utsname name;
+
+  uname(&name);
+  string machine(name.machine);
+
+  if (machine.find("x86_64") != string::npos) return "amd64";
+  if (machine == "arch64" || machine == "arm64") return "arm64";
+
+  return OS::getCPU();
+}
+
+
+bool FreeBSDOSImpl::isSystemIdle() const {
+  return 15 < PowerManagement::instance().getIdleSeconds();
+}
+
+
+void FreeBSDOSImpl::ueventMsg() {
+  array<char, 4096> buf {};
+  auto len = recv(sock, buf.data(), buf.size() - 1, 0);
+  if (len < 0) return;
+
+  string msg(buf.data(), len);
+  LOG_DEBUG(4, "UEVENT: " << String::escapeC(msg));
+
+  // Only interested in DRM "add" events
+  if (msg.find("ACTION=add")    != string::npos &&
+      msg.find("SUBSYSTEM=drm") != string::npos)
+    gpuAdded();
+}
