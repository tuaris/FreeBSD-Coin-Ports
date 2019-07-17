--- src/bitcoin-cli.cpp.orig	2016-04-17 16:40:42 UTC
+++ src/bitcoin-cli.cpp
@@ -109,7 +109,7 @@ Object CallRPC(const string& strMethod, 
     // Connect to localhost
     bool fUseSSL = GetBoolArg("-rpcssl", false);
     asio::io_service io_service;
-    ssl::context context(io_service, ssl::context::sslv23);
+    ssl::context context(ssl::context::sslv23);
     context.set_options(ssl::context::no_sslv2 | ssl::context::no_sslv3);
     asio::ssl::stream<asio::ip::tcp::socket> sslStream(io_service, context);
     SSLIOStreamDevice<asio::ip::tcp> d(sslStream, fUseSSL);
