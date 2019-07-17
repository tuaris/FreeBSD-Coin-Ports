--- src/smessage.cpp.orig	2014-11-06 21:36:20.000000000 -0500
+++ src/smessage.cpp	2014-11-06 21:36:30.000000000 -0500
@@ -3159,12 +3159,7 @@
     HMAC_CTX_init(&ctx);
     
     unsigned int nBytes;
-    if (!HMAC_Init_ex(&ctx, &civ[0], 32, EVP_sha256(), NULL)
-        || !HMAC_Update(&ctx, (unsigned char*) pHeader+4, SMSG_HDR_LEN-4)
-        || !HMAC_Update(&ctx, (unsigned char*) pPayload, nPayload)
-        || !HMAC_Update(&ctx, pPayload, nPayload)
-        || !HMAC_Final(&ctx, sha256Hash, &nBytes)
-        || nBytes != 32)
+    if (nBytes != 32)
     {
         if (fDebugSmsg)
             printf("HMAC error.\n");
@@ -3237,13 +3232,7 @@
             memcpy(civ+i, &nonse, 4);
         
         unsigned int nBytes;
-        if (!HMAC_Init_ex(&ctx, &civ[0], 32, EVP_sha256(), NULL)
-            || !HMAC_Update(&ctx, (unsigned char*) pHeader+4, SMSG_HDR_LEN-4)
-            || !HMAC_Update(&ctx, (unsigned char*) pPayload, nPayload)
-            || !HMAC_Update(&ctx, pPayload, nPayload)
-            || !HMAC_Final(&ctx, sha256Hash, &nBytes)
-            //|| !HMAC_Final(&ctx, &vchHash[0], &nBytes)
-            || nBytes != 32)
+        if (nBytes != 32)
             break;
         
         /*
@@ -3560,11 +3549,7 @@
     HMAC_CTX ctx;
     HMAC_CTX_init(&ctx);
     
-    if (!HMAC_Init_ex(&ctx, &key_m[0], 32, EVP_sha256(), NULL)
-        || !HMAC_Update(&ctx, (unsigned char*) &smsg.timestamp, sizeof(smsg.timestamp))
-        || !HMAC_Update(&ctx, &vchCiphertext[0], vchCiphertext.size())
-        || !HMAC_Final(&ctx, smsg.mac, &nBytes)
-        || nBytes != 32)
+    if (nBytes != 32)
         fHmacOk = false;
     
     HMAC_CTX_cleanup(&ctx);
@@ -3862,11 +3847,7 @@
     HMAC_CTX ctx;
     HMAC_CTX_init(&ctx);
     
-    if (!HMAC_Init_ex(&ctx, &key_m[0], 32, EVP_sha256(), NULL)
-        || !HMAC_Update(&ctx, (unsigned char*) &psmsg->timestamp, sizeof(psmsg->timestamp))
-        || !HMAC_Update(&ctx, pPayload, nPayload)
-        || !HMAC_Final(&ctx, MAC, &nBytes)
-        || nBytes != 32)
+    if (nBytes != 32)
         fHmacOk = false;
     
     HMAC_CTX_cleanup(&ctx);
