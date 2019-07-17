--- porkcoin-qt.pro.orig	2015-01-08 09:27:59 UTC
+++ porkcoin-qt.pro
@@ -4,7 +4,7 @@ TEMPLATE = app
 TARGET = PorkCoin-qt
 VERSION = 0.7.2
 INCLUDEPATH += src src/json src/qt
-DEFINES += QT_GUI BOOST_THREAD_USE_LIB BOOST_SPIRIT_THREADSAFE BOOST_THREAD_PROVIDES_GENERIC_SHARED_MUTEX_ON_WIN __NO_SYSTEM_INCLUDES
+DEFINES += QT_GUI BOOST_THREAD_USE_LIB BOOST_SPIRIT_THREADSAFE
 CONFIG += no_include_pwd
 CONFIG += thread
 greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
@@ -20,32 +20,6 @@ greaterThan(QT_MAJOR_VERSION, 4) {
 OBJECTS_DIR = build
 MOC_DIR = build
 UI_DIR = build
-BOOST_INCLUDE_PATH=D:\lib\boost_1_55_0\boost_1_55_0
-OPENSSL_INCLUDE_PATH=D:\lib\openssl-1.0.1i\include
-BDB_INCLUDE_PATH=D:\lib\db-4.8.30.NC\build_unix
-MINIUPNPC_INCLUDE_PATH=D:\lib\miniupnp-master
-BOOST_LIB_PATH=C:\Boost\lib
-OPENSSL_LIB_PATH=D:\lib\openssl-0.9.8h\out
-BDB_LIB_PATH=D:\lib\db-4.8.30.NC\build_unix\.libs
-MINIUPNPC_LIB_PATH=D:\lib\miniupnp-master
-
-LIBS += -LD:\lib\openssl-0.9.8h\out
-
-
-LIBS += -LD:\lib\openssl-0.9.8h\out
-LIBS += -LD:\lib\boost_1_55_0\boost_1_55_0\stage\lib
-LIBS += -LD:\lib\db-4.7.25.NC\docs_src\ref\upgrade.3.0
-LIBS +=  -LD:\lib\miniupnpc-1.9\miniupnpc-1.9
-LIBS +=  -L"D:\lib\db-4.8.30.NC\build_unix\.libs"
-LIBS +=  -LD:\lib\db-4.8.30.NC\build_unix
-LIBS +=  -LD:\ecoin\src\src\leveldb
-INCLUDEPATHS += -I"d:\miniupnpc-1.8.20130503"
-INCLUDEPATH += D:\ecoin\src\src\leveldb\include
-INCLUDEPATH += D:\ecoin\src\src\leveldb\helpers\
-
-OBJECTS_DIR = build
-MOC_DIR = build
-UI_DIR = build
 CC=g++  CFLAGS=-x c
 # use: qmake "RELEASE=1"
 contains(RELEASE, 1) {
@@ -447,10 +421,10 @@ macx:QMAKE_CXXFLAGS_THREAD += -pthread
 # Set libraries and includes at end, to use platform-defined defaults if not overridden
 INCLUDEPATH += $$BOOST_INCLUDE_PATH $$BDB_INCLUDE_PATH $$OPENSSL_INCLUDE_PATH $$QRENCODE_INCLUDE_PATH
 LIBS += $$join(BOOST_LIB_PATH,,-L,) $$join(BDB_LIB_PATH,,-L,) $$join(OPENSSL_LIB_PATH,,-L,) $$join(QRENCODE_LIB_PATH,,-L,)
-LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
+LIBS += -lssl -lcrypto -lexecinfo -ldb_cxx$$BDB_LIB_SUFFIX
 # -lgdi32 has to happen after -lcrypto (see  #681)
 windows:LIBS += -lws2_32 -lshlwapi -lmswsock -lole32 -loleaut32 -luuid -lgdi32
-LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX
+LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX -lboost_chrono$$BOOST_LIB_SUFFIX
 windows:LIBS += -lboost_chrono$$BOOST_LIB_SUFFIX
 
 contains(RELEASE, 1) {
