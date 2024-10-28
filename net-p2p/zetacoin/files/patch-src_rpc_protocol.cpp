--- src/rpc/protocol.cpp.orig	2024-10-27 05:45:44 UTC
+++ src/rpc/protocol.cpp
@@ -71,7 +71,7 @@ boost::filesystem::path GetAuthCookieFile()
 boost::filesystem::path GetAuthCookieFile()
 {
     boost::filesystem::path path(GetArg("-rpccookiefile", COOKIEAUTH_FILE));
-    if (!path.is_complete()) path = GetDataDir() / path;
+    if (!path.is_absolute()) path = GetDataDir() / path;
     return path;
 }
 
