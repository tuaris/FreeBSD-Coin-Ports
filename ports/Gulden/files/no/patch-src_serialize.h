--- src/serialize.h.orig	2015-08-13 11:33:58 UTC
+++ src/serialize.h
@@ -6,6 +6,8 @@
 #ifndef BITCOIN_SERIALIZE_H
 #define BITCOIN_SERIALIZE_H
 
+#include "compat/endian.h"
+
 #include <algorithm>
 #include <assert.h>
 #include <ios>
@@ -18,8 +20,6 @@
 #include <utility>
 #include <vector>
 
-#include "compat/endian.h"
-
 class CScript;
 
 static const unsigned int MAX_SIZE = 0x02000000;
