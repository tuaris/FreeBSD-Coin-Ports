--- Htmlcoin.pro.orig	2015-03-26 22:29:14 UTC
+++ Htmlcoin.pro
@@ -14,19 +14,6 @@ greaterThan(QT_MAJOR_VERSION, 4) {
     DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
 }
 
-BOOST_LIB_SUFFIX=-mgw49-mt-s-1_57
-BOOST_INCLUDE_PATH=C:/deps/boost_1_57_0
-BOOST_LIB_PATH=C:/deps/boost_1_57_0/stage/lib
-BDB_INCLUDE_PATH=C:/deps/db-4.8.30.NC/build_unix
-BDB_LIB_PATH=C:/deps/db-4.8.30.NC/build_unix
-OPENSSL_INCLUDE_PATH=C:/deps/openssl-1.0.1j/include
-OPENSSL_LIB_PATH=C:/deps/openssl-1.0.1j
-MINIUPNPC_INCLUDE_PATH=C:/deps/
-MINIUPNPC_LIB_PATH=C:/deps/miniupnpc
-QRENCODE_INCLUDE_PATH=C:/deps/qrencode-3.4.4
-QRENCODE_LIB_PATH=C:/deps/qrencode-3.4.4/.libs
-
-
 # for boost 1.37, add -mt to the boost libraries
 # use: qmake BOOST_LIB_SUFFIX=-mt
 # for boost thread win32 with _win32 sufix
@@ -462,10 +449,10 @@ macx:QMAKE_CXXFLAGS_THREAD += -pthread
 # Set libraries and includes at end, to use platform-defined defaults if not overridden
 INCLUDEPATH += $$BOOST_INCLUDE_PATH $$BDB_INCLUDE_PATH $$OPENSSL_INCLUDE_PATH $$QRENCODE_INCLUDE_PATH
 LIBS += $$join(BOOST_LIB_PATH,,-L,) $$join(BDB_LIB_PATH,,-L,) $$join(OPENSSL_LIB_PATH,,-L,) $$join(QRENCODE_LIB_PATH,,-L,)
-LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
+LIBS += -lssl -lcrypto -lexecinfo -ldb_cxx$$BDB_LIB_SUFFIX
 # -lgdi32 has to happen after -lcrypto (see  #681)
 windows:LIBS += -lws2_32 -lshlwapi -lmswsock -lole32 -loleaut32 -luuid -lgdi32
-LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX
+LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX -lboost_chrono$$BOOST_THREAD_LIB_SUFFIX
 windows:LIBS += -lboost_chrono$$BOOST_LIB_SUFFIX
 
 contains(RELEASE, 1) {
