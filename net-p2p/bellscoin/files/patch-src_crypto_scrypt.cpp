--- src/crypto/scrypt.cpp.orig	2024-09-13 11:52:56 UTC
+++ src/crypto/scrypt.cpp
@@ -32,6 +32,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
+#include <sys/endian.h>
 //#include <openssl/sha.h>
 
 #if defined(USE_SSE2) && !defined(USE_SSE2_ALWAYS)
