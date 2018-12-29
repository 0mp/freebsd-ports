--- mk/libraries.mk.orig	2018-12-29 00:22:31 UTC
+++ mk/libraries.mk
@@ -91,6 +91,7 @@ define build-library
     $(1)_PATH := $$(_d)/$$($(1)_NAME).$(SO_EXT)
 
     $$($(1)_PATH): $$($(1)_OBJS) $$(_libs) | $$(_d)/
+	$$(trace-ld) echo _1_ $(CXX) -o $$(abspath $$@) -shared $$(GLOBAL_LDFLAGS) $$($(1)_OBJS) $$($(1)_LDFLAGS) $$($(1)_LDFLAGS_PROPAGATED) $$(foreach lib, $$($(1)_LIBS), $$($$(lib)_LDFLAGS_USE)) $$($(1)_LDFLAGS_UNINSTALLED)
 	$$(trace-ld) $(CXX) -o $$(abspath $$@) -shared $$(GLOBAL_LDFLAGS) $$($(1)_OBJS) $$($(1)_LDFLAGS) $$($(1)_LDFLAGS_PROPAGATED) $$(foreach lib, $$($(1)_LIBS), $$($$(lib)_LDFLAGS_USE)) $$($(1)_LDFLAGS_UNINSTALLED)
 
     ifneq ($(OS), Darwin)
@@ -105,6 +106,7 @@ define build-library
     $$(eval $$(call create-dir, $$($(1)_INSTALL_DIR)))
 
     $$($(1)_INSTALL_PATH): $$($(1)_OBJS) $$(_libs_final) | $(DESTDIR)$$($(1)_INSTALL_DIR)/
+	$$(trace-ld) echo _2_ $(CXX) -o $$@ -shared $$(GLOBAL_LDFLAGS) $$($(1)_OBJS) $$($(1)_LDFLAGS) $$($(1)_LDFLAGS_PROPAGATED) $$(foreach lib, $$($(1)_LIBS), $$($$(lib)_LDFLAGS_USE_INSTALLED))
 	$$(trace-ld) $(CXX) -o $$@ -shared $$(GLOBAL_LDFLAGS) $$($(1)_OBJS) $$($(1)_LDFLAGS) $$($(1)_LDFLAGS_PROPAGATED) $$(foreach lib, $$($(1)_LIBS), $$($$(lib)_LDFLAGS_USE_INSTALLED))
 
     $(1)_LDFLAGS_USE_INSTALLED += -L$$(DESTDIR)$$($(1)_INSTALL_DIR) -l$$(patsubst lib%,%,$$(strip $$($(1)_NAME)))
