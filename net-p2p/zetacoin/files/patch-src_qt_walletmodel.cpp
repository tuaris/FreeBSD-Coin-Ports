--- src/qt/walletmodel.cpp.orig	2018-07-31 20:08:28 UTC
+++ src/qt/walletmodel.cpp
@@ -26,6 +26,7 @@
 #include <QTimer>
 
 #include <boost/foreach.hpp>
+#include <boost/bind/bind.hpp>
 
 WalletModel::WalletModel(const PlatformStyle *platformStyle, CWallet *wallet, OptionsModel *optionsModel, QObject *parent) :
     QObject(parent), wallet(wallet), optionsModel(optionsModel), addressTableModel(0),
@@ -499,21 +500,21 @@ static void NotifyWatchonlyChanged(WalletModel *wallet
 void WalletModel::subscribeToCoreSignals()
 {
     // Connect signals to wallet
-    wallet->NotifyStatusChanged.connect(boost::bind(&NotifyKeyStoreStatusChanged, this, _1));
-    wallet->NotifyAddressBookChanged.connect(boost::bind(NotifyAddressBookChanged, this, _1, _2, _3, _4, _5, _6));
-    wallet->NotifyTransactionChanged.connect(boost::bind(NotifyTransactionChanged, this, _1, _2, _3));
-    wallet->ShowProgress.connect(boost::bind(ShowProgress, this, _1, _2));
-    wallet->NotifyWatchonlyChanged.connect(boost::bind(NotifyWatchonlyChanged, this, _1));
+    wallet->NotifyStatusChanged.connect(boost::bind(&NotifyKeyStoreStatusChanged, this, boost::placeholders::_1));
+    wallet->NotifyAddressBookChanged.connect(boost::bind(NotifyAddressBookChanged, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3, boost::placeholders::_4, boost::placeholders::_5, boost::placeholders::_6));
+    wallet->NotifyTransactionChanged.connect(boost::bind(NotifyTransactionChanged, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3));
+    wallet->ShowProgress.connect(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2));
+    wallet->NotifyWatchonlyChanged.connect(boost::bind(NotifyWatchonlyChanged, this, boost::placeholders::_1));
 }
 
 void WalletModel::unsubscribeFromCoreSignals()
 {
     // Disconnect signals from wallet
-    wallet->NotifyStatusChanged.disconnect(boost::bind(&NotifyKeyStoreStatusChanged, this, _1));
-    wallet->NotifyAddressBookChanged.disconnect(boost::bind(NotifyAddressBookChanged, this, _1, _2, _3, _4, _5, _6));
-    wallet->NotifyTransactionChanged.disconnect(boost::bind(NotifyTransactionChanged, this, _1, _2, _3));
-    wallet->ShowProgress.disconnect(boost::bind(ShowProgress, this, _1, _2));
-    wallet->NotifyWatchonlyChanged.disconnect(boost::bind(NotifyWatchonlyChanged, this, _1));
+    wallet->NotifyStatusChanged.disconnect(boost::bind(&NotifyKeyStoreStatusChanged, this, boost::placeholders::_1));
+    wallet->NotifyAddressBookChanged.disconnect(boost::bind(NotifyAddressBookChanged, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3, boost::placeholders::_4, boost::placeholders::_5, boost::placeholders::_6));
+    wallet->NotifyTransactionChanged.disconnect(boost::bind(NotifyTransactionChanged, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3));
+    wallet->ShowProgress.disconnect(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2));
+    wallet->NotifyWatchonlyChanged.disconnect(boost::bind(NotifyWatchonlyChanged, this, boost::placeholders::_1));
 }
 
 // WalletModel::UnlockContext implementation
