PORTNAME=	foldingathome
DISTVERSIONPREFIX=	v
DISTVERSION=	8.5.6
CATEGORIES=	biology

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Folding@home client for distributed simulation of protein folding
WWW=		https://foldingathome.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		cbang>0:devel/cbang
LIB_DEPENDS=	libevent.so:devel/libevent \
		libevent_pthreads.so:devel/libevent \
		libexpat.so:textproc/expat2 \
		libleveldb.so:databases/leveldb \
		liblz4.so:archivers/liblz4 \
		libre2.so:devel/re2 \
		libsnappy.so:archivers/snappy \
		libsysinfo.so:devel/libsysinfo \
		libxxhash.so:devel/xxhash \
		libyaml.so:textproc/libyaml \
		libzstd.so:archivers/zstd

USES=		compiler:c++17-lang localbase scons sqlite ssl

USE_GITHUB=	yes
GH_ACCOUNT=	FoldingAtHome
GH_PROJECT=	fah-client-bastet
USE_RC_SUBR=	fahclient

MAKE_ARGS=	cc="${CC}" \
		ccflags="${CCFLAGS}" \
		compiler="${CHOSEN_COMPILER_TYPE:C/gcc/gnu/}" \
		cxx="${CXX}" \
		cxxflags="${CXXFLAGS}" \
		cxxstd="c++17" \
		ldflags="${LDFLAGS}" \
		libpath="/lib" \
		prefix="${STAGEDIR}${PREFIX}" \
		sharedlib=1
MAKE_ENV=	CBANG_HOME=${_CBANG_HOME}

ETCDIR=		${PREFIX}/etc/fahclient
DOCSDIR=	${PREFIX}/share/doc/fahclient

SUB_FILES=	fahclient.8 pkg-message
SUB_LIST=	FAHCLIENT_CONFIG_XML=${_FAHCLIENT_CONFIG_XML} \
		FAHCLIENT_PROGRAM=${_FAHCLIENT_PROGRAM} \
		FAHCLIENT_WORK_DIR=${_FAHCLIENT_WORK_DIR}

USERS=		fahclient
GROUPS=		fahclient

PLIST_SUB=	FAHCLIENT_WORK_DIR=${_FAHCLIENT_WORK_DIR}

_CBANG_HOME=	${LOCALBASE}/libexec/cbang

_FAHCLIENT_CONFIG_XML=	${ETCDIR}/config.xml
_FAHCLIENT_WORK_DIR=	/var/db/fahclient
_FAHCLIENT_PROGRAM=	${PREFIX}/bin/fah-client

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fah-client ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/config.xml.sample \
		${STAGEDIR}${_FAHCLIENT_CONFIG_XML}.sample
	@${MKDIR} ${STAGEDIR}${_FAHCLIENT_WORK_DIR}
	${INSTALL_MAN} ${WRKDIR}/fahclient.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
