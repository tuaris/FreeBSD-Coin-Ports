--- src/validationinterface.cpp.orig	2021-05-15 06:47:32 UTC
+++ src/validationinterface.cpp
@@ -17,6 +17,7 @@
 #include <future>
 
 #include <boost/signals2/signal.hpp>
+#include <boost/bind/bind.hpp>
 
 struct MainSignalsInstance {
     boost::signals2::signal<void (const CBlockIndex *, const CBlockIndex *, bool fInitialDownload)> UpdatedBlockTip;
@@ -60,11 +61,11 @@ size_t CMainSignals::CallbacksPending() {
 }
 
 void CMainSignals::RegisterWithMempoolSignals(CTxMemPool& pool) {
-    pool.NotifyEntryRemoved.connect(boost::bind(&CMainSignals::MempoolEntryRemoved, this, _1, _2));
+    pool.NotifyEntryRemoved.connect(boost::bind(&CMainSignals::MempoolEntryRemoved, this, boost::placeholders::_1, boost::placeholders::_2));
 }
 
 void CMainSignals::UnregisterWithMempoolSignals(CTxMemPool& pool) {
-    pool.NotifyEntryRemoved.disconnect(boost::bind(&CMainSignals::MempoolEntryRemoved, this, _1, _2));
+    pool.NotifyEntryRemoved.disconnect(boost::bind(&CMainSignals::MempoolEntryRemoved, this, boost::placeholders::_1, boost::placeholders::_2));
 }
 
 CMainSignals& GetMainSignals()
@@ -73,27 +74,27 @@ CMainSignals& GetMainSignals()
 }
 
 void RegisterValidationInterface(CValidationInterface* pwalletIn) {
-    g_signals.m_internals->UpdatedBlockTip.connect(boost::bind(&CValidationInterface::UpdatedBlockTip, pwalletIn, _1, _2, _3));
-    g_signals.m_internals->TransactionAddedToMempool.connect(boost::bind(&CValidationInterface::TransactionAddedToMempool, pwalletIn, _1));
-    g_signals.m_internals->BlockConnected.connect(boost::bind(&CValidationInterface::BlockConnected, pwalletIn, _1, _2, _3));
-    g_signals.m_internals->BlockDisconnected.connect(boost::bind(&CValidationInterface::BlockDisconnected, pwalletIn, _1));
-    g_signals.m_internals->TransactionRemovedFromMempool.connect(boost::bind(&CValidationInterface::TransactionRemovedFromMempool, pwalletIn, _1));
-    g_signals.m_internals->ChainStateFlushed.connect(boost::bind(&CValidationInterface::ChainStateFlushed, pwalletIn, _1));
-    g_signals.m_internals->Broadcast.connect(boost::bind(&CValidationInterface::ResendWalletTransactions, pwalletIn, _1, _2));
-    g_signals.m_internals->BlockChecked.connect(boost::bind(&CValidationInterface::BlockChecked, pwalletIn, _1, _2));
-    g_signals.m_internals->NewPoWValidBlock.connect(boost::bind(&CValidationInterface::NewPoWValidBlock, pwalletIn, _1, _2));
+    g_signals.m_internals->UpdatedBlockTip.connect(boost::bind(&CValidationInterface::UpdatedBlockTip, pwalletIn, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3));
+    g_signals.m_internals->TransactionAddedToMempool.connect(boost::bind(&CValidationInterface::TransactionAddedToMempool, pwalletIn, boost::placeholders::_1));
+    g_signals.m_internals->BlockConnected.connect(boost::bind(&CValidationInterface::BlockConnected, pwalletIn, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3));
+    g_signals.m_internals->BlockDisconnected.connect(boost::bind(&CValidationInterface::BlockDisconnected, pwalletIn, boost::placeholders::_1));
+    g_signals.m_internals->TransactionRemovedFromMempool.connect(boost::bind(&CValidationInterface::TransactionRemovedFromMempool, pwalletIn, boost::placeholders::_1));
+    g_signals.m_internals->ChainStateFlushed.connect(boost::bind(&CValidationInterface::ChainStateFlushed, pwalletIn, boost::placeholders::_1));
+    g_signals.m_internals->Broadcast.connect(boost::bind(&CValidationInterface::ResendWalletTransactions, pwalletIn, boost::placeholders::_1, boost::placeholders::_2));
+    g_signals.m_internals->BlockChecked.connect(boost::bind(&CValidationInterface::BlockChecked, pwalletIn, boost::placeholders::_1, boost::placeholders::_2));
+    g_signals.m_internals->NewPoWValidBlock.connect(boost::bind(&CValidationInterface::NewPoWValidBlock, pwalletIn, boost::placeholders::_1, boost::placeholders::_2));
 }
 
 void UnregisterValidationInterface(CValidationInterface* pwalletIn) {
-    g_signals.m_internals->BlockChecked.disconnect(boost::bind(&CValidationInterface::BlockChecked, pwalletIn, _1, _2));
-    g_signals.m_internals->Broadcast.disconnect(boost::bind(&CValidationInterface::ResendWalletTransactions, pwalletIn, _1, _2));
-    g_signals.m_internals->ChainStateFlushed.disconnect(boost::bind(&CValidationInterface::ChainStateFlushed, pwalletIn, _1));
-    g_signals.m_internals->TransactionAddedToMempool.disconnect(boost::bind(&CValidationInterface::TransactionAddedToMempool, pwalletIn, _1));
-    g_signals.m_internals->BlockConnected.disconnect(boost::bind(&CValidationInterface::BlockConnected, pwalletIn, _1, _2, _3));
-    g_signals.m_internals->BlockDisconnected.disconnect(boost::bind(&CValidationInterface::BlockDisconnected, pwalletIn, _1));
-    g_signals.m_internals->TransactionRemovedFromMempool.disconnect(boost::bind(&CValidationInterface::TransactionRemovedFromMempool, pwalletIn, _1));
-    g_signals.m_internals->UpdatedBlockTip.disconnect(boost::bind(&CValidationInterface::UpdatedBlockTip, pwalletIn, _1, _2, _3));
-    g_signals.m_internals->NewPoWValidBlock.disconnect(boost::bind(&CValidationInterface::NewPoWValidBlock, pwalletIn, _1, _2));
+    g_signals.m_internals->BlockChecked.disconnect(boost::bind(&CValidationInterface::BlockChecked, pwalletIn, boost::placeholders::_1, boost::placeholders::_2));
+    g_signals.m_internals->Broadcast.disconnect(boost::bind(&CValidationInterface::ResendWalletTransactions, pwalletIn, boost::placeholders::_1, boost::placeholders::_2));
+    g_signals.m_internals->ChainStateFlushed.disconnect(boost::bind(&CValidationInterface::ChainStateFlushed, pwalletIn, boost::placeholders::_1));
+    g_signals.m_internals->TransactionAddedToMempool.disconnect(boost::bind(&CValidationInterface::TransactionAddedToMempool, pwalletIn, boost::placeholders::_1));
+    g_signals.m_internals->BlockConnected.disconnect(boost::bind(&CValidationInterface::BlockConnected, pwalletIn, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3));
+    g_signals.m_internals->BlockDisconnected.disconnect(boost::bind(&CValidationInterface::BlockDisconnected, pwalletIn, boost::placeholders::_1));
+    g_signals.m_internals->TransactionRemovedFromMempool.disconnect(boost::bind(&CValidationInterface::TransactionRemovedFromMempool, pwalletIn, boost::placeholders::_1));
+    g_signals.m_internals->UpdatedBlockTip.disconnect(boost::bind(&CValidationInterface::UpdatedBlockTip, pwalletIn, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3));
+    g_signals.m_internals->NewPoWValidBlock.disconnect(boost::bind(&CValidationInterface::NewPoWValidBlock, pwalletIn, boost::placeholders::_1, boost::placeholders::_2));
 }
 
 void UnregisterAllValidationInterfaces() {
