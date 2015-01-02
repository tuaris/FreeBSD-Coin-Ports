--- src/scrypt.cpp.orig	2014-04-03 20:52:43 UTC
+++ src/scrypt.cpp
@@ -36,6 +36,7 @@
 #include <stdint.h>
 #include <string.h>
 #include <openssl/sha.h>
+#include <boost/lexical_cast.hpp>
 
 #if defined(USE_SSE2) && !defined(USE_SSE2_ALWAYS)
 #ifdef _MSC_VER
@@ -47,22 +48,6 @@
 #endif
 #endif
 
-static inline uint32_t be32dec(const void *pp)
-{
-	const uint8_t *p = (uint8_t const *)pp;
-	return ((uint32_t)(p[3]) + ((uint32_t)(p[2]) << 8) +
-	    ((uint32_t)(p[1]) << 16) + ((uint32_t)(p[0]) << 24));
-}
-
-static inline void be32enc(void *pp, uint32_t x)
-{
-	uint8_t *p = (uint8_t *)pp;
-	p[3] = x & 0xff;
-	p[2] = (x >> 8) & 0xff;
-	p[1] = (x >> 16) & 0xff;
-	p[0] = (x >> 24) & 0xff;
-}
-
 typedef struct HMAC_SHA256Context {
 	SHA256_CTX ictx;
 	SHA256_CTX octx;
@@ -329,4 +314,4 @@ void scrypt_1024_1_1_256(const char *inp
 {
 	char scratchpad[SCRYPT_SCRATCHPAD_SIZE];
     scrypt_1024_1_1_256_sp(input, output, scratchpad);
-}
\ No newline at end of file
+}
