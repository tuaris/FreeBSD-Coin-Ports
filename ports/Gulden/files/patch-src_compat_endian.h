--- src/compat/endian.h.orig	2015-08-13 11:33:58 UTC
+++ src/compat/endian.h
@@ -15,6 +15,8 @@
 
 #if defined(HAVE_ENDIAN_H)
 #include <endian.h>
+#elif defined(HAVE_SYS_ENDIAN_H)
+#include <sys/endian.h>
 #endif
 
 #if defined(WORDS_BIGENDIAN)
