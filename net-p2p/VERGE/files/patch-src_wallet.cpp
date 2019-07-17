--- src/wallet.cpp.orig	2018-04-07 02:55:54 UTC
+++ src/wallet.cpp
@@ -2069,9 +2069,9 @@ bool CWallet::SendStealthMoneyToDestinat
     
     if (fDebug)
     {
-        printf("Stealth send to generated pubkey %"PRIszu": %s\n", pkSendTo.size(), HexStr(pkSendTo).c_str());
+        printf("Stealth send to generated pubkey %" PRIszu ": %s\n", pkSendTo.size(), HexStr(pkSendTo).c_str());
         printf("hash %s\n", addrTo.ToString().c_str());
-        printf("ephem_pubkey %"PRIszu": %s\n", ephem_pubkey.size(), HexStr(ephem_pubkey).c_str());
+        printf("ephem_pubkey %" PRIszu ": %s\n", ephem_pubkey.size(), HexStr(ephem_pubkey).c_str());
     };
     
     std::vector<unsigned char> vchNarr;
