--- continuum.pro.orig	2014-04-22 06:27:33 UTC
+++ continuum.pro
@@ -107,6 +107,7 @@ contains(BITCOIN_NEED_QT_PLUGINS, 1) {
 
 INCLUDEPATH += src/leveldb/include src/leveldb/helpers
 LIBS += $$PWD/src/leveldb/libleveldb.a $$PWD/src/leveldb/libmemenv.a
+genleveldb.commands = cd $$PWD/src/leveldb && CC=$$QMAKE_CC CXX=$$QMAKE_CXX $(MAKE) OPT=\"$$QMAKE_CXXFLAGS $$QMAKE_CXXFLAGS_RELEASE\" libleveldb.a libmemenv.a
 genleveldb.target = $$PWD/src/leveldb/libleveldb.a
 genleveldb.depends = FORCE
 PRE_TARGETDEPS += $$PWD/src/leveldb/libleveldb.a
@@ -422,7 +423,7 @@ LIBS += $$join(BOOST_LIB_PATH,,-L,) $$jo
 LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
 # -lgdi32 has to happen after -lcrypto (see  #681)
 win32:LIBS += -lws2_32 -lshlwapi -lmswsock -lole32 -loleaut32 -luuid -lgdi32
-LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX
+LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX -lboost_chrono$$BOOST_LIB_SUFFIX
 win32:LIBS += -lboost_chrono$$BOOST_LIB_SUFFIX
 macx:LIBS += -lboost_chrono$$BOOST_LIB_SUFFIX
 
