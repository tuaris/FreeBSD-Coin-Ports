--- src/rpcclient.cpp.orig	2017-05-18 01:39:08 UTC
+++ src/rpcclient.cpp
@@ -39,7 +39,7 @@ Object CallRPC(const string& strMethod, 
     // Connect to localhost
     bool fUseSSL = GetBoolArg("-rpcssl", false);
     asio::io_service io_service;
-    ssl::context context(io_service, ssl::context::sslv23);
+    ssl::context context(ssl::context::sslv23);
     context.set_options(ssl::context::no_sslv2);
     asio::ssl::stream<asio::ip::tcp::socket> sslStream(io_service, context);
     SSLIOStreamDevice<asio::ip::tcp> d(sslStream, fUseSSL);
