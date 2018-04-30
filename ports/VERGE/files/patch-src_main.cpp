--- src/main.cpp.orig	2018-04-30 02:12:58 UTC
+++ src/main.cpp
@@ -1977,7 +1977,7 @@ bool CBlock::SetBestChain(CTxDB& txdb, C
         }
 
         if (!vpindexSecondary.empty())
-            printf("Postponing %"PRIszu" reconnects\n", vpindexSecondary.size());
+            printf("Postponing %" PRIszu " reconnects\n", vpindexSecondary.size());
 
         // Switch to new best branch
         if (!Reorganize(txdb, pindexIntermediate))
