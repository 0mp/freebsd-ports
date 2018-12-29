--- src/linenoise/linenoise.cpp.orig	2018-12-28 20:56:06 UTC
+++ src/linenoise/linenoise.cpp
@@ -117,6 +117,8 @@
 
 #endif /* _WIN32 */
 
+#include <sys/stat.h>
+
 #include <stdio.h>
 #include <errno.h>
 #include <fcntl.h>
