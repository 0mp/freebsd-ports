# $FreeBSD$

PORTNAME=	nix
DISTVERSION=    2.1.3
CATEGORIES=	sysutils

MAINTAINER=     0mp@FreeBSD.org
COMMENT=	Purely functional package manager

LICENSE=        LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPDENDS=	liblzma.so:archives/lzmalib \
		libsodium.so:security/libsodium
BUILD_DEPENDS=	bash:shells/bash \
		autoconf-archive>=0:devel/autoconf-archive \
		boost-libs>0:devel/boost-libs \
		xsltproc:textproc/libxslt \
		xmllint:textproc/libxml2 \
		${LOCALBASE}/include/brotli/decode.h:archivers/brotli \
		${LOCALBASE}/include/curl/curl.h:ftp/curl \
		boehm-gc>=0:devel/boehm-gc \
		libsodium>=0:security/libsodium
		# flex>=0:textproc/flex

# bzip2 libbz2 seems to be required as well.
USES=	autoreconf bison:build compiler:c++14-lang gmake pkgconfig ssl sqlite:3 tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	NixOS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-seccomp-sandboxing --enable-gc

pre-build:
	${REINPLACE_CMD} -e 's|@OPENSSL_LIBS@|-L${OPENSSLLIB} -lcrypto|' ${WRKSRC}/Makefile.config.in
	${REINPLACE_CMD} -e 's|@LIBBROTLI_LIBS@|-L${LOCALBASE}/lib -lbrotlienc -lbrotlidec|' ${WRKSRC}/Makefile.config.in

.include <bsd.port.mk>
