--- src/net.cpp.orig	2014-08-27 12:56:24.000000000 -0400
+++ src/net.cpp	2014-10-26 01:26:09.000000000 -0400
@@ -57,7 +57,7 @@
 static CNode* pnodeLocalHost = NULL;
 CAddress addrSeenByPeer(CService("0.0.0.0", 0), nLocalServices);
 uint64 nLocalHostNonce = 0;
-array<int, THREAD_MAX> vnThreadsRunning;
+boost::array<int, THREAD_MAX> vnThreadsRunning;
 static std::vector<SOCKET> vhListenSocket;
 CAddrMan addrman;
 
