--- binarycoin-qt.pro.orig	2015-11-11 00:51:37 UTC
+++ binarycoin-qt.pro
@@ -25,20 +25,6 @@ greaterThan(QT_MAJOR_VERSION, 4) {
 #    BOOST_INCLUDE_PATH, BOOST_LIB_PATH, BDB_INCLUDE_PATH,
 #    BDB_LIB_PATH, OPENSSL_INCLUDE_PATH and OPENSSL_LIB_PATH respectively
 
-win32{
-BOOST_LIB_SUFFIX=-mgw49-mt-s-1_57
-BOOST_INCLUDE_PATH=C:/deps/boost_1_57_0
-BOOST_LIB_PATH=C:/deps/boost_1_57_0/stage/lib
-BDB_INCLUDE_PATH=C:/deps/db-6.1.26.NC/build_unix
-BDB_LIB_PATH=C:/deps/db-6.1.26.NC/build_unix
-OPENSSL_INCLUDE_PATH=C:/deps/openssl-1.0.2d/include
-OPENSSL_LIB_PATH=C:/deps/openssl-1.0.2d
-MINIUPNPC_INCLUDE_PATH=C:/deps/
-MINIUPNPC_LIB_PATH=C:/deps/miniupnpc
-QRENCODE_INCLUDE_PATH=C:/deps/qrencode-3.4.4
-QRENCODE_LIB_PATH=C:/deps/qrencode-3.4.4/.libs
-}
-
 OBJECTS_DIR = build
 MOC_DIR = build
 UI_DIR = build
@@ -388,7 +374,7 @@ LIBS += $$join(BOOST_LIB_PATH,,-L,) $$jo
 LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
 # -lgdi32 has to happen after -lcrypto (see  #681)
 windows:LIBS += -lole32 -luuid -lgdi32
-LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX
+LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX -lboost_chrono$$BOOST_THREAD_LIB_SUFFIX
 
 contains(RELEASE, 1) {
     !windows:!macx {
