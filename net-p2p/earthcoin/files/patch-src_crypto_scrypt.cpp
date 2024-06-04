--- src/crypto/scrypt.cpp.orig	2021-05-15 06:47:32 UTC
+++ src/crypto/scrypt.cpp
@@ -44,22 +44,6 @@
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
 /**
  * PBKDF2_SHA256(passwd, passwdlen, salt, saltlen, c, buf, dkLen):
  * Compute PBKDF2(passwd, salt, c, dkLen) using HMAC-SHA256 as the PRF, and
