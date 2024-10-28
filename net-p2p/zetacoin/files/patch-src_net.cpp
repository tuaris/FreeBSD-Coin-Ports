--- src/net.cpp.orig	2018-07-31 20:08:28 UTC
+++ src/net.cpp
@@ -1389,7 +1389,11 @@ void ThreadMapPort()
     struct IGDdatas data;
     int r;
 
+#if MINIUPNPC_API_VERSION <= 17
     r = UPNP_GetValidIGD(devlist, &urls, &data, lanaddr, sizeof(lanaddr));
+#else
+    r = UPNP_GetValidIGD(devlist, &urls, &data, lanaddr, sizeof(lanaddr), nullptr, 0);
+#endif
     if (r == 1)
     {
         if (fDiscover) {
