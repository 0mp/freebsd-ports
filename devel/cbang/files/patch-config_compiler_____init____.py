--- config/compiler/__init__.py.orig	2026-01-02 13:27:38 UTC
+++ config/compiler/__init__.py
@@ -259,7 +259,7 @@ def configure(conf, cstd = 'c99'):
     # Optimizations
     if optimize:
         if compiler_mode == 'gnu':
-            env.AppendUnique(CCFLAGS = ['-O3'])
+            env.AppendUnique(CCFLAGS = [''])
 
         elif compiler_mode == 'msvc':
             env.AppendUnique(CCFLAGS = ['/O2', '/Zc:throwingNew'])
