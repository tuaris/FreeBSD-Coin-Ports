--- src/rpcwallet.cpp.orig	2016-01-14 03:11:54 UTC
+++ src/rpcwallet.cpp
@@ -10,6 +10,8 @@
 #include "util.h"
 #include "ntp.h"
 #include "base58.h"
+#include <stdint.h>
+#define INT64_MAX 0x7fffffffffffffffll
 
 using namespace json_spirit;
 using namespace std;
