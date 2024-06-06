--- src/qt/clientmodel.cpp.orig	2024-06-06 07:29:16 UTC
+++ src/qt/clientmodel.cpp
@@ -19,6 +19,8 @@
 
 #include <stdint.h>
 
+#include <boost/bind/bind.hpp>
+
 #include <QDebug>
 #include <QTimer>
 
@@ -249,21 +251,21 @@ static void BlockTipChanged(ClientModel *clientmodel, 
 void ClientModel::subscribeToCoreSignals()
 {
     // Connect signals to client
-    uiInterface.ShowProgress.connect(boost::bind(ShowProgress, this, _1, _2));
-    uiInterface.NotifyNumConnectionsChanged.connect(boost::bind(NotifyNumConnectionsChanged, this, _1));
+    uiInterface.ShowProgress.connect(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2));
+    uiInterface.NotifyNumConnectionsChanged.connect(boost::bind(NotifyNumConnectionsChanged, this, boost::placeholders::_1));
     uiInterface.NotifyAlertChanged.connect(boost::bind(NotifyAlertChanged, this));
     uiInterface.BannedListChanged.connect(boost::bind(BannedListChanged, this));
-    uiInterface.NotifyBlockTip.connect(boost::bind(BlockTipChanged, this, _1, _2, false));
-    uiInterface.NotifyHeaderTip.connect(boost::bind(BlockTipChanged, this, _1, _2, true));
+    uiInterface.NotifyBlockTip.connect(boost::bind(BlockTipChanged, this, boost::placeholders::_1, boost::placeholders::_2, false));
+    uiInterface.NotifyHeaderTip.connect(boost::bind(BlockTipChanged, this, boost::placeholders::_1, boost::placeholders::_2, true));
 }
 
 void ClientModel::unsubscribeFromCoreSignals()
 {
     // Disconnect signals from client
-    uiInterface.ShowProgress.disconnect(boost::bind(ShowProgress, this, _1, _2));
-    uiInterface.NotifyNumConnectionsChanged.disconnect(boost::bind(NotifyNumConnectionsChanged, this, _1));
+    uiInterface.ShowProgress.disconnect(boost::bind(ShowProgress, this, boost::placeholders::_1, boost::placeholders::_2));
+    uiInterface.NotifyNumConnectionsChanged.disconnect(boost::bind(NotifyNumConnectionsChanged, this, boost::placeholders::_1));
     uiInterface.NotifyAlertChanged.disconnect(boost::bind(NotifyAlertChanged, this));
     uiInterface.BannedListChanged.disconnect(boost::bind(BannedListChanged, this));
-    uiInterface.NotifyBlockTip.disconnect(boost::bind(BlockTipChanged, this, _1, _2, false));
-    uiInterface.NotifyHeaderTip.disconnect(boost::bind(BlockTipChanged, this, _1, _2, true));
+    uiInterface.NotifyBlockTip.disconnect(boost::bind(BlockTipChanged, this, boost::placeholders::_1, boost::placeholders::_2, false));
+    uiInterface.NotifyHeaderTip.disconnect(boost::bind(BlockTipChanged, this, boost::placeholders::_1, boost::placeholders::_2, true));
 }
