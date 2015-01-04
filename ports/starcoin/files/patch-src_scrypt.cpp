--- src/scrypt.cpp.orig	2014-06-18 16:36:37 UTC
+++ src/scrypt.cpp
@@ -34,6 +34,7 @@
 #include <stdint.h>
 #include <string.h>
 #include <openssl/sha.h>
+#include <boost/lexical_cast.hpp>
 
 #if defined(USE_SSE2) && !defined(USE_SSE2_ALWAYS)
 #ifdef _MSC_VER
