--- b1bl3coin-qt.pro.orig	2014-11-01 19:13:35 UTC
+++ b1bl3coin-qt.pro
@@ -477,10 +477,10 @@ macx:QMAKE_CXXFLAGS_THREAD += -pthread
 # Set libraries and includes at end, to use platform-defined defaults if not overridden
 INCLUDEPATH += $$BOOST_INCLUDE_PATH $$BDB_INCLUDE_PATH $$OPENSSL_INCLUDE_PATH $$QRENCODE_INCLUDE_PATH
 LIBS += $$join(BOOST_LIB_PATH,,-L,) $$join(BDB_LIB_PATH,,-L,) $$join(OPENSSL_LIB_PATH,,-L,) $$join(QRENCODE_LIB_PATH,,-L,)
-LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
+LIBS += -lssl -lcrypto -lexecinfo -ldb_cxx$$BDB_LIB_SUFFIX
 # -lgdi32 has to happen after -lcrypto (see  #681)
 win32:LIBS += -lws2_32 -lshlwapi -lmswsock -lole32 -loleaut32 -luuid -lgdi32
-LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX
+LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX -lboost_chrono$$BOOST_THREAD_LIB_SUFFIX
 win32:LIBS += -lboost_chrono$$BOOST_LIB_SUFFIX
 
 contains(RELEASE, 1) {
