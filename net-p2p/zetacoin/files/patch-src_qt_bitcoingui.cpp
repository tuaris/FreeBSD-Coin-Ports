--- src/qt/bitcoingui.cpp.orig	2018-07-31 20:08:28 UTC
+++ src/qt/bitcoingui.cpp
@@ -36,6 +36,8 @@
 
 #include <iostream>
 
+#include <boost/bind/bind.hpp>
+
 #include <QAction>
 #include <QApplication>
 #include <QDateTime>
@@ -1115,15 +1117,15 @@ static bool ThreadSafeMessageBox(BitcoinGUI *gui, cons
 void BitcoinGUI::subscribeToCoreSignals()
 {
     // Connect signals to client
-    uiInterface.ThreadSafeMessageBox.connect(boost::bind(ThreadSafeMessageBox, this, _1, _2, _3));
-    uiInterface.ThreadSafeQuestion.connect(boost::bind(ThreadSafeMessageBox, this, _1, _3, _4));
+    uiInterface.ThreadSafeMessageBox.connect(boost::bind(ThreadSafeMessageBox, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3));
+    uiInterface.ThreadSafeQuestion.connect(boost::bind(ThreadSafeMessageBox, this, boost::placeholders::_1, boost::placeholders::_3, boost::placeholders::_4));
 }
 
 void BitcoinGUI::unsubscribeFromCoreSignals()
 {
     // Disconnect signals from client
-    uiInterface.ThreadSafeMessageBox.disconnect(boost::bind(ThreadSafeMessageBox, this, _1, _2, _3));
-    uiInterface.ThreadSafeQuestion.disconnect(boost::bind(ThreadSafeMessageBox, this, _1, _3, _4));
+    uiInterface.ThreadSafeMessageBox.disconnect(boost::bind(ThreadSafeMessageBox, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3));
+    uiInterface.ThreadSafeQuestion.disconnect(boost::bind(ThreadSafeMessageBox, this, boost::placeholders::_1, boost::placeholders::_3, boost::placeholders::_4));
 }
 
 UnitDisplayStatusBarControl::UnitDisplayStatusBarControl(const PlatformStyle *platformStyle) :
