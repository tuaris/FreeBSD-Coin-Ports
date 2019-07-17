--- src/smessage.cpp.orig	2018-04-07 02:55:54 UTC
+++ src/smessage.cpp
@@ -194,7 +194,7 @@ void SecMsgBucket::hashBucket()
     hash = XXH32_digest(state);
     
     if (fDebug)
-        printf("Hashed %"PRIszu" messages, hash %u\n", setTokens.size(), hash);
+        printf("Hashed %" PRIszu " messages, hash %u\n", setTokens.size(), hash);
 };
 
 
@@ -612,7 +612,7 @@ void ThreadSecureMsg(void* parg)
         int64_t now = GetTime();
         
         if (fDebug)
-            printf("SecureMsgThread %"PRId64" \n", now);
+            printf("SecureMsgThread %" PRId64 " \n", now);
         
         int64_t cutoffTime = now - SMSG_RETENTION;
         
@@ -628,7 +628,7 @@ void ThreadSecureMsg(void* parg)
                 if (it->first < cutoffTime)
                 {
                     if (fDebug)
-                        printf("Removing bucket %"PRId64" \n", it->first);
+                        printf("Removing bucket %" PRId64 " \n", it->first);
                     std::string fileName = boost::lexical_cast<std::string>(it->first) + "_01.dat";
                     fs::path fullPath = GetDataDir() / "smsgStore" / fileName;
                     if (fs::exists(fullPath))
@@ -669,7 +669,7 @@ void ThreadSecureMsg(void* parg)
                             int64_t     ignoreUntil = GetTime() + SMSG_TIME_IGNORE;
                             
                             if (fDebug)
-                                printf("Lock on bucket %"PRId64" for peer %u timed out.\n", it->first, nPeerId);
+                                printf("Lock on bucket %" PRId64 " for peer %u timed out.\n", it->first, nPeerId);
                             // -- look through the nodes for the peer that locked this bucket
                             LOCK(cs_vNodes);
                             BOOST_FOREACH(CNode* pnode, vNodes)
@@ -685,7 +685,7 @@ void ThreadSecureMsg(void* parg)
                                 pnode->PushMessage("smsgIgnore", vchData);
                                 
                                 if (fDebug)
-                                    printf("This node will ignore peer %u until %"PRId64".\n", nPeerId, ignoreUntil);
+                                    printf("This node will ignore peer %u until %" PRId64 ".\n", nPeerId, ignoreUntil);
                                 break;
                             };
                             it->second.nLockPeerId = 0;
@@ -813,7 +813,7 @@ std::string fsReadable(uint64_t nBytes)
     if (nBytes >= 1024)
         snprintf(buffer, sizeof(buffer), "%.2f KB", nBytes/1024.0);
     else
-        snprintf(buffer, sizeof(buffer), "%"PRIu64" bytes", nBytes);
+        snprintf(buffer, sizeof(buffer), "%" PRIu64 " bytes", nBytes);
     return std::string(buffer);
 };
 
@@ -949,10 +949,10 @@ int SecureMsgBuildBucketSet()
         nMessages += tokenSet.size();
         
         if (fDebug)
-            printf("Bucket %"PRId64" contains %"PRIszu" messages.\n", fileTime, tokenSet.size());
+            printf("Bucket %" PRId64 " contains %" PRIszu " messages.\n", fileTime, tokenSet.size());
     };
     
-    printf("Processed %u files, loaded %"PRIszu" buckets containing %u messages.\n", nFiles, smsgBuckets.size(), nMessages);
+    printf("Processed %u files, loaded %" PRIszu " buckets containing %u messages.\n", nFiles, smsgBuckets.size(), nMessages);
     
     return 0;
 };
@@ -1066,7 +1066,7 @@ int SecureMsgReadIni()
         };
     };
     
-    printf("Loaded %"PRIszu" addresses.\n", smsgAddresses.size());
+    printf("Loaded %" PRIszu " addresses.\n", smsgAddresses.size());
     
     fclose(fp);
     
@@ -1357,7 +1357,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
         if (now < pfrom->smsgData.ignoreUntil)
         {
             if (fDebug)
-                printf("Node is ignoring peer %u until %"PRId64".\n", pfrom->smsgData.nPeerId, pfrom->smsgData.ignoreUntil);
+                printf("Node is ignoring peer %u until %" PRId64 ".\n", pfrom->smsgData.nPeerId, pfrom->smsgData.ignoreUntil);
             return false;
         };
         
@@ -1405,7 +1405,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
             if (time < now - SMSG_RETENTION)
             {
                 if (fDebug)
-                    printf("Not interested in peer bucket %"PRId64", has expired.\n", time);
+                    printf("Not interested in peer bucket %" PRId64 ", has expired.\n", time);
                 
                 if (time < now - SMSG_RETENTION - SMSG_TIME_LEEWAY)
                     pfrom->Misbehaving(1);
@@ -1414,7 +1414,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
             if (time > now + SMSG_TIME_LEEWAY)
             {
                 if (fDebug)
-                    printf("Not interested in peer bucket %"PRId64", in the future.\n", time);
+                    printf("Not interested in peer bucket %" PRId64 ", in the future.\n", time);
                 pfrom->Misbehaving(1);
                 continue;
             };
@@ -1422,14 +1422,14 @@ bool SecureMsgReceiveData(CNode* pfrom, 
             if (ncontent < 1)
             {
                 if (fDebug)
-                    printf("Peer sent empty bucket, ignore %"PRId64" %u %u.\n", time, ncontent, hash);
+                    printf("Peer sent empty bucket, ignore %" PRId64 " %u %u.\n", time, ncontent, hash);
                 continue;
             };
             
             if (fDebug)
             {
-                printf("peer bucket %"PRId64" %u %u.\n", time, ncontent, hash);
-                printf("this bucket %"PRId64" %"PRIszu" %u.\n", time, smsgBuckets[time].setTokens.size(), smsgBuckets[time].hash);
+                printf("peer bucket %" PRId64 " %u %u.\n", time, ncontent, hash);
+                printf("this bucket %" PRId64 " %" PRIszu " %u.\n", time, smsgBuckets[time].setTokens.size(), smsgBuckets[time].hash);
             };
             
             if (smsgBuckets[time].nLockCount > 0)
@@ -1447,7 +1447,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
                     && smsgBuckets[time].hash != hash)) // if same amount in buckets check hash
             {
                 if (fDebug)
-                    printf("Requesting contents of bucket %"PRId64".\n", time);
+                    printf("Requesting contents of bucket %" PRId64 ".\n", time);
                 
                 uint32_t sz = vchDataOut.size();
                 vchDataOut.resize(sz + 8);
@@ -1471,7 +1471,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
             memcpy(&vchDataOut[0], &now, 8);
             pfrom->PushMessage("smsgMatch", vchDataOut);
             if (fDebug)
-                printf("Sending smsgMatch, %"PRId64".\n", now);
+                printf("Sending smsgMatch, %" PRId64 ".\n", now);
         };
         
     } else
@@ -1506,7 +1506,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
             if (itb == smsgBuckets.end())
             {
                 if (fDebug)
-                    printf("Don't have bucket %"PRId64".\n", time);
+                    printf("Don't have bucket %" PRId64 ".\n", time);
                 continue;
             };
             
@@ -1515,7 +1515,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
             try {
                 vchDataOut.resize(8 + 16 * tokenSet.size());
             } catch (std::exception& e) {
-                printf("vchDataOut.resize %"PRIszu" threw: %s.\n", 8 + 16 * tokenSet.size(), e.what());
+                printf("vchDataOut.resize %" PRIszu " threw: %s.\n", 8 + 16 * tokenSet.size(), e.what());
                 continue;
             };
             memcpy(&vchDataOut[0], &time, 8);
@@ -1552,13 +1552,13 @@ bool SecureMsgReceiveData(CNode* pfrom, 
         if (time < now - SMSG_RETENTION)
         {
             if (fDebug)
-                printf("Not interested in peer bucket %"PRId64", has expired.\n", time);
+                printf("Not interested in peer bucket %" PRId64 ", has expired.\n", time);
             return false;
         };
         if (time > now + SMSG_TIME_LEEWAY)
         {
             if (fDebug)
-                printf("Not interested in peer bucket %"PRId64", in the future.\n", time);
+                printf("Not interested in peer bucket %" PRId64 ", in the future.\n", time);
             pfrom->Misbehaving(1);
             return false;
         };
@@ -1566,12 +1566,12 @@ bool SecureMsgReceiveData(CNode* pfrom, 
         if (smsgBuckets[time].nLockCount > 0)
         {
             if (fDebug)
-                printf("Bucket %"PRId64" lock count %u, waiting for message data from peer %u.\n", time, smsgBuckets[time].nLockCount, smsgBuckets[time].nLockPeerId);
+                printf("Bucket %" PRId64 " lock count %u, waiting for message data from peer %u.\n", time, smsgBuckets[time].nLockCount, smsgBuckets[time].nLockPeerId);
             return false;
         }; 
         
         if (fDebug)
-            printf("Sifting through bucket %"PRId64".\n", time);
+            printf("Sifting through bucket %" PRId64 ".\n", time);
         
         std::vector<unsigned char> vchDataOut;
         vchDataOut.resize(8);
@@ -1608,8 +1608,8 @@ bool SecureMsgReceiveData(CNode* pfrom, 
         {
             if (fDebug)
             {
-                printf("Asking peer for  %"PRIszu" messages.\n", (vchDataOut.size() - 8) / 16);
-                printf("Locking bucket %"PRIszu" for peer %u.\n", time, pfrom->smsgData.nPeerId);
+                printf("Asking peer for  %" PRIszu " messages.\n", (vchDataOut.size() - 8) / 16);
+                printf("Locking bucket %" PRIszu " for peer %u.\n", time, pfrom->smsgData.nPeerId);
             };
             smsgBuckets[time].nLockCount   = 3; // lock this bucket for at most 3 * SMSG_THREAD_DELAY seconds, unset when peer sends smsgMsg
             smsgBuckets[time].nLockPeerId  = pfrom->smsgData.nPeerId;
@@ -1640,7 +1640,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
         if (itb == smsgBuckets.end())
         {
             if (fDebug)
-                printf("Don't have bucket %"PRId64".\n", time);
+                printf("Don't have bucket %" PRId64 ".\n", time);
             return false;
         };
         
@@ -1657,7 +1657,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
             if (it == tokenSet.end())
             {
                 if (fDebug)
-                    printf("Don't have wanted message %"PRId64".\n", token.timestamp);
+                    printf("Don't have wanted message %" PRId64 ".\n", token.timestamp);
             } else
             {
                 //printf("Have message at %"PRId64".\n", it->offset); // DEBUG
@@ -1671,14 +1671,14 @@ bool SecureMsgReceiveData(CNode* pfrom, 
                     vchBunch.insert(vchBunch.end(), vchOne.begin(), vchOne.end()); // append
                 } else
                 {
-                    printf("SecureMsgRetrieve failed %"PRId64".\n", token.timestamp);
+                    printf("SecureMsgRetrieve failed %" PRId64 ".\n", token.timestamp);
                 };
                 
                 if (nBunch >= 500
                     || vchBunch.size() >= 96000)
                 {
                     if (fDebug)
-                        printf("Break bunch %u, %"PRIszu".\n", nBunch, vchBunch.size());
+                        printf("Break bunch %u, %" PRIszu ".\n", nBunch, vchBunch.size());
                     break; // end here, peer will send more want messages if needed.
                 };
             };
@@ -1688,7 +1688,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
         if (nBunch > 0)
         {
             if (fDebug)
-                printf("Sending block of %u messages for bucket %"PRId64".\n", nBunch, time);
+                printf("Sending block of %u messages for bucket %" PRId64 ".\n", nBunch, time);
             
             memcpy(&vchBunch[0], &nBunch, 4);
             memcpy(&vchBunch[4], &time, 8);
@@ -1701,7 +1701,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
         vRecv >> vchData;
         
         if (fDebug)
-            printf("smsgMsg vchData.size() %"PRIszu".\n", vchData.size());
+            printf("smsgMsg vchData.size() %" PRIszu ".\n", vchData.size());
         
         SecureMsgReceive(pfrom, vchData);
     } else
@@ -1713,7 +1713,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
         
         if (vchData.size() < 8)
         {
-            printf("smsgMatch, not enough data %"PRIszu".\n", vchData.size());
+            printf("smsgMatch, not enough data %" PRIszu ".\n", vchData.size());
             pfrom->Misbehaving(1);
             return false;
         };
@@ -1724,7 +1724,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
         int64_t now = GetTime();
         if (time > now + SMSG_TIME_LEEWAY)
         {
-            printf("Warning: Peer buckets matched in the future: %"PRId64".\nEither this node or the peer node has the incorrect time set.\n", time);
+            printf("Warning: Peer buckets matched in the future: %" PRId64 ".\nEither this node or the peer node has the incorrect time set.\n", time);
             if (fDebug)
                 printf("Peer match time set to now.\n");
             time = now;
@@ -1733,7 +1733,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
         pfrom->smsgData.lastMatched = time;
         
         if (fDebug)
-            printf("Peer buckets matched at %"PRId64".\n", time);
+            printf("Peer buckets matched at %" PRId64 ".\n", time);
         
     } else
     if (strCommand == "smsgPing")
@@ -1767,7 +1767,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
         
         if (vchData.size() < 8)
         {
-            printf("smsgIgnore, not enough data %"PRIszu".\n", vchData.size());
+            printf("smsgIgnore, not enough data %" PRIszu ".\n", vchData.size());
             pfrom->Misbehaving(1);
             return false;
         };
@@ -1778,7 +1778,7 @@ bool SecureMsgReceiveData(CNode* pfrom, 
         pfrom->smsgData.ignoreUntil = time;
         
         if (fDebug)
-            printf("Peer %u is ignoring this node until %"PRId64", ignore peer too.\n", pfrom->smsgData.nPeerId, time);
+            printf("Peer %u is ignoring this node until %" PRId64 ", ignore peer too.\n", pfrom->smsgData.nPeerId, time);
     } else
     {
         // Unknown message
@@ -1827,7 +1827,7 @@ bool SecureMsgSendData(CNode* pto, bool 
         
         if (fDebug)
             printf("SecureMsgSendData(): nWakeCounter expired, sending bucket inventory to %s.\n"
-            "Now %"PRId64" next wake counter %u\n", pto->addrName.c_str(), now, pto->smsgData.nWakeCounter);
+            "Now %" PRId64 " next wake counter %u\n", pto->addrName.c_str(), now, pto->smsgData.nWakeCounter);
     };
     pto->smsgData.nWakeCounter--;
     
@@ -1862,7 +1862,7 @@ bool SecureMsgSendData(CNode* pto, bool 
                 try {
                     vchData.resize(vchData.size() + 16);
                 } catch (std::exception& e) {
-                    printf("vchData.resize %"PRIszu" threw: %s.\n", vchData.size() + 16, e.what());
+                    printf("vchData.resize %" PRIszu " threw: %s.\n", vchData.size() + 16, e.what());
                     continue;
                 };
                 memcpy(p, &it->first, 8);
@@ -2137,7 +2137,7 @@ bool ScanChainForPublicKeys(CBlockIndex*
     
     printf("Scanned %u blocks, %u transactions, %u inputs\n", nBlocks, nTransactions, nInputs);
     printf("Found %u public keys, %u duplicates.\n", nPubkeys, nDuplicates);
-    printf("Took %"PRId64" ms\n", GetTimeMillis() - nStart);
+    printf("Took %" PRId64 " ms\n", GetTimeMillis() - nStart);
     
     return true;
 };
@@ -2316,7 +2316,7 @@ bool SecureMsgScanBuckets()
     };
     
     printf("Processed %u files, scanned %u messages, received %u messages.\n", nFiles, nMessages, nFoundMessages);
-    printf("Took %"PRId64" ms\n", GetTimeMillis() - mStart);
+    printf("Took %" PRId64 " ms\n", GetTimeMillis() - mStart);
     
     return true;
 }
@@ -2763,7 +2763,7 @@ int SecureMsgAddAddress(std::string& add
 int SecureMsgRetrieve(SecMsgToken &token, std::vector<unsigned char>& vchData)
 {
     if (fDebug)
-        printf("SecureMsgRetrieve() %"PRId64".\n", token.timestamp);
+        printf("SecureMsgRetrieve() %" PRId64 ".\n", token.timestamp);
     
     // -- has cs_smsg lock from SecureMsgReceiveData
     
@@ -2865,7 +2865,7 @@ int SecureMsgReceive(CNode* pfrom, std::
     
     if (nBunch == 0 || nBunch > 500)
     {
-        printf("Error: Invalid no. messages received in bunch %u, for bucket %"PRId64".\n", nBunch, bktTime);
+        printf("Error: Invalid no. messages received in bunch %u, for bucket %" PRId64 ".\n", nBunch, bktTime);
         pfrom->Misbehaving(1);
         
         // -- release lock on bucket if it exists
@@ -2921,7 +2921,7 @@ int SecureMsgReceive(CNode* pfrom, std::
     if (itb == smsgBuckets.end())
     {
         if (fDebug)
-            printf("Don't have bucket %"PRId64".\n", bktTime);
+            printf("Don't have bucket %" PRId64 ".\n", bktTime);
         return 1;
     };
     
@@ -3054,9 +3054,9 @@ int SecureMsgStore(unsigned char *pHeade
             if (fDebug)
             {
                 printf("nPayload: %u\n", nPayload);
-                printf("bucket: %"PRId64"\n", bucket);
+                printf("bucket: %" PRId64 "\n", bucket);
                 
-                printf("message ts: %"PRId64, token.timestamp);
+                printf("message ts: %" PRId64, token.timestamp);
                 std::vector<unsigned char> vchShow;
                 vchShow.resize(8);
                 memcpy(&vchShow[0], token.sample, 8);
@@ -3117,7 +3117,7 @@ int SecureMsgStore(unsigned char *pHeade
     };
     
     //if (fDebug)
-    printf("SecureMsg added to bucket %"PRId64".\n", bucket);
+    printf("SecureMsg added to bucket %" PRId64 ".\n", bucket);
     return 0;
 };
 
@@ -3292,7 +3292,7 @@ int SecureMsgSetHash(unsigned char *pHea
     if (!found)
     {
         if (fDebug)
-            printf("SecureMsgSetHash() failed, took %"PRId64" ms, nonse %u\n", GetTimeMillis() - nStart, nonse);
+            printf("SecureMsgSetHash() failed, took %" PRId64 " ms, nonse %u\n", GetTimeMillis() - nStart, nonse);
         return 1;
     };
     
@@ -3300,7 +3300,7 @@ int SecureMsgSetHash(unsigned char *pHea
     //memcpy(psmsg->hash, &vchHash[0], 4);
     
     if (fDebug)
-        printf("SecureMsgSetHash() took %"PRId64" ms, nonse %u\n", GetTimeMillis() - nStart, nonse);
+        printf("SecureMsgSetHash() took %" PRId64 " ms, nonse %u\n", GetTimeMillis() - nStart, nonse);
     
     return 0;
 };
@@ -3336,7 +3336,7 @@ int SecureMsgEncrypt(SecureMessage& smsg
     
     if (message.size() > SMSG_MAX_MSG_BYTES)
     {
-        printf("Message is too long, %"PRIszu".\n", message.size());
+        printf("Message is too long, %" PRIszu ".\n", message.size());
         return 2;
     };
     
@@ -3603,7 +3603,7 @@ int SecureMsgSend(std::string& addressFr
         std::ostringstream oss;
         oss << message.size() << " > " << SMSG_MAX_MSG_BYTES;
         sError = "Message is too long, " + oss.str();
-        printf("Message is too long, %"PRIszu".\n", message.size());
+        printf("Message is too long, %" PRIszu ".\n", message.size());
         return 1;
     };
     
