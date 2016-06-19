--- src/rpcdump.cpp.orig	2013-11-21 23:13:49 UTC
+++ src/rpcdump.cpp
@@ -27,7 +27,7 @@ std::string static EncodeDumpTime(int64 
 }
 
 int64 static DecodeDumpTime(const std::string &str) {
-    static const boost::posix_time::time_input_facet facet("%Y-%m-%dT%H:%M:%SZ");
+    static boost::posix_time::time_input_facet facet("%Y-%m-%dT%H:%M:%SZ");
     static const boost::posix_time::ptime epoch = boost::posix_time::from_time_t(0);
     const std::locale loc(std::locale::classic(), &facet);
     std::istringstream iss(str);
