--- src/util.cpp.orig	2015-11-30 23:06:15 UTC
+++ src/util.cpp
@@ -33,6 +33,7 @@ namespace boost {
 #include <openssl/crypto.h>
 #include <openssl/rand.h>
 #include <stdarg.h>
+#include <stdint.h>
 
 #ifdef WIN32
 #ifdef _MSC_VER
@@ -63,6 +64,8 @@ namespace boost {
 #include <execinfo.h>
 #endif
 
+#define INT64_MAX 0x7fffffffffffffffll
+
 
 using namespace std;
  using namespace boost;
