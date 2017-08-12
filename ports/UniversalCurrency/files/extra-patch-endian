--- src/pbkdf2.cpp.orig	2015-04-28 10:47:39 UTC
+++ src/pbkdf2.cpp
@@ -12,19 +12,6 @@ be32dec(const void *pp)
         ((uint32_t)(p[1]) << 16) + ((uint32_t)(p[0]) << 24));
 }
 
-static inline void
-be32enc(void *pp, uint32_t x)
-{
-    uint8_t * p = (uint8_t *)pp;
-
-    p[3] = x & 0xff;
-    p[2] = (x >> 8) & 0xff;
-    p[1] = (x >> 16) & 0xff;
-    p[0] = (x >> 24) & 0xff;
-}
-
-
-
 /* Initialize an HMAC-SHA256 operation with the given key. */
 void
 HMAC_SHA256_Init(HMAC_SHA256_CTX * ctx, const void * _K, size_t Klen)
