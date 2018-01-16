--- src/Gulden/Common/scrypt.h.orig	2018-01-01 19:55:55 UTC
+++ src/Gulden/Common/scrypt.h
@@ -27,18 +27,4 @@ void PBKDF2_SHA256(const uint8_t* passwd
 
 void PBKDF2_SHA512(const char* pass, size_t passwdlen, const unsigned char* salt, size_t saltlen, int32_t iterations, unsigned char* digest, uint32_t outputbytes);
 
-static inline uint32_t le32dec(const void* pp)
-{
-    const uint8_t* p = (uint8_t const*)pp;
-    return ((uint32_t)(p[0]) + ((uint32_t)(p[1]) << 8) + ((uint32_t)(p[2]) << 16) + ((uint32_t)(p[3]) << 24));
-}
-
-static inline void le32enc(void* pp, uint32_t x)
-{
-    uint8_t* p = (uint8_t*)pp;
-    p[0] = x & 0xff;
-    p[1] = (x >> 8) & 0xff;
-    p[2] = (x >> 16) & 0xff;
-    p[3] = (x >> 24) & 0xff;
-}
 #endif
