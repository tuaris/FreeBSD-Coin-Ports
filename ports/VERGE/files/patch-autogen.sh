--- autogen.sh.orig	2018-04-07 02:55:54 UTC
+++ autogen.sh
@@ -1,19 +1,19 @@
 #!/bin/bash
 set -e
-pushd tor
-git checkout -f
-popd
+#pushd tor
+#git checkout -f
+#popd
 
-git submodule update --init --recursive
+#git submodule update --init --recursive
 srcdir="$(dirname $0)"
 cd "$srcdir"
 autoreconf --install --force
 
-pushd tor
-patch --no-backup-if-mismatch -f -p0 < ../tor-am.patch
-patch --no-backup-if-mismatch -f -p0 < ../tor-or-am.patch
-./autogen.sh
-popd
+#pushd tor
+#patch --no-backup-if-mismatch -f -p0 < ../tor-am.patch
+#patch --no-backup-if-mismatch -f -p0 < ../tor-or-am.patch
+#./autogen.sh
+#popd
 
 
 
