--- src/scrypt-sse2.cpp.orig	2014-06-18 16:36:37 UTC
+++ src/scrypt-sse2.cpp
@@ -32,6 +32,7 @@
 #include <stdint.h>
 #include <string.h>
 #include <openssl/sha.h>
+#include <boost/lexical_cast.hpp>
 
 #include <emmintrin.h>
 
