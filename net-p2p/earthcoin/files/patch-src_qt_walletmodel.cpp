--- src/qt/walletmodel.cpp.orig	2021-05-15 06:47:32 UTC
+++ src/qt/walletmodel.cpp
@@ -21,6 +21,7 @@
 #include <wallet/wallet.h>
 
 #include <stdint.h>
+#include <boost/bind/bind.hpp>
 
 #include <QDebug>
 #include <QMessageBox>
@@ -438,10 +439,10 @@ void WalletModel::subscribeToCoreSignals()
     // Connect signals to wallet
     m_handler_unload = m_wallet->handleUnload(boost::bind(&NotifyUnload, this));
     m_handler_status_changed = m_wallet->handleStatusChanged(boost::bind(&NotifyKeyStoreStatusChanged, this));
-    m_handler_address_book_changed = m_wallet->handleAddressBookChanged(boost::bind(NotifyAddressBookChanged, this, _1, _2, _3, _4, _5));
-    m_handler_transaction_changed = m_wallet->handleTransactionChanged(boost::bind(NotifyTransactionChanged, this, _1, _2));
-    m_handler_show_progress = m_wallet->handleShowProgress(boost::bind(ShowProgress, this, _1, _2));
-    m_handler_watch_only_changed = m_wallet->handleWatchOnlyChanged(boost::bind(NotifyWatchonlyChanged, this, _1));
+    m_handler_address_book_changed = m_wallet->handleAddressBookChanged(boost::bind(NotifyAddressBookChanged, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3, boost::placeholders::_4, boost::placeholders::_5));
+    m_handler_transaction_changed = m_wallet->handleTransactionChanged(boost::bind(NotifyTransactionChanged, this, boost::placeholders::_1, boost::placeholders::_2));
+    m_handler_show_progress = m_wallet->handleShowProgress(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2));
+    m_handler_watch_only_changed = m_wallet->handleWatchOnlyChanged(boost::bind(NotifyWatchonlyChanged, this, boost::placeholders::_1));
 }
 
 void WalletModel::unsubscribeFromCoreSignals()
