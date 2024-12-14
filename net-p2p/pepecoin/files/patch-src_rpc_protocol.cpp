--- src/rpc/protocol.cpp.orig	2024-05-12 22:05:21 UTC
+++ src/rpc/protocol.cpp
@@ -72,7 +72,7 @@ static const std::string COOKIEAUTH_FILE = ".cookie";
 boost::filesystem::path GetAuthCookieFile()
 {
     boost::filesystem::path path(GetArg("-rpccookiefile", COOKIEAUTH_FILE));
-    if (!path.is_complete()) path = GetDataDir() / path;
+    if (!path.is_absolute()) path = GetDataDir() / path;
     return path;
 }
 
