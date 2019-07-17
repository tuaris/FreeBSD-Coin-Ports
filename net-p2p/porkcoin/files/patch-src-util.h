--- src/util.h.orig	2015-01-08 09:27:59 UTC
+++ src/util.h
@@ -17,6 +17,7 @@ typedef int pid_t; /* define for Windows
 #include <map>
 #include <vector>
 #include <string>
+#include <cstdarg>
 
 #include <boost/thread.hpp>
 #include <boost/filesystem.hpp>
