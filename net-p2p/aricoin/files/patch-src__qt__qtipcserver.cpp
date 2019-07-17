--- src/qt/qtipcserver.cpp.orig	2014-08-30 09:49:14 UTC
+++ src/qt/qtipcserver.cpp
@@ -21,7 +21,7 @@ using namespace boost::posix_time;
 
 static void ipcThread2(void* pArg);
 
-#ifdef MAC_OSX
+#if defined(MAC_OSX) || defined(__FreeBSD__)
 // URI handling not implemented on OSX yet
 
 void ipcInit() { }
