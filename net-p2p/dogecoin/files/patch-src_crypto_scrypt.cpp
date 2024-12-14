--- src/crypto/scrypt.cpp.orig	2024-12-01 01:55:09 UTC
+++ src/crypto/scrypt.cpp
@@ -32,6 +32,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
+#include <sys/endian.h>
 
 #if defined(USE_SSE2) && !defined(USE_SSE2_ALWAYS)
 #ifdef _MSC_VER
