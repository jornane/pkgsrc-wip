$NetBSD$

--- chrome/browser/extensions/browser_context_keyed_service_factories.cc.orig	2020-07-08 21:40:34.000000000 +0000
+++ chrome/browser/extensions/browser_context_keyed_service_factories.cc
@@ -53,7 +53,7 @@
 #include "extensions/browser/api/networking_private/networking_private_delegate_factory.h"
 #include "ppapi/buildflags/buildflags.h"
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/input_ime/input_ime_api.h"
 #endif
 
@@ -103,7 +103,7 @@ void EnsureBrowserContextKeyedServiceFac
   extensions::IdentityAPI::GetFactoryInstance();
   extensions::InstallTrackerFactory::GetInstance();
   extensions::InstallVerifierFactory::GetInstance();
-#if defined(OS_CHROMEOS)
+#if defined(OS_CHROMEOS) || defined(OS_BSD)
   extensions::InputImeAPI::GetFactoryInstance();
 #endif
   extensions::LanguageSettingsPrivateDelegateFactory::GetInstance();
