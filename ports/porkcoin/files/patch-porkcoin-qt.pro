--- porkcoin-qt.pro.orig	2015-01-04 07:06:38 UTC
+++ porkcoin-qt.pro
@@ -1,63 +1,15 @@
-QT       += core gui network widgets
-QMAKE_LFLAGS=-static
 TEMPLATE = app
 TARGET = PorkCoin-qt
+macx:TARGET = "PorkCoin-Qt"
 VERSION = 0.7.2
 INCLUDEPATH += src src/json src/qt
-DEFINES += QT_GUI BOOST_THREAD_USE_LIB BOOST_SPIRIT_THREADSAFE BOOST_THREAD_PROVIDES_GENERIC_SHARED_MUTEX_ON_WIN __NO_SYSTEM_INCLUDES
+QT += core gui network
+greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
+DEFINES += QT_GUI BOOST_THREAD_USE_LIB BOOST_SPIRIT_THREADSAFE
 CONFIG += no_include_pwd
 CONFIG += thread
-greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
-lessThan(QT_MAJOR_VERSION, 5): CONFIG += static
 QMAKE_CXXFLAGS = -fpermissive
 
-greaterThan(QT_MAJOR_VERSION, 4) {
-    QT += widgets
-    DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
-}
-
-
-OBJECTS_DIR = build
-MOC_DIR = build
-UI_DIR = build
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
-CC=g++  CFLAGS=-x c
-# use: qmake "RELEASE=1"
-contains(RELEASE, 1) {
-    # Mac: compile for maximum compatibility (10.5, 32-bit)
-    macx:QMAKE_CXXFLAGS += -mmacosx-version-min=10.5 -arch i386 -isysroot /Developer/SDKs/MacOSX10.5.sdk
-
-    !windows:!macx {
-        # Linux: static link
-        LIBS += -Wl,-Bstatic
-    }
-}
-
 # for boost 1.37, add -mt to the boost libraries
 # use: qmake BOOST_LIB_SUFFIX=-mt
 # for boost thread win32 with _win32 sufix
@@ -67,18 +19,34 @@ contains(RELEASE, 1) {
 # Dependency library locations can be customized with:
 #    BOOST_INCLUDE_PATH, BOOST_LIB_PATH, BDB_INCLUDE_PATH,
 #    BDB_LIB_PATH, OPENSSL_INCLUDE_PATH and OPENSSL_LIB_PATH respectively
-
+win32 {
+BOOST_LIB_SUFFIX=-mgw48-mt-s-1_55
+BOOST_INCLUDE_PATH=C:/deps/boost_1_55_0
+BOOST_LIB_PATH=C:/deps/boost_1_55_0/stage/lib
+BDB_INCLUDE_PATH=C:/deps/db-4.8.30.NC/build_unix
+BDB_LIB_PATH=C:/deps/db-4.8.30.NC/build_unix
+OPENSSL_INCLUDE_PATH=C:/deps/openssl-1.0.1g/include
+OPENSSL_LIB_PATH=C:/deps/openssl-1.0.1g
+MINIUPNPC_INCLUDE_PATH=C:/deps/
+MINIUPNPC_LIB_PATH=C:/deps/miniupnpc
+}
 
 OBJECTS_DIR = build
 MOC_DIR = build
 UI_DIR = build
+CC=g++  CFLAGS=-x c
 
 # use: qmake "RELEASE=1"
 contains(RELEASE, 1) {
     # Mac: compile for maximum compatibility (10.5, 32-bit)
-    macx:QMAKE_CXXFLAGS += -mmacosx-version-min=10.5 -arch i386 -isysroot /Developer/SDKs/MacOSX10.5.sdk
-    macx:QMAKE_CFLAGS += -mmacosx-version-min=10.5 -arch i386 -isysroot /Developer/SDKs/MacOSX10.5.sdk
-    macx:QMAKE_OBJECTIVE_CFLAGS += -mmacosx-version-min=10.5 -arch i386 -isysroot /Developer/SDKs/MacOSX10.5.sdk
+    #macx:QMAKE_CXXFLAGS += -mmacosx-version-min=10.5 -arch i386 -isysroot /Developer/SDKs/MacOSX10.5.sdk
+    #macx:QMAKE_CFLAGS += -mmacosx-version-min=10.5 -arch i386 -isysroot /Developer/SDKs/MacOSX10.5.sdk
+    #macx:QMAKE_OBJECTIVE_CFLAGS += -mmacosx-version-min=10.5 -arch i386 -isysroot /Developer/SDKs/MacOSX10.5.sdk
+
+    # Mac: compile for maximum compatibility (10.7, 64-bit)
+    macx:QMAKE_CXXFLAGS += -mmacosx-version-min=10.7 -isysroot /Developer/SDKs/MacOSX10.7.sdk
+    macx:QMAKE_CFLAGS += -mmacosx-version-min=10.7 -isysroot /Developer/SDKs/MacOSX10.7.sdk
+    macx:QMAKE_LFLAGS += -mmacosx-version-min=10.7 -isysroot /Developer/SDKs/MacOSX10.7.sdk
 
     !win32:!macx {
         # Linux: static link and extra security (see: https://wiki.debian.org/Hardening)
@@ -99,6 +67,8 @@ QMAKE_CXXFLAGS *= -D_FORTIFY_SOURCE=2
 win32:QMAKE_LFLAGS *= -Wl,--dynamicbase -Wl,--nxcompat
 # on Windows: enable GCC large address aware linker flag
 win32:QMAKE_LFLAGS *= -Wl,--large-address-aware
+# i686-w64-mingw32
+win32:QMAKE_LFLAGS *= -static-libgcc -static-libstdc++
 
 # use: qmake "USE_QRCODE=1"
 # libqrencode (http://fukuchi.org/works/qrencode/index.en.html) must be installed for support
@@ -148,6 +118,9 @@ contains(BITCOIN_NEED_QT_PLUGINS, 1) {
     DEFINES += BITCOIN_NEED_QT_PLUGINS
     QTPLUGIN += qcncodecs qjpcodecs qtwcodecs qkrcodecs qtaccessiblewidgets
 }
+
+INCLUDEPATH += src/leveldb/include src/leveldb/helpers
+LIBS += $$PWD/src/leveldb/libleveldb.a $$PWD/src/leveldb/libmemenv.a
 !win32 {
     # we use QMAKE_CXXFLAGS_RELEASE even without RELEASE=1 because we use RELEASE to indicate linking preferences not -O preferences
     genleveldb.commands = cd $$PWD/src/leveldb && CC=$$QMAKE_CC CXX=$$QMAKE_CXX $(MAKE) OPT=\"$$QMAKE_CXXFLAGS $$QMAKE_CXXFLAGS_RELEASE\" libleveldb.a libmemenv.a
@@ -157,8 +130,19 @@ contains(BITCOIN_NEED_QT_PLUGINS, 1) {
         QMAKE_RANLIB = $$replace(QMAKE_STRIP, strip, ranlib)
     }
     LIBS += -lshlwapi
-    genleveldb.commands = cd $$PWD/src/leveldb && CC=$$QMAKE_CC CXX=$$QMAKE_CXX TARGET_OS=OS_WINDOWS_CROSSCOMPILE $(MAKE) OPT=\"$$QMAKE_CXXFLAGS $$QMAKE_CXXFLAGS_RELEASE\" libleveldb.a libmemenv.a && $$QMAKE_RANLIB $$PWD/src/leveldb/libleveldb.a && $$QMAKE_RANLIB $$PWD/src/leveldb/libmemenv.a
+    #genleveldb.commands = cd $$PWD/src/leveldb && CC=$$QMAKE_CC CXX=$$QMAKE_CXX TARGET_OS=OS_WINDOWS_CROSSCOMPILE $(MAKE) OPT=\"$$QMAKE_CXXFLAGS $$QMAKE_CXXFLAGS_RELEASE\" libleveldb.a libmemenv.a && $$QMAKE_RANLIB $$PWD/src/leveldb/libleveldb.a && $$QMAKE_RANLIB $$PWD/src/leveldb/libmemenv.a
 }
+genleveldb.target = $$PWD/src/leveldb/libleveldb.a
+genleveldb.depends = FORCE
+PRE_TARGETDEPS += $$PWD/src/leveldb/libleveldb.a
+QMAKE_EXTRA_TARGETS += genleveldb
+# Gross ugly hack that depends on qmake internals, unfortunately there is no other way to do it.
+QMAKE_CLEAN += $$PWD/src/leveldb/libleveldb.a; cd $$PWD/src/leveldb ; $(MAKE) clean
+
+
+QMAKE_CXXFLAGS += -msse2
+QMAKE_CFLAGS += -msse2
+QMAKE_CXXFLAGS_WARN_ON = -fdiagnostics-show-option -Wall -Wextra -Wformat -Wformat-security -Wno-unused-parameter -Wstack-protector
 
 # Input
 DEPENDPATH += src src/json src/qt
@@ -447,10 +431,10 @@ macx:QMAKE_CXXFLAGS_THREAD += -pthread
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
