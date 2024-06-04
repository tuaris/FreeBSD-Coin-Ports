--- src/qt/earthcoingui.cpp.orig	2021-05-15 06:47:32 UTC
+++ src/qt/earthcoingui.cpp
@@ -39,6 +39,8 @@
 
 #include <iostream>
 
+#include <boost/bind/bind.hpp>
+
 #include <QAction>
 #include <QApplication>
 #include <QComboBox>
@@ -1276,8 +1278,8 @@ static bool ThreadSafeMessageBox(EarthcoinGUI *gui, co
 void EarthcoinGUI::subscribeToCoreSignals()
 {
     // Connect signals to client
-    m_handler_message_box = m_node.handleMessageBox(boost::bind(ThreadSafeMessageBox, this, _1, _2, _3));
-    m_handler_question = m_node.handleQuestion(boost::bind(ThreadSafeMessageBox, this, _1, _3, _4));
+    m_handler_message_box = m_node.handleMessageBox(boost::bind(ThreadSafeMessageBox, this, boost::placeholders::_1, boost::placeholders::_2, boost::placeholders::_3));
+    m_handler_question = m_node.handleQuestion(boost::bind(ThreadSafeMessageBox, this, boost::placeholders::_1, boost::placeholders::_3, boost::placeholders::_4));
 }
 
 void EarthcoinGUI::unsubscribeFromCoreSignals()
