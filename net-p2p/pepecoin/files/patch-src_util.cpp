--- src/util.cpp.orig	2024-05-12 22:05:21 UTC
+++ src/util.cpp
@@ -590,7 +590,7 @@ const boost::filesystem::path &GetBackupDir()
 boost::filesystem::path GetConfigFile(const std::string& confPath)
 {
     boost::filesystem::path pathConfigFile(confPath);
-    if (!pathConfigFile.is_complete())
+    if (!pathConfigFile.is_absolute())
         pathConfigFile = GetDataDir(false) / pathConfigFile;
 
     return pathConfigFile;
@@ -626,7 +626,7 @@ void ReadConfigFile(const std::string& confPath)
 boost::filesystem::path GetPidFile()
 {
     boost::filesystem::path pathPidFile(GetArg("-pid", BITCOIN_PID_FILENAME));
-    if (!pathPidFile.is_complete()) pathPidFile = GetDataDir() / pathPidFile;
+    if (!pathPidFile.is_absolute()) pathPidFile = GetDataDir() / pathPidFile;
     return pathPidFile;
 }
 
