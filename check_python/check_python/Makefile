# package/check_python/Makefile

include $(TOPDIR)/rules.mk

PKG_NAME:=check_python
PKG_VERSION:=1.0
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/check_python
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Python version caller
  DEPENDS:=+python3
endef

define Package/check_python/description
  calls python3 --version using popen() and prints the result.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./check_python.c $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -o $(PKG_BUILD_DIR)/check_python $(PKG_BUILD_DIR)/check_python.c
endef

define Package/check_python/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/check_python $(1)/usr/bin/
endef

$(eval $(call BuildPackage,check_python))
