--- src/net.cpp.orig	2024-12-01 01:55:09 UTC
+++ src/net.cpp
@@ -1488,7 +1488,11 @@ void ThreadMapPort()
     struct IGDdatas data;
     int r;
 
+#if MINIUPNPC_API_VERSION >= 18
+    r = UPNP_GetValidIGD(devlist, &urls, &data, lanaddr, sizeof(lanaddr), NULL, 0);
+#else
     r = UPNP_GetValidIGD(devlist, &urls, &data, lanaddr, sizeof(lanaddr));
+#endif
     if (r == 1)
     {
         if (fDiscover) {
