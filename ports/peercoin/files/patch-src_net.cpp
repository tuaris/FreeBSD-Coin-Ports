--- src/net.cpp.orig	2012-05-04 14:22:26 UTC
+++ src/net.cpp
@@ -49,7 +49,7 @@ uint64 nLocalServices = (fClient ? 0 : N
 CAddress addrLocalHost(CService("0.0.0.0", 0), nLocalServices);
 static CNode* pnodeLocalHost = NULL;
 uint64 nLocalHostNonce = 0;
-array<int, THREAD_MAX> vnThreadsRunning;
+boost::array<int, THREAD_MAX> vnThreadsRunning;
 static SOCKET hListenSocket = INVALID_SOCKET;
 CAddrMan addrman;
 
