--- src/scrypt-sse2.cpp.orig	2017-11-20 09:40:53 UTC
+++ src/scrypt-sse2.cpp
@@ -33,6 +33,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
+#include <sys/endian.h>
 #include <openssl/sha.h>
 
 #include <emmintrin.h>
