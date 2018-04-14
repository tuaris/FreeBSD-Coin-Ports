--- src/serialize.h.orig	2016-03-24 15:19:15 UTC
+++ src/serialize.h
@@ -802,19 +802,6 @@ public:
     iterator insert(iterator it, const char& x=char()) { return vch.insert(it, x); }
     void insert(iterator it, size_type n, const char& x) { vch.insert(it, n, x); }
 
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
-
     void insert(iterator it, std::vector<char>::const_iterator first, std::vector<char>::const_iterator last)
     {
         assert(last - first >= 0);
@@ -846,6 +833,7 @@ public:
     iterator erase(iterator it)
     {
         if (it == vch.begin() + nReadPos)
+
         {
             // special case for erasing from the front
             if (++nReadPos >= vch.size())
