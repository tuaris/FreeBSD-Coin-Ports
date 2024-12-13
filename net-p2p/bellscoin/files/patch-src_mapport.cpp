--- src/mapport.cpp.orig	2024-09-13 11:52:56 UTC
+++ src/mapport.cpp
@@ -164,7 +164,11 @@ static bool ProcessUpnp()
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
