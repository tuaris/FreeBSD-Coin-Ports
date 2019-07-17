--- src/serialize.h.orig	2018-04-07 02:55:54 UTC
+++ src/serialize.h
@@ -841,20 +841,6 @@ public:
     iterator insert(iterator it, const char& x=char()) { return vch.insert(it, x); }
     void insert(iterator it, size_type n, const char& x) { vch.insert(it, n, x); }
 
-#ifndef MAC_OSX
-    void insert(iterator it, const_iterator first, const_iterator last)
-    {
-        assert(last - first >= 0);
-        if (it == vch.begin() + nReadPos && (unsigned int)(last - first) <= nReadPos)
-        {
-            // special case for inserting at the front when there's room
-            nReadPos -= (last - first);
-            memcpy(&vch[nReadPos], &first[0], last - first);
-        }
-        else
-            vch.insert(it, first, last);
-    }
-#endif
     void insert(iterator it, std::vector<char>::const_iterator first, std::vector<char>::const_iterator last)
     {
         assert(last - first >= 0);
