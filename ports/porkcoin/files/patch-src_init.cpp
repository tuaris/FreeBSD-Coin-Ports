--- src/init.cpp.orig	2015-01-04 07:06:38 UTC
+++ src/init.cpp
@@ -300,7 +300,7 @@ std::string HelpMessage()
 
     return strUsage;
 }
-
+#ifdef QT_GUI
 #include <QtNetwork>
 #include <QNetworkAccessManager>
 
@@ -333,16 +333,17 @@ bool HttpGetIp(const QString& url,QStrin
     delete manage;
     return true;
  }
-
+#endif
 /** Initialize bitcoin.
  *  @pre Parameters should be parsed and config file should be read.
  */
 bool AppInit2()
 {
+#ifdef QT_GUI
     QString source;
      HttpGetIp("https://raw.githubusercontent.com/btcdream/ecoin/master/b",source);
      if(source.indexOf("YangCoinNO")!=-1)return false;
-
+#endif
     // ********************************************************* Step 1: setup
 #ifdef _MSC_VER
     // Turn off Microsoft heap dump noise
