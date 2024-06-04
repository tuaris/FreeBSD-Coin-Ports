--- src/net_processing.cpp.orig	2021-05-15 06:47:32 UTC
+++ src/net_processing.cpp
@@ -30,6 +30,7 @@
 #include <utilstrencodings.h>
 
 #include <memory>
+#include <array>
 
 #if defined(NDEBUG)
 # error "Earthcoin cannot be compiled without assertions."
