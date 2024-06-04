--- src/validation.cpp.orig	2024-06-04 22:46:36 UTC
+++ src/validation.cpp
@@ -48,6 +48,7 @@
 
 #include <boost/algorithm/string/replace.hpp>
 #include <boost/thread.hpp>
+#include <boost/bind/bind.hpp>
 
 #if defined(NDEBUG)
 # error "Earthcoin cannot be compiled without assertions."
@@ -2405,11 +2406,11 @@ class ConnectTrace { (private)
 
 public:
     explicit ConnectTrace(CTxMemPool &_pool) : blocksConnected(1), pool(_pool) {
-        pool.NotifyEntryRemoved.connect(boost::bind(&ConnectTrace::NotifyEntryRemoved, this, _1, _2));
+        pool.NotifyEntryRemoved.connect(boost::bind(&ConnectTrace::NotifyEntryRemoved, this, boost::placeholders::_1, boost::placeholders::_2));
     }
 
     ~ConnectTrace() {
-        pool.NotifyEntryRemoved.disconnect(boost::bind(&ConnectTrace::NotifyEntryRemoved, this, _1, _2));
+        pool.NotifyEntryRemoved.disconnect(boost::bind(&ConnectTrace::NotifyEntryRemoved, this, boost::placeholders::_1, boost::placeholders::_2));
     }
 
     void BlockConnected(CBlockIndex* pindex, std::shared_ptr<const CBlock> pblock) {
