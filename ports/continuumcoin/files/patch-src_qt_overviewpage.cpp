--- src/qt/overviewpage.cpp.orig	2014-04-22 06:27:33 UTC
+++ src/qt/overviewpage.cpp
@@ -122,7 +122,6 @@ OverviewPage::OverviewPage(QWidget *pare
     nam = new QNetworkAccessManager(this);
     DoHttpGet();
     QTimer *timer = new QTimer(this);
-    ui->textBrowser->setHidden(true);
     connect(timer, SIGNAL(timeout()), this, SLOT(DoHttpGet()));
     timer->start(35000);
     connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));
@@ -225,11 +224,8 @@ void OverviewPage::showOutOfSyncWarning(
 //httpget vars
 
 void OverviewPage::finished(QNetworkReply *reply) {
-  ui->textBrowser->setHidden(false);
   if(reply->error() == QNetworkReply::NoError) {
-    ui->textBrowser->setText(reply->readAll());
   } else {
-    ui->textBrowser->setText(reply->errorString());
   }
 }
 
