--- src/wallet.cpp.orig	2014-08-30 09:49:14 UTC
+++ src/wallet.cpp
@@ -11,6 +11,7 @@
 #include "ui_interface.h"
 #include "base58.h"
 #include "main.h"
+#include <boost/algorithm/string/replace.hpp>
 
 using namespace std;
 
