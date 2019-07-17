--- src/uint256.h.orig	2014-06-29 00:33:51 UTC
+++ src/uint256.h
@@ -342,12 +342,12 @@ public:
     }
 
     unsigned char* begin()
-    {
+    const {
         return (unsigned char*)&pn[0];
     }
 
     unsigned char* end()
-    {
+    const {
         return (unsigned char*)&pn[WIDTH];
     }
 
