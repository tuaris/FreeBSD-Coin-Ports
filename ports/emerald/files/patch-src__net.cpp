--- src/net.cpp.orig	2015-11-30 23:06:15 UTC
+++ src/net.cpp
@@ -58,7 +58,7 @@ static bool vfReachable[NET_MAX] = {};
 static bool vfLimited[NET_MAX] = {};
 static CNode* pnodeLocalHost = NULL;
 uint64 nLocalHostNonce = 0;
-array<int, THREAD_MAX> vnThreadsRunning;
+boost::array<int, THREAD_MAX> vnThreadsRunning;
 static std::vector<SOCKET> vhListenSocket;
 CAddrMan addrman;
 
@@ -1124,10 +1124,14 @@ void ThreadMapPort2(void* parg)
 #ifndef UPNPDISCOVER_SUCCESS
     /* miniupnpc 1.5 */
     devlist = upnpDiscover(2000, multicastif, minissdpdpath, 0);
-#else
+#elif MINIUPNPC_API_VERSION < 14
     /* miniupnpc 1.6 */
     int error = 0;
     devlist = upnpDiscover(2000, multicastif, minissdpdpath, 0, 0, &error);
+#else
+    /* miniupnpc 1.9.20150730 */
+    int error = 0;
+    devlist = upnpDiscover(2000, multicastif, minissdpdpath, 0, 0, 2, &error);    
 #endif
 
     struct UPNPUrls urls;
