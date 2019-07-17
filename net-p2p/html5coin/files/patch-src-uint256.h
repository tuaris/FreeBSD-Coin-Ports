--- src/uint256.h.orig	2015-03-26 22:29:14 UTC
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
 
