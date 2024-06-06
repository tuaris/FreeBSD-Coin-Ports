--- src/qt/transactiontablemodel.cpp.orig	2018-07-31 20:08:28 UTC
+++ src/qt/transactiontablemodel.cpp
@@ -27,6 +27,7 @@
 #include <QList>
 
 #include <boost/foreach.hpp>
+#include <boost/bind/bind.hpp>
 
 // Amount column is right-aligned it contains numbers
 static int column_alignments[] = {
@@ -777,13 +778,13 @@ static void ShowProgress(TransactionTableModel *ttm, c
 void TransactionTableModel::subscribeToCoreSignals()
 {
     // Connect signals to wallet
-    wallet->NotifyTransactionChanged.connect(boost::bind(NotifyTransactionChanged, this, _1, _2, _3));
-    wallet->ShowProgress.connect(boost::bind(ShowProgress, this, _1, _2));
+    wallet->NotifyTransactionChanged.connect(boost::bind(NotifyTransactionChanged, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3));
+    wallet->ShowProgress.connect(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2));
 }
 
 void TransactionTableModel::unsubscribeFromCoreSignals()
 {
     // Disconnect signals from wallet
-    wallet->NotifyTransactionChanged.disconnect(boost::bind(NotifyTransactionChanged, this, _1, _2, _3));
-    wallet->ShowProgress.disconnect(boost::bind(ShowProgress, this, _1, _2));
+    wallet->NotifyTransactionChanged.disconnect(boost::bind(NotifyTransactionChanged, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3));
+    wallet->ShowProgress.disconnect(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2));
 }
