--- src/fah/client/OS.cpp.orig	2026-09-18 23:20:20 UTC
+++ src/fah/client/OS.cpp
@@ -35,6 +35,8 @@
 #include "win/WinOSImpl.h"
 #elif defined(__APPLE__)
 #include "osx/OSXOSImpl.h"
+#elif defined(__FreeBSD__)
+#include "freebsd/FreeBSDOSImpl.h"
 #else
 #include "lin/LinOSImpl.h"
 #endif
@@ -62,6 +64,9 @@ SmartPointer<OS> OS::create(App &app) {
 
 #elif defined(__APPLE__)
   return new OSXOSImpl(app);
+
+#elif defined(__FreeBSD__)
+  return new FreeBSDOSImpl(app);
 
 #else
   return new LinOSImpl(app);
