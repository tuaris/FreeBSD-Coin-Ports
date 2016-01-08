--- src/net.cpp.orig	2014-08-30 09:49:14 UTC
+++ src/net.cpp
@@ -18,10 +18,10 @@
 #endif
 
 #ifdef USE_UPNP
-#include <miniwget.h>
-#include <miniupnpc.h>
-#include <upnpcommands.h>
-#include <upnperrors.h>
+#include <miniupnpc/miniupnpc.h>
+#include <miniupnpc/miniwget.h>
+#include <miniupnpc/upnpcommands.h>
+#include <miniupnpc/upnperrors.h>
 #endif
 
 using namespace std;
@@ -58,7 +58,7 @@ static bool vfReachable[NET_MAX] = {};
 static bool vfLimited[NET_MAX] = {};
 static CNode* pnodeLocalHost = NULL;
 uint64 nLocalHostNonce = 0;
-array<int, THREAD_MAX> vnThreadsRunning;
+boost::array<int, THREAD_MAX> vnThreadsRunning;
 static std::vector<SOCKET> vhListenSocket;
 CAddrMan addrman;
 
@@ -1032,10 +1032,14 @@ void ThreadMapPort2(void* parg)
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
