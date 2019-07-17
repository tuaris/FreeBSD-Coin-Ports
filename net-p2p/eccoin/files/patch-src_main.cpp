--- src/main.cpp.orig	2014-12-22 23:06:47 UTC
+++ src/main.cpp
@@ -932,8 +932,8 @@ uint256 WantedByOrphan(const CBlock* pbl
 
 int generateMTRandom(unsigned int s, int range)
 {
-	random::mt19937 gen(s);
-    random::uniform_int_distribution<> dist(0, range);
+	boost::random::mt19937 gen(s);
+    boost::random::uniform_int_distribution<> dist(0, range);
     return dist(gen);
 }
 /*
