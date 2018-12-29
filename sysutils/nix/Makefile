# $FreeBSD$

PORTNAME=	nix
DISTVERSION=    2.1.3
CATEGORIES=	sysutils

MAINTAINER=     0mp@FreeBSD.org
COMMENT=	Purely functional package manager

LICENSE=        LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgc.so:devel/boehm-gc \
		libsodium.so:security/libsodium \
		libcurl.so:ftp/curl \
		libbrotlienc.so:archivers/brotli \
		libbrotlidec.so:archivers/brotli \
		libboost_context.so:devel/boost-libs
BUILD_DEPENDS=	bash:shells/bash \
		autoconf-archive>=0:devel/autoconf-archive \
		xsltproc:textproc/libxslt \
		xmllint:textproc/libxml2 \
		docbook-xsl-ns>=0:textproc/docbook-xsl-ns \
		docbook-xsl>=0:textproc/docbook-xsl

# bzip2 libbz2 seems to be required as well.
USES=	autoreconf bison:build compiler:c++14-lang gmake pkgconfig ssl sqlite:3 tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	NixOS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-seccomp-sandboxing --enable-gc

# Otherwise "environ" is undefined.
MAKE_ARGS=	libutil_ALLOW_UNDEFINED=yes

pre-build:
	${REINPLACE_CMD} \
		-e 's|@OPENSSL_LIBS@|-L${OPENSSLLIB} -lcrypto|' \
		-e 's|@LIBBROTLI_LIBS@|-L${LOCALBASE}/lib -lbrotlienc -lbrotlidec|' \
		-e 's|@LIBCURL_LIBS@|-L${LOCALBASE}/lib -lcurl|' \
		${WRKSRC}/Makefile.config.in

.include <bsd.port.mk>
