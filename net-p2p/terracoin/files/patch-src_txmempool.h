--- src/txmempool.h.orig	2018-01-11 20:38:04 UTC
+++ src/txmempool.h
@@ -204,7 +204,7 @@ struct mempoolentry_txid
 class CompareTxMemPoolEntryByDescendantScore
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         bool fUseADescendants = UseDescendantScore(a);
         bool fUseBDescendants = UseDescendantScore(b);
@@ -226,7 +226,7 @@ public:
     }
 
     // Calculate which score to use for an entry (avoiding division).
-    bool UseDescendantScore(const CTxMemPoolEntry &a)
+    bool UseDescendantScore(const CTxMemPoolEntry &a) const
     {
         double f1 = (double)a.GetModifiedFee() * a.GetSizeWithDescendants();
         double f2 = (double)a.GetModFeesWithDescendants() * a.GetTxSize();
@@ -241,7 +241,7 @@ public:
 class CompareTxMemPoolEntryByScore
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         double f1 = (double)a.GetModifiedFee() * b.GetTxSize();
         double f2 = (double)b.GetModifiedFee() * a.GetTxSize();
@@ -255,7 +255,7 @@ public:
 class CompareTxMemPoolEntryByEntryTime
 {
 public:
-    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b)
+    bool operator()(const CTxMemPoolEntry& a, const CTxMemPoolEntry& b) const
     {
         return a.GetTime() < b.GetTime();
     }
