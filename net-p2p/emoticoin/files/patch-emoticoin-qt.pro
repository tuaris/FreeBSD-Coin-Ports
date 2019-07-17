--- emoticoin-qt.pro.orig	2014-03-21 11:09:42 UTC
+++ emoticoin-qt.pro
@@ -22,16 +22,6 @@ CONFIG += static
 #    BOOST_INCLUDE_PATH, BOOST_LIB_PATH, BDB_INCLUDE_PATH,
 #    BDB_LIB_PATH, OPENSSL_INCLUDE_PATH and OPENSSL_LIB_PATH respectively
 
-BOOST_LIB_SUFFIX=-mgw48-mt-s-1_55
-BOOST_INCLUDE_PATH=C:/deps/boost_1_55_0
-BOOST_LIB_PATH=C:/deps/boost_1_55_0/stage/lib
-BDB_INCLUDE_PATH=C:/deps/db-4.8.30.NC/build_unix
-BDB_LIB_PATH=C:/deps/db-4.8.30.NC/build_unix
-OPENSSL_INCLUDE_PATH=C:/deps/openssl-1.0.1e/include
-OPENSSL_LIB_PATH=C:/deps/openssl-1.0.1e
-MINIUPNPC_INCLUDE_PATH=C:/deps/
-MINIUPNPC_LIB_PATH=C:/deps/miniupnpc
-
 OBJECTS_DIR = build
 MOC_DIR = build
 UI_DIR = build
@@ -444,7 +434,7 @@ LIBS += $$join(BOOST_LIB_PATH,,-L,) $$jo
 LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
 # -lgdi32 has to happen after -lcrypto (see  #681)
 win32:LIBS += -lws2_32 -lshlwapi -lmswsock -lole32 -loleaut32 -luuid -lgdi32
-LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX
+LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX -lboost_chrono$$BOOST_THREAD_LIB_SUFFIX
 win32:LIBS += -lboost_chrono$$BOOST_LIB_SUFFIX
 macx:LIBS += -lboost_chrono$$BOOST_LIB_SUFFIX
 
