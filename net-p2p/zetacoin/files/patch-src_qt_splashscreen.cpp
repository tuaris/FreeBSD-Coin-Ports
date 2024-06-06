--- src/qt/splashscreen.cpp.orig	2018-07-31 20:08:28 UTC
+++ src/qt/splashscreen.cpp
@@ -16,6 +16,8 @@
 #include "ui_interface.h"
 #include "version.h"
 
+#include <boost/bind/bind.hpp>
+
 #ifdef ENABLE_WALLET
 #include "wallet/wallet.h"
 #endif
@@ -167,28 +169,28 @@ static void ShowProgress(SplashScreen *splash, const s
 #ifdef ENABLE_WALLET
 static void ConnectWallet(SplashScreen *splash, CWallet* wallet)
 {
-    wallet->ShowProgress.connect(boost::bind(ShowProgress, splash, _1, _2));
+    wallet->ShowProgress.connect(boost::bind(ShowProgress, splash, boost::placeholders::_1, boost::placeholders::_2));
 }
 #endif
 
 void SplashScreen::subscribeToCoreSignals()
 {
     // Connect signals to client
-    uiInterface.InitMessage.connect(boost::bind(InitMessage, this, _1));
-    uiInterface.ShowProgress.connect(boost::bind(ShowProgress, this, _1, _2));
+    uiInterface.InitMessage.connect(boost::bind(InitMessage, this, boost::placeholders::_1));
+    uiInterface.ShowProgress.connect(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2));
 #ifdef ENABLE_WALLET
-    uiInterface.LoadWallet.connect(boost::bind(ConnectWallet, this, _1));
+    uiInterface.LoadWallet.connect(boost::bind(ConnectWallet, this, boost::placeholders::_1));
 #endif
 }
 
 void SplashScreen::unsubscribeFromCoreSignals()
 {
     // Disconnect signals from client
-    uiInterface.InitMessage.disconnect(boost::bind(InitMessage, this, _1));
-    uiInterface.ShowProgress.disconnect(boost::bind(ShowProgress, this, _1, _2));
+    uiInterface.InitMessage.disconnect(boost::bind(InitMessage, this, boost::placeholders::_1));
+    uiInterface.ShowProgress.disconnect(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2));
 #ifdef ENABLE_WALLET
     if(pwalletMain)
-        pwalletMain->ShowProgress.disconnect(boost::bind(ShowProgress, this, _1, _2));
+        pwalletMain->ShowProgress.disconnect(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2));
 #endif
 }
 
