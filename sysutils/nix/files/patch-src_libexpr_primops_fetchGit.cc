--- src/libexpr/primops/fetchGit.cc.orig	2018-12-28 21:26:26 UTC
+++ src/libexpr/primops/fetchGit.cc
@@ -5,6 +5,7 @@
 #include "pathlocks.hh"
 
 #include <sys/time.h>
+#include <sys/wait.h>
 
 #include <regex>
 
