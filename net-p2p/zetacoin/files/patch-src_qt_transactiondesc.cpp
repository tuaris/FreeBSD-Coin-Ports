--- src/qt/transactiondesc.cpp.orig	2018-07-31 20:08:28 UTC
+++ src/qt/transactiondesc.cpp
@@ -244,14 +244,14 @@ QString TransactionDesc::toHTML(CWallet *wallet, CWall
     strHTML += "<b>" + tr("Output index") + ":</b> " + QString::number(rec->getOutputIndex()) + "<br>";
 
     // Message from normal bitcoin:URI (bitcoin:123...?message=example)
-    Q_FOREACH (const PAIRTYPE(std::string, std::string)& r, wtx.vOrderForm)
+    for (const std::pair<std::string, std::string>& r : wtx.vOrderForm)
         if (r.first == "Message")
             strHTML += "<br><b>" + tr("Message") + ":</b><br>" + GUIUtil::HtmlEscape(r.second, true) + "<br>";
 
     //
     // PaymentRequest info:
     //
-    Q_FOREACH (const PAIRTYPE(std::string, std::string)& r, wtx.vOrderForm)
+    for (const std::pair<std::string, std::string>& r : wtx.vOrderForm)
     {
         if (r.first == "PaymentRequest")
         {
