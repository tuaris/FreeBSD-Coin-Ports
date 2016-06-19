--- src/net.cpp.orig	2016-05-17 20:09:59 UTC
+++ src/net.cpp
@@ -972,10 +972,14 @@ void ThreadMapPort()
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
