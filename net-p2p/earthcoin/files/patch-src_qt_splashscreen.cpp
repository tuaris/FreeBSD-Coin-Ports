--- src/qt/splashscreen.cpp.orig	2021-05-15 06:47:32 UTC
+++ src/qt/splashscreen.cpp
@@ -18,6 +18,8 @@
 #include <ui_interface.h>
 #include <version.h>
 
+#include <boost/bind/bind.hpp>
+
 #include <QApplication>
 #include <QCloseEvent>
 #include <QDesktopWidget>
@@ -178,7 +180,7 @@ static void ShowProgress(SplashScreen *splash, const s
 #ifdef ENABLE_WALLET
 void SplashScreen::ConnectWallet(std::unique_ptr<interfaces::Wallet> wallet)
 {
-    m_connected_wallet_handlers.emplace_back(wallet->handleShowProgress(boost::bind(ShowProgress, this, _1, _2, false)));
+    m_connected_wallet_handlers.emplace_back(wallet->handleShowProgress(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2, false)));
     m_connected_wallets.emplace_back(std::move(wallet));
 }
 #endif
@@ -186,8 +188,8 @@ void SplashScreen::ConnectWallet(std::unique_ptr<inter
 void SplashScreen::subscribeToCoreSignals()
 {
     // Connect signals to client
-    m_handler_init_message = m_node.handleInitMessage(boost::bind(InitMessage, this, _1));
-    m_handler_show_progress = m_node.handleShowProgress(boost::bind(ShowProgress, this, _1, _2, _3));
+    m_handler_init_message = m_node.handleInitMessage(boost::bind(InitMessage, this, boost::placeholders::_1));
+    m_handler_show_progress = m_node.handleShowProgress(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3));
 #ifdef ENABLE_WALLET
     m_handler_load_wallet = m_node.handleLoadWallet([this](std::unique_ptr<interfaces::Wallet> wallet) { ConnectWallet(std::move(wallet)); });
 #endif
