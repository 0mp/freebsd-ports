# $FreeBSD$

PORTNAME=	nix
DISTVERSION=	2.1.3
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Purely functional package manager

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbrotlienc.so:archivers/brotli \
		libgc.so:devel/boehm-gc \
		libboost_context.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libsodium.so:security/libsodium
BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive \
		bash:shells/bash \
		docbook-xsl-ns>=0:textproc/docbook-xsl-ns \
		xmllint:textproc/libxml2 \
		xsltproc:textproc/libxslt

USES=	autoreconf bison:build compiler:c++14-lang gmake pkgconfig ssl sqlite:3
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	NixOS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-seccomp-sandboxing --enable-gc
# Otherwise "environ" is undefined.
MAKE_ARGS=	libutil_ALLOW_UNDEFINED=yes

STRIP_TARGETS=	bin/nix-instantiate bin/nix-store bin/nix-copy-closure \
		bin/nix bin/nix-channel bin/nix-env bin/nix-build \
		bin/nix-collect-garbage bin/nix-daemon bin/nix-prefetch-url \
		lib/libnixmain.so lib/libnixstore.so lib/libnixexpr.so \
		lib/libnixutil.so libexec/nix/build-remote

post-patch:
	${REINPLACE_CMD} -e 's|@OPENSSL_LIBS@|-L${OPENSSLLIB} -lcrypto|' ${WRKSRC}/Makefile.config.in

post-install:
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} ${STRIP_TARGETS}

.include <bsd.port.mk>
