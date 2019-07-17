--- src/net.cpp.orig	2015-04-18 01:21:15 UTC
+++ src/net.cpp
@@ -57,7 +57,7 @@ static bool vfLimited[NET_MAX] = {};
 static CNode* pnodeLocalHost = NULL;
 CAddress addrSeenByPeer(CService("0.0.0.0", 0), nLocalServices);
 uint64_t nLocalHostNonce = 0;
-array<int, THREAD_MAX> vnThreadsRunning;
+boost::array<int, THREAD_MAX> vnThreadsRunning;
 static std::vector<SOCKET> vhListenSocket;
 CAddrMan addrman;
 
