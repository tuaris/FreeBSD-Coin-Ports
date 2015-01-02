--- mooncoin-qt.pro.orig	2014-04-03 20:52:43 UTC
+++ mooncoin-qt.pro
@@ -450,7 +450,7 @@ LIBS += $$join(BOOST_LIB_PATH,,-L,) $$jo
 LIBS += -lssl -lcrypto
 # -lgdi32 has to happen after -lcrypto (see  #681)
 !macx {
-    LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX
+    LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_chrono$$BOOST_THREAD_LIB_SUFFIX
     LIBS += -lboost_thread$$BOOST_THREAD_LIB_SUFFIX -lboost_chrono$$BOOST_LIB_SUFFIX -ldb_cxx$$BDB_LIB_SUFFIX
 }
 
