--- src/main.cpp.orig	2014-05-02 02:16:19 UTC
+++ src/main.cpp
@@ -934,8 +934,8 @@ uint256 WantedByOrphan(const CBlock* pbl
 
 int generateMTRandom(unsigned int s, int range)
 {
-	random::mt19937 gen(s);
-    random::uniform_int_distribution<> dist(1, range);
+	boost::random::mt19937 gen(s);
+    boost::random::uniform_int_distribution<> dist(1, range);
     return dist(gen);
 }
 
