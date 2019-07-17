--- src/leveldb/helpers/memenv/memenv.cc.orig	2018-04-07 02:55:54 UTC
+++ src/leveldb/helpers/memenv/memenv.cc
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file. See the AUTHORS file for names of contributors.
 
+#define __STDC_LIMIT_MACROS
+
 #include "helpers/memenv/memenv.h"
 
 #include "leveldb/env.h"
