--- src/wallet/wallet.cpp.orig	2018-07-31 20:08:28 UTC
+++ src/wallet/wallet.cpp
@@ -27,6 +27,7 @@
 #include "utilmoneystr.h"
 
 #include <assert.h>
+#include <random>
 
 #include <boost/algorithm/string/replace.hpp>
 #include <boost/filesystem.hpp>
@@ -420,8 +421,10 @@ bool CWallet::Verify()
     uiInterface.InitMessage(_("Verifying wallet..."));
 
     // Wallet file must be a plain filename without a directory
-    if (walletFile != boost::filesystem::basename(walletFile) + boost::filesystem::extension(walletFile))
+	boost::filesystem::path walletPath(walletFile);
+	if (walletFile != walletPath.stem().string() + walletPath.extension().string()) {
         return InitError(strprintf(_("Wallet %s resides outside data directory %s"), walletFile, GetDataDir().string()));
+	}
 
     if (!bitdb.Open(GetDataDir()))
     {
@@ -1936,6 +1939,8 @@ bool CWallet::SelectCoinsMinConf(const CAmount& nTarge
 {
     setCoinsRet.clear();
     nValueRet = 0;
+	random_device rd;
+    mt19937 insecure_rand(rd());
 
     // List of values less than target
     pair<CAmount, pair<const CWalletTx*,unsigned int> > coinLowestLarger;
@@ -1944,7 +1949,7 @@ bool CWallet::SelectCoinsMinConf(const CAmount& nTarge
     vector<pair<CAmount, pair<const CWalletTx*,unsigned int> > > vValue;
     CAmount nTotalLower = 0;
 
-    random_shuffle(vCoins.begin(), vCoins.end(), GetRandInt);
+    shuffle(vCoins.begin(), vCoins.end(), insecure_rand);
 
     BOOST_FOREACH(const COutput &output, vCoins)
     {
@@ -3541,7 +3546,11 @@ bool CWallet::BackupWallet(const std::string& strDest)
                     pathDest /= strWalletFile;
 
                 try {
-#if BOOST_VERSION >= 104000
+#if BOOST_VERSION >= 107400
+                    // Boost 1.74.0 and up implements std++17 like "copy_options", and this
+                    // is the only remaining enum after 1.85.0
+                    boost::filesystem::copy_file(pathSrc, pathDest, boost::filesystem::copy_options::overwrite_existing);
+#elif BOOST_VERSION >= 104000
                     boost::filesystem::copy_file(pathSrc, pathDest, boost::filesystem::copy_option::overwrite_if_exists);
 #else
                     boost::filesystem::copy_file(pathSrc, pathDest);
