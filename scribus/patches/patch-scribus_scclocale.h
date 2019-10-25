$NetBSD$

Support NetBSD.

--- scribus/scclocale.h.orig	2019-07-30 22:35:07.000000000 +0000
+++ scribus/scclocale.h
@@ -21,14 +21,14 @@
 #include <xlocale.h>
 #endif
 
-#if defined(Q_OS_SOLARIS) || defined (Q_OS_OPENBSD) || defined(Q_OS_FREEBSD) || defined(Q_OS_HAIKU)
+#if defined(Q_OS_SOLARIS) || defined (Q_OS_OPENBSD) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_HAIKU)
 #include <locale.h>
 #endif
 
 #if defined(Q_OS_WIN)
 #define XLocaleType _locale_t
 #else
-  #if defined (Q_OS_SOLARIS) || defined (Q_OS_OPENBSD) || defined(Q_OS_FREEBSD) || defined(Q_OS_HAIKU)
+  #if defined (Q_OS_SOLARIS) || defined (Q_OS_OPENBSD) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_HAIKU)
   #define XLocaleType char*   //dummy?
   #else
   #define XLocaleType locale_t
