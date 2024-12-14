--- src/random.h.orig	2024-05-12 22:05:21 UTC
+++ src/random.h
@@ -8,6 +8,7 @@
 
 #include "uint256.h"
 
+#include <limits>
 #include <stdint.h>
 
 /* Seed OpenSSL PRNG with additional entropy data */
@@ -44,6 +45,14 @@ class FastRandomContext { (public)
 
     uint32_t Rz;
     uint32_t Rw;
+};
+
+class OpenSSLRandomContext {
+public:
+  typedef uint64_t result_type;
+  static constexpr uint64_t min() { return 0; }
+  static constexpr uint64_t max() { return std::numeric_limits<uint64_t>::max(); }
+  inline uint64_t operator()() { return GetRand(max()); }
 };
 
 #endif // BITCOIN_RANDOM_H
