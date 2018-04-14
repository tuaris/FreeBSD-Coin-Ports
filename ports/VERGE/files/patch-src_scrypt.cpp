--- src/scrypt.cpp.orig	2018-04-07 02:55:54 UTC
+++ src/scrypt.cpp
@@ -55,15 +55,6 @@ static inline uint32_t be32dec(const voi
 }
 */
 
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
