--- emerald-qt.pro.orig	2014-08-31 15:33:55 UTC
+++ emerald-qt.pro
@@ -18,7 +18,7 @@ CONFIG += no_include_pwd
 #    BDB_LIB_PATH, OPENSSL_INCLUDE_PATH and OPENSSL_LIB_PATH respectively
 # Change following your build environment
 # I am using mingw 4.9.1 to build
-BOOST_LIB_SUFFIX=-mgw49-mt-s-1_55
+#BOOST_LIB_SUFFIX=-mgw49-mt-s-1_55
 BOOST_INCLUDE_PATH=C:/deps/boost_1_55_0
 BOOST_LIB_PATH=C:/deps/boost_1_55_0/stage/lib
 #BOOST_LIB_SUFFIX=-mgw46-mt-sd-1_53
@@ -365,10 +365,10 @@ macx:TARGET = "Emerald-Qt"
 # Set libraries and includes at end, to use platform-defined defaults if not overridden
 INCLUDEPATH += $$BOOST_INCLUDE_PATH $$BDB_INCLUDE_PATH $$OPENSSL_INCLUDE_PATH $$QRENCODE_INCLUDE_PATH
 LIBS += $$join(BOOST_LIB_PATH,,-L,) $$join(BDB_LIB_PATH,,-L,) $$join(OPENSSL_LIB_PATH,,-L,) $$join(QRENCODE_LIB_PATH,,-L,)
-LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX -loleaut32
+LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
 # -lgdi32 has to happen after -lcrypto (see  #681)
 windows:LIBS += -lole32 -luuid -lgdi32 
-LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX
+LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX -lboost_chrono$$BOOST_THREAD_LIB_SUFFIX
 
 contains(RELEASE, 1) {
     !windows:!macx {
