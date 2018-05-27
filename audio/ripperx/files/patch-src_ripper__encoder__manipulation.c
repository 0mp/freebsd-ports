--- src/ripper_encoder_manipulation.c.orig	2012-02-05 18:13:33 UTC
+++ src/ripper_encoder_manipulation.c
@@ -49,7 +49,6 @@
 #endif
 
 #include <sys/ioctl.h>
-#include <pty.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
@@ -317,7 +316,7 @@ static int execute_ripper_encoder_with_plugin(const ch
         dup2(pty_fd0, 0);
         dup2(tty_fd1, 1);
 
-        setpgrp();
+        setpgid(0, 0);
 	execute_using_shell(pi_com);
 
         dup2(stderr_fd, 2);
@@ -351,9 +350,9 @@ static int execute_ripper_encoder_with_plugin(const ch
         dup2(tty_fd0, 1);
         dup2(tty_fd0, 2);
 
-        setpgrp();
+        setpgid(0, 0);
 	execute_using_shell(pg_com);
-	
+
         dup2(stderr_fd, 2);
         perror(_("Failed to exec the specified program"));
         _exit(127);
