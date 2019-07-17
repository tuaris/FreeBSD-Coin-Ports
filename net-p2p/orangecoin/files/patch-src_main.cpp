--- src/main.cpp.orig	2014-08-10 15:27:09 UTC
+++ src/main.cpp
@@ -928,8 +928,8 @@ uint256 WantedByOrphan(const CBlock* pbl
 
 int generateMTRandom(unsigned int s, int range)
 {
-	random::mt19937 gen(s);
-    random::uniform_int_distribution<> dist(0, range);
+	boost::random::mt19937 gen(s);
+    boost::random::uniform_int_distribution<> dist(0, range);
     return dist(gen);
 }
 
