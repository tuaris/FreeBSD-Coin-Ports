--- src/net.cpp.orig	2014-04-28 21:18:05.000000000 -0400
+++ src/net.cpp	2014-11-30 12:51:44.000000000 -0500
@@ -57,7 +57,7 @@
 static CNode* pnodeLocalHost = NULL;
 CAddress addrSeenByPeer(CService("0.0.0.0", 0), nLocalServices);
 uint64 nLocalHostNonce = 0;
-array<int, THREAD_MAX> vnThreadsRunning;
+boost::array<int, THREAD_MAX> vnThreadsRunning;
 static std::vector<SOCKET> vhListenSocket;
 CAddrMan addrman;
 
