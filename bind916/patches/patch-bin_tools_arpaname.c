$NetBSD: patch-bin_tools_arpaname.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* C syntax.

--- bin/tools/arpaname.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ bin/tools/arpaname.c
@@ -14,7 +14,7 @@
 #include <isc/net.h>
 #include <isc/print.h>
 
-#define UNUSED(x) (void)(x)
+#define UNUSED(x) (void)&(x)
 
 int
 main(int argc, char *argv[]) {
