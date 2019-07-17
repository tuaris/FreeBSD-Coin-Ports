--- src/rpcsmessage.cpp.orig	2018-04-07 02:55:54 UTC
+++ src/rpcsmessage.cpp
@@ -805,7 +805,7 @@ Value smsgbuckets(const Array& params, b
                 std::string sBucket = boost::lexical_cast<std::string>(it->first);
                 std::string sFile = sBucket + "_01.dat";
                 
-                snprintf(cbuf, sizeof(cbuf), "%"PRIszu, tokenSet.size());
+                snprintf(cbuf, sizeof(cbuf), "%" PRIszu, tokenSet.size());
                 std::string snContents(cbuf);
                 
                 std::string sHash = boost::lexical_cast<std::string>(it->second.hash);
