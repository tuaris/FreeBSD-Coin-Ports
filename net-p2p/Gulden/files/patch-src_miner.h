--- src/miner.h.orig	2018-02-03 15:45:38 UTC
+++ src/miner.h
@@ -90,7 +90,7 @@ struct modifiedentry_iter {
 };
 
 struct CompareModifiedEntry {
-    bool operator()(const CTxMemPoolModifiedEntry& a, const CTxMemPoolModifiedEntry& b)
+    bool operator()(const CTxMemPoolModifiedEntry& a, const CTxMemPoolModifiedEntry& b) const
     {
         double f1 = (double)a.nModFeesWithAncestors * b.nSizeWithAncestors;
         double f2 = (double)b.nModFeesWithAncestors * a.nSizeWithAncestors;
