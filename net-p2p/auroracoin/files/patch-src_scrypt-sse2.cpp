--- src/scrypt-sse2.cpp.orig	2018-09-14 10:16:16 UTC
+++ src/scrypt-sse2.cpp
@@ -31,6 +31,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
+#include <sys/endian.h>
 #include <openssl/sha.h>
 
 #include <emmintrin.h>
