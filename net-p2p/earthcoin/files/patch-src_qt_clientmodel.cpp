--- src/qt/clientmodel.cpp.orig	2021-05-15 06:47:32 UTC
+++ src/qt/clientmodel.cpp
@@ -25,6 +25,8 @@
 
 #include <stdint.h>
 
+#include <boost/bind/bind.hpp>
+
 #include <QDebug>
 #include <QTimer>
 
@@ -247,13 +249,13 @@ static void BlockTipChanged(ClientModel *clientmodel, 
 void ClientModel::subscribeToCoreSignals()
 {
     // Connect signals to client
-    m_handler_show_progress = m_node.handleShowProgress(boost::bind(ShowProgress, this, _1, _2));
-    m_handler_notify_num_connections_changed = m_node.handleNotifyNumConnectionsChanged(boost::bind(NotifyNumConnectionsChanged, this, _1));
-    m_handler_notify_network_active_changed = m_node.handleNotifyNetworkActiveChanged(boost::bind(NotifyNetworkActiveChanged, this, _1));
+    m_handler_show_progress = m_node.handleShowProgress(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2));
+    m_handler_notify_num_connections_changed = m_node.handleNotifyNumConnectionsChanged(boost::bind(NotifyNumConnectionsChanged, this, boost::placeholders::_1));
+    m_handler_notify_network_active_changed = m_node.handleNotifyNetworkActiveChanged(boost::bind(NotifyNetworkActiveChanged, this, boost::placeholders::_1));
     m_handler_notify_alert_changed = m_node.handleNotifyAlertChanged(boost::bind(NotifyAlertChanged, this));
     m_handler_banned_list_changed = m_node.handleBannedListChanged(boost::bind(BannedListChanged, this));
-    m_handler_notify_block_tip = m_node.handleNotifyBlockTip(boost::bind(BlockTipChanged, this, _1, _2, _3, _4, false));
-    m_handler_notify_header_tip = m_node.handleNotifyHeaderTip(boost::bind(BlockTipChanged, this, _1, _2, _3, _4, true));
+    m_handler_notify_block_tip = m_node.handleNotifyBlockTip(boost::bind(BlockTipChanged, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3, boost::placeholders::_4, false));
+    m_handler_notify_header_tip = m_node.handleNotifyHeaderTip(boost::bind(BlockTipChanged, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3, boost::placeholders::_4, true));
 }
 
 void ClientModel::unsubscribeFromCoreSignals()
