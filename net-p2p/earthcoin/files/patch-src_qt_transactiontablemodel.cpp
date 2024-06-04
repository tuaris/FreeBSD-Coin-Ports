--- src/qt/transactiontablemodel.cpp.orig	2021-05-15 06:47:32 UTC
+++ src/qt/transactiontablemodel.cpp
@@ -21,6 +21,8 @@
 #include <uint256.h>
 #include <util.h>
 
+#include <boost/bind/bind.hpp>
+
 #include <QColor>
 #include <QDateTime>
 #include <QDebug>
@@ -749,8 +751,8 @@ static void ShowProgress(TransactionTableModel *ttm, c
 void TransactionTableModel::subscribeToCoreSignals()
 {
     // Connect signals to wallet
-    m_handler_transaction_changed = walletModel->wallet().handleTransactionChanged(boost::bind(NotifyTransactionChanged, this, _1, _2));
-    m_handler_show_progress = walletModel->wallet().handleShowProgress(boost::bind(ShowProgress, this, _1, _2));
+    m_handler_transaction_changed = walletModel->wallet().handleTransactionChanged(boost::bind(NotifyTransactionChanged, this, boost::placeholders::_1, boost::placeholders::_2));
+    m_handler_show_progress = walletModel->wallet().handleShowProgress(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2));
 }
 
 void TransactionTableModel::unsubscribeFromCoreSignals()
