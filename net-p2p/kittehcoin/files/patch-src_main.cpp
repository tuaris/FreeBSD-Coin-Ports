--- src/main.cpp.orig	2014-04-09 16:44:01 UTC
+++ src/main.cpp
@@ -1071,8 +1071,8 @@ int GetNumBlocksOfPeers()
 
 int static generateMTRandom(unsigned int s, int range)
 {
-    random::mt19937 gen(s);
-    random::uniform_int_distribution<> dist(1, range);
+    boost::random::mt19937 gen(s);
+    boost::random::uniform_int_distribution<> dist(1, range);
     return dist(gen);
 }
 
