--- src/checkpoints.cpp.orig	2014-11-01 20:10:01 UTC
+++ src/checkpoints.cpp
@@ -54,12 +54,13 @@ namespace Checkpoints
         	(  50000, uint256("0x1abbfb14e47ae45f39df10403f80d5425857b4be1645eabb899ea0d054ec5c82"))
             (  60000, uint256("0x57b9dc1701d4879fc15c631bfcb982c73a4e1f1d6e619dfcd2b7760635ea55a1"))
             (  64430, uint256("0x564d94d38b108bc6c9e7b59fa33b547f094da01a099b87af6601e8d3e30cb2c3"))
+            (  70000, uint256("0x48c1ea33b1b3fcdf599b8fb7438ce73263ac7d4c6195812ecc5678b24da78696"))
         ;
     
     static const CCheckpointData data = {
         &mapCheckpoints,
-        1397069764, // * UNIX timestamp of last checkpoint block
-        9068,    // * total number of transactions between genesis and last checkpoint
+        1420113353, // * UNIX timestamp of last checkpoint block
+        76396,    // * total number of transactions between genesis and last checkpoint
                     //   (the tx=... number in the SetBestChain debug.log lines)
         8000.0     // * estimated number of transactions per day after checkpoint
     };
