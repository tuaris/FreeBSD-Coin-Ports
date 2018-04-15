--- src/txmempool.h.orig	2018-02-03 15:45:38 UTC
+++ src/txmempool.h
@@ -230,7 +230,7 @@ struct mempoolentry_txid {
  */
 class CompareTxMemPoolEntryByDescendantScore {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         bool fUseADescendants = UseDescendantScore(a);
         bool fUseBDescendants = UseDescendantScore(b);
@@ -264,7 +264,7 @@ public:
  */
 class CompareTxMemPoolEntryByScore {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         double f1 = (double)a.GetModifiedFee() * b.GetTxSize();
         double f2 = (double)b.GetModifiedFee() * a.GetTxSize();
@@ -277,7 +277,7 @@ public:
 
 class CompareTxMemPoolEntryByEntryTime {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         return a.GetTime() < b.GetTime();
     }
@@ -285,7 +285,7 @@ public:
 
 class CompareTxMemPoolEntryByAncestorFee {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         double aFees = a.GetModFeesWithAncestors();
         double aSize = a.GetSizeWithAncestors();
