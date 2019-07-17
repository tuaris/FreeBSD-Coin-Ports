--- halfcoin-qt.pro.orig	2015-05-20 09:16:27 UTC
+++ halfcoin-qt.pro
@@ -61,7 +61,7 @@ contains(USE_QRCODE, 1) {
 #  or: qmake "USE_UPNP=0" (disabled by default)
 #  or: qmake "USE_UPNP=-" (not supported)
 # miniupnpc (http://miniupnp.free.fr/files/) must be installed for support
-contains(USE_UPNP, -) {
+contains(USE_UPNP, 1) {
     message(Building without UPNP support)
 } else {
     message(Building with UPNP support)
@@ -408,7 +408,7 @@ LIBS += $$join(BOOST_LIB_PATH,,-L,) $$jo
 LIBS += -lssl -lcrypto -ldb_cxx$$BDB_LIB_SUFFIX
 # -lgdi32 has to happen after -lcrypto (see  #681)
 win32:LIBS += -lws2_32 -lshlwapi -lmswsock -lole32 -loleaut32 -luuid -lgdi32
-LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX
+LIBS += -lboost_system$$BOOST_LIB_SUFFIX -lboost_filesystem$$BOOST_LIB_SUFFIX -lboost_program_options$$BOOST_LIB_SUFFIX -lboost_thread$$BOOST_THREAD_LIB_SUFFIX -lboost_chrono$$BOOST_LIB_SUFFIX
 win32:LIBS += -lboost_chrono$$BOOST_LIB_SUFFIX
 macx:LIBS += -lboost_chrono$$BOOST_LIB_SUFFIX
 
