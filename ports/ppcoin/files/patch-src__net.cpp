--- src/net.cpp.orig	2014-07-30 19:48:08 UTC
+++ src/net.cpp
@@ -51,7 +51,7 @@ CAddress addrLocalHost(CService("0.0.0.0
 CAddress addrSeenByPeer(CService("0.0.0.0", 0), nLocalServices);
 static CNode* pnodeLocalHost = NULL;
 uint64 nLocalHostNonce = 0;
-array<int, THREAD_MAX> vnThreadsRunning;
+boost::array<int, THREAD_MAX> vnThreadsRunning;
 static SOCKET hListenSocket = INVALID_SOCKET;
 CAddrMan addrman;
 
