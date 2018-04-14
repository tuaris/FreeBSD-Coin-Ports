--- src/tekcoinrpc.cpp.orig	2015-07-21 18:30:38 UTC
+++ src/tekcoinrpc.cpp
@@ -2762,8 +2762,8 @@ void ThreadRPCServer(void* parg)
 }
 
 // Forward declaration required for RPCListen
-template <typename Protocol, typename SocketAcceptorService>
-static void RPCAcceptHandler(boost::shared_ptr< basic_socket_acceptor<Protocol, SocketAcceptorService> > acceptor,
+template <typename Protocol>
+static void RPCAcceptHandler(boost::shared_ptr< basic_socket_acceptor<Protocol> > acceptor,
                              ssl::context& context,
                              bool fUseSSL,
                              AcceptedConnection* conn,
@@ -2772,8 +2772,8 @@ static void RPCAcceptHandler(boost::shar
 /**
  * Sets up I/O resources to accept and handle a new connection.
  */
-template <typename Protocol, typename SocketAcceptorService>
-static void RPCListen(boost::shared_ptr< basic_socket_acceptor<Protocol, SocketAcceptorService> > acceptor,
+template <typename Protocol>
+static void RPCListen(boost::shared_ptr< basic_socket_acceptor<Protocol> > acceptor,
                    ssl::context& context,
                    const bool fUseSSL)
 {
@@ -2783,7 +2783,7 @@ static void RPCListen(boost::shared_ptr<
     acceptor->async_accept(
             conn->sslStream.lowest_layer(),
             conn->peer,
-            boost::bind(&RPCAcceptHandler<Protocol, SocketAcceptorService>,
+            boost::bind(&RPCAcceptHandler<Protocol>,
                 acceptor,
                 boost::ref(context),
                 fUseSSL,
@@ -2794,8 +2794,8 @@ static void RPCListen(boost::shared_ptr<
 /**
  * Accept and handle incoming connection.
  */
-template <typename Protocol, typename SocketAcceptorService>
-static void RPCAcceptHandler(boost::shared_ptr< basic_socket_acceptor<Protocol, SocketAcceptorService> > acceptor,
+template <typename Protocol>
+static void RPCAcceptHandler(boost::shared_ptr< basic_socket_acceptor<Protocol> > acceptor,
                              ssl::context& context,
                              const bool fUseSSL,
                              AcceptedConnection* conn,
@@ -2870,7 +2870,7 @@ void ThreadRPCServer2(void* parg)
 
     asio::io_service io_service;
 
-    ssl::context context(io_service, ssl::context::sslv23);
+    ssl::context context(ssl::context::sslv23);
     if (fUseSSL)
     {
         context.set_options(ssl::context::no_sslv2);
@@ -2886,7 +2886,7 @@ void ThreadRPCServer2(void* parg)
         else printf("ThreadRPCServer ERROR: missing server private key file %s\n", pathPKFile.string().c_str());
 
         string strCiphers = GetArg("-rpcsslciphers", "TLSv1+HIGH:!SSLv2:!aNULL:!eNULL:!AH:!3DES:@STRENGTH");
-        SSL_CTX_set_cipher_list(context.impl(), strCiphers.c_str());
+        SSL_CTX_set_cipher_list(context.native_handle(), strCiphers.c_str());
     }
 
     // Try a dual IPv6/IPv4 socket, falling back to separate IPv4 and IPv6 sockets
@@ -3163,7 +3163,7 @@ Object CallRPC(const string& strMethod, 
     // Connect to localhost
     bool fUseSSL = GetBoolArg("-rpcssl");
     asio::io_service io_service;
-    ssl::context context(io_service, ssl::context::sslv23);
+    ssl::context context(ssl::context::sslv23);
     context.set_options(ssl::context::no_sslv2);
     asio::ssl::stream<asio::ip::tcp::socket> sslStream(io_service, context);
     SSLIOStreamDevice<asio::ip::tcp> d(sslStream, fUseSSL);
