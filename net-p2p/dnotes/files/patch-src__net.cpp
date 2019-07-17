--- src/net.cpp.orig	2014-08-31 15:33:55 UTC
+++ src/net.cpp
@@ -58,7 +58,7 @@ static bool vfReachable[NET_MAX] = {};
 static bool vfLimited[NET_MAX] = {};
 static CNode* pnodeLocalHost = NULL;
 uint64 nLocalHostNonce = 0;
-array<int, THREAD_MAX> vnThreadsRunning;
+boost::array<int, THREAD_MAX> vnThreadsRunning;
 static std::vector<SOCKET> vhListenSocket;
 CAddrMan addrman;
 
