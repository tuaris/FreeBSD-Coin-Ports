--- src/qt/sendcoinsdialog.cpp.orig	2021-05-15 06:47:32 UTC
+++ src/qt/sendcoinsdialog.cpp
@@ -23,6 +23,8 @@
 #include <policy/fees.h>
 #include <wallet/fees.h>
 
+#include <array>
+
 #include <QFontMetrics>
 #include <QScrollBar>
 #include <QSettings>
