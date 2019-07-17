--- src/ntp.cpp.orig	2015-11-30 23:06:15 UTC
+++ src/ntp.cpp
@@ -15,6 +15,9 @@
 #include "net.h"
 //#include "util.h"
 #include "ui_interface.h"
+#include <stdint.h>
+
+#define INT64_MAX 0x7fffffffffffffffll
 
 extern int GetRandInt(int nMax);
 
