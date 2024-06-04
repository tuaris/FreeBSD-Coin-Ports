--- src/httpserver.cpp.orig	2021-05-15 06:47:32 UTC
+++ src/httpserver.cpp
@@ -31,6 +31,8 @@
 
 #include <support/events.h>
 
+#include <deque>
+
 #ifdef EVENT__HAVE_NETINET_IN_H
 #include <netinet/in.h>
 #ifdef _XOPEN_SOURCE_EXTENDED
