--- src/util.cpp.orig	2018-07-31 20:08:28 UTC
+++ src/util.cpp
@@ -522,7 +522,7 @@ boost::filesystem::path GetConfigFile()
 boost::filesystem::path GetConfigFile()
 {
     boost::filesystem::path pathConfigFile(GetArg("-conf", BITCOIN_CONF_FILENAME));
-    if (!pathConfigFile.is_complete())
+    if (!pathConfigFile.is_absolute())
         pathConfigFile = GetDataDir(false) / pathConfigFile;
 
     return pathConfigFile;
@@ -556,7 +556,7 @@ boost::filesystem::path GetPidFile()
 boost::filesystem::path GetPidFile()
 {
     boost::filesystem::path pathPidFile(GetArg("-pid", BITCOIN_PID_FILENAME));
-    if (!pathPidFile.is_complete()) pathPidFile = GetDataDir() / pathPidFile;
+    if (!pathPidFile.is_absolute()) pathPidFile = GetDataDir() / pathPidFile;
     return pathPidFile;
 }
 
