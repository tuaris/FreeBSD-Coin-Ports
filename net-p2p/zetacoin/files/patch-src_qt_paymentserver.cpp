--- src/qt/paymentserver.cpp.orig	2018-07-31 20:08:28 UTC
+++ src/qt/paymentserver.cpp
@@ -555,7 +555,7 @@ bool PaymentServer::processPaymentRequest(const Paymen
     QList<std::pair<CScript, CAmount> > sendingTos = request.getPayTo();
     QStringList addresses;
 
-    Q_FOREACH(const PAIRTYPE(CScript, CAmount)& sendingTo, sendingTos) {
+    for (const std::pair<CScript, CAmount>& sendingTo : sendingTos) {
         // Extract and check destination addresses
         CTxDestination dest;
         if (ExtractDestination(sendingTo.first, dest)) {
