--- src/qt/sendcoinsdialog.cpp.orig	2018-07-31 20:08:28 UTC
+++ src/qt/sendcoinsdialog.cpp
@@ -22,6 +22,8 @@
 #include "txmempool.h"
 #include "wallet/wallet.h"
 
+#include <array>
+
 #include <QMessageBox>
 #include <QScrollBar>
 #include <QSettings>
