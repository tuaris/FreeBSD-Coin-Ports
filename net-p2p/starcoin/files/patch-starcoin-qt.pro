--- starcoin-qt.pro.orig	2014-06-18 16:36:37 UTC
+++ starcoin-qt.pro
@@ -363,12 +363,12 @@ macx:QMAKE_CXXFLAGS_THREAD += -pthread
 INCLUDEPATH += $$BOOST_INCLUDE_PATH $$BDB_INCLUDE_PATH $$OPENSSL_INCLUDE_PATH $$QRENCODE_INCLUDE_PATH
 LIBS += $$join(BOOST_LIB_PATH,,-L,) $$join(BDB_LIB_PATH,,-L,) $$join(OPENSSL_LIB_PATH,,-L,) $$join(QRENCODE_LIB_PATH,,-L,)
 windows:LIBS += -Wl,-Bstatic
-LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
+LIBS += -lssl -lcrypto -lexecinfo -ldb_cxx$$BDB_LIB_SUFFIX
 # -lgdi32 has to happen after -lcrypto (see  #681)
 windows:LIBS += -Wl,-Bdynamic
 windows:LIBS += -lws2_32 -lshlwapi -lmswsock -lole32 -loleaut32 -luuid -lgdi32
 windows:LIBS += -Wl,-Bstatic
-LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX
+LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX -lboost_chrono$$BOOST_THREAD_LIB_SUFFIX
 windows:LIBS += -lboost_chrono$$BOOST_LIB_SUFFIX
 windows:LIBS += -lpthread -Wl,-Bdynamic
 LIBS += -lz
