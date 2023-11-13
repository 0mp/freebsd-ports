--- router/src/harness/src/tls_context.cc.orig	2023-10-12 11:45:01 UTC
+++ router/src/harness/src/tls_context.cc
@@ -242,7 +242,7 @@ static int o11x_version(TlsVersion version) {
       return TLS1_1_VERSION;
     case TlsVersion::TLS_1_2:
       return TLS1_2_VERSION;
-#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 1)
+#ifdef TLS1_3_VERSION
     case TlsVersion::TLS_1_3:
       return TLS1_3_VERSION;
 #endif
@@ -273,9 +273,11 @@ stdx::expected<void, std::error_code> TlsContext::vers
     default:
       // unknown, leave all disabled
       [[fallthrough]];
+#ifdef TLS1_3_VERSION
     case TlsVersion::TLS_1_3:
       opts |= SSL_OP_NO_TLSv1_2;
       [[fallthrough]];
+#endif
     case TlsVersion::TLS_1_2:
       opts |= SSL_OP_NO_TLSv1_1;
       [[fallthrough]];
@@ -323,8 +325,10 @@ TlsVersion TlsContext::min_version() const {
       return TlsVersion::TLS_1_1;
     case TLS1_2_VERSION:
       return TlsVersion::TLS_1_2;
+#ifdef TLS1_3_VERSION
     case TLS1_3_VERSION:
       return TlsVersion::TLS_1_3;
+#endif
     case 0:
       return TlsVersion::AUTO;
     default:
@@ -376,7 +380,8 @@ TlsContext::InfoCallback TlsContext::info_callback() c
 }
 
 int TlsContext::security_level() const {
-#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0)
+#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0) && \
+    !defined(LIBRESSL_VERSION_NUMBER)
   return SSL_CTX_get_security_level(ssl_ctx_.get());
 #else
   return 0;
