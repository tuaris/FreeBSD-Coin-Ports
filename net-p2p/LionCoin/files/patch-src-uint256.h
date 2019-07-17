--- src/uint256.h.orig	2014-11-23 09:05:57.000000000 -0500
+++ src/uint256.h	2014-11-30 13:28:35.000000000 -0500
@@ -342,12 +342,12 @@
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
 
