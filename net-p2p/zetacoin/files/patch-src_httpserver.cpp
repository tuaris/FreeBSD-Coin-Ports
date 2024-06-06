--- src/httpserver.cpp.orig	2018-07-31 20:08:28 UTC
+++ src/httpserver.cpp
@@ -27,6 +27,8 @@
 #include <event2/util.h>
 #include <event2/keyvalq_struct.h>
 
+#include <deque>
+
 #ifdef EVENT__HAVE_NETINET_IN_H
 #include <netinet/in.h>
 #ifdef _XOPEN_SOURCE_EXTENDED
