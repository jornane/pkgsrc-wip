$NetBSD$

--- chrome/browser/search/search_suggest/search_suggest_service.cc.orig	2020-07-08 21:40:35.000000000 +0000
+++ chrome/browser/search/search_suggest/search_suggest_service.cc
@@ -21,7 +21,7 @@
 #include "components/prefs/scoped_user_pref_update.h"
 #include "components/signin/public/identity_manager/accounts_in_cookie_jar_info.h"
 #include "components/signin/public/identity_manager/identity_manager.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 namespace {
 
