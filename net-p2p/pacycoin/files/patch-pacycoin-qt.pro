--- pacycoin-qt.pro.orig	2015-07-21 18:30:38 UTC
+++ pacycoin-qt.pro
@@ -20,14 +20,14 @@ windows:LIBS += -lshlwapi
 LIBS += $$join(BOOST_LIB_PATH,,-L,) $$join(BDB_LIB_PATH,,-L,) $$join(OPENSSL_LIB_PATH,,-L,) $$join(QRENCODE_LIB_PATH,,-L,)
 LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
 windows:LIBS += -lws2_32 -lole32 -loleaut32 -luuid -lgdi32
-LIBS += -lboost_system-mgw46-mt-sd-1_53 -lboost_filesystem-mgw46-mt-sd-1_53 -lboost_program_options-mgw46-mt-sd-1_53 -lboost_thread-mgw46-mt-sd-1_53
-BOOST_LIB_SUFFIX=-mgw46-mt-sd-1_53
-BOOST_INCLUDE_PATH=C:/deps/boost
-BOOST_LIB_PATH=C:/deps/boost/stage/lib
-BDB_INCLUDE_PATH=c:/deps/db/build_unix
-BDB_LIB_PATH=c:/deps/db/build_unix
-OPENSSL_INCLUDE_PATH=c:/deps/ssl/include
-OPENSSL_LIB_PATH=c:/deps/ssl
+#LIBS += -lboost_system-mgw46-mt-sd-1_53 -lboost_filesystem-mgw46-mt-sd-1_53 -lboost_program_options-mgw46-mt-sd-1_53 -lboost_thread-mgw46-mt-sd-1_53
+#BOOST_LIB_SUFFIX=-mgw46-mt-sd-1_53
+#BOOST_INCLUDE_PATH=C:/deps/boost
+#BOOST_LIB_PATH=C:/deps/boost/stage/lib
+#BDB_INCLUDE_PATH=c:/deps/db/build_unix
+#BDB_LIB_PATH=c:/deps/db/build_unix
+#OPENSSL_INCLUDE_PATH=c:/deps/ssl/include
+#OPENSSL_LIB_PATH=c:/deps/ssl
 OBJECTS_DIR = build
 MOC_DIR = build
 UI_DIR = build
@@ -366,7 +366,7 @@ LIBS += $$join(BOOST_LIB_PATH,,-L,) $$jo
 LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
 # -lgdi32 has to happen after -lcrypto (see  #681)
 windows:LIBS += -lws2_32 -lmswsock -lole32 -loleaut32 -luuid -lgdi32
-LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX
+LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX -lboost_chrono$$BOOST_THREAD_LIB_SUFFIX
 
 contains(RELEASE, 1) {
     !windows:!macx {
