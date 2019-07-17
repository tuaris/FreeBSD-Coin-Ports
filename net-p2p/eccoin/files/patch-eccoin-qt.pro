--- eccoin-qt.pro.orig	2014-12-22 23:06:47 UTC
+++ eccoin-qt.pro
@@ -7,9 +7,10 @@ CONFIG += no_include_pwd
 CONFIG += thread
 CONFIG += static
 CONFIG += widgets
+CONFIG += c++14
 QT += core gui network widgets
 
-QMAKE_CXXFLAGS = -fpermissive -std=c++14
+QMAKE_CXXFLAGS = -fpermissive
 
 greaterThan(QT_MAJOR_VERSION, 4) {
     QT += widgets
@@ -406,10 +407,10 @@ macx:QMAKE_CXXFLAGS_THREAD += -pthread
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
