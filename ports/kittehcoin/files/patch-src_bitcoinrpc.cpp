--- src/bitcoinrpc.cpp.orig	2014-04-09 16:44:01 UTC
+++ src/bitcoinrpc.cpp
@@ -660,8 +660,8 @@ private:
 void ServiceConnection(AcceptedConnection *conn);
 
 // Forward declaration required for RPCListen
-template <typename Protocol, typename SocketAcceptorService>
-static void RPCAcceptHandler(boost::shared_ptr< basic_socket_acceptor<Protocol, SocketAcceptorService> > acceptor,
+template <typename Protocol >
+static void RPCAcceptHandler(boost::shared_ptr< basic_socket_acceptor<Protocol> > acceptor,
                              ssl::context& context,
                              bool fUseSSL,
                              AcceptedConnection* conn,
@@ -670,8 +670,8 @@ static void RPCAcceptHandler(boost::shar
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
@@ -681,7 +681,7 @@ static void RPCListen(boost::shared_ptr<
     acceptor->async_accept(
             conn->sslStream.lowest_layer(),
             conn->peer,
-            boost::bind(&RPCAcceptHandler<Protocol, SocketAcceptorService>,
+            boost::bind(&RPCAcceptHandler<Protocol>,
                 acceptor,
                 boost::ref(context),
                 fUseSSL,
@@ -692,8 +692,8 @@ static void RPCListen(boost::shared_ptr<
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
@@ -762,7 +762,7 @@ void StartRPCThreads()
 
     assert(rpc_io_service == NULL);
     rpc_io_service = new asio::io_service();
-    rpc_ssl_context = new ssl::context(*rpc_io_service, ssl::context::sslv23);
+    rpc_ssl_context = new ssl::context(ssl::context::sslv23);
 
     const bool fUseSSL = GetBoolArg("-rpcssl");
 
@@ -781,7 +781,7 @@ void StartRPCThreads()
         else printf("ThreadRPCServer ERROR: missing server private key file %s\n", pathPKFile.string().c_str());
 
         string strCiphers = GetArg("-rpcsslciphers", "TLSv1+HIGH:!SSLv2:!aNULL:!eNULL:!AH:!3DES:@STRENGTH");
-        SSL_CTX_set_cipher_list(rpc_ssl_context->impl(), strCiphers.c_str());
+        SSL_CTX_set_cipher_list(rpc_ssl_context->native_handle(), strCiphers.c_str());
     }
 
     // Try a dual IPv6/IPv4 socket, falling back to separate IPv4 and IPv6 sockets
@@ -1064,7 +1064,7 @@ Object CallRPC(const string& strMethod, 
     // Connect to localhost
     bool fUseSSL = GetBoolArg("-rpcssl");
     asio::io_service io_service;
-    ssl::context context(io_service, ssl::context::sslv23);
+    ssl::context context(ssl::context::sslv23);
     context.set_options(ssl::context::no_sslv2);
     asio::ssl::stream<asio::ip::tcp::socket> sslStream(io_service, context);
     SSLIOStreamDevice<asio::ip::tcp> d(sslStream, fUseSSL);
