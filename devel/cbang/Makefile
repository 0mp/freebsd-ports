PORTNAME=	cbang
DISTVERSIONPREFIX=	bastet-v
DISTVERSION=	8.5.6
CATEGORIES=	devel

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C! (cbang) is a library of cross-platform C++ utilities
WWW=		https://cbang.org/

LICENSE=	LGPL21

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		libsysinfo>0:devel/libsysinfo
LIB_DEPENDS=	libevent.so:devel/libevent \
		libexpat.so:textproc/expat2 \
		libleveldb.so:databases/leveldb \
		liblz4.so:archivers/liblz4 \
		libre2.so:devel/re2 \
		libsnappy.so:archivers/snappy \
		libxxhash.so:devel/xxhash \
		libyaml.so:textproc/libyaml \
		libzstd.so:archivers/zstd

USES=		compiler:c++17-lang cpe localbase mysql:client python:test \
		scons sqlite ssl
CPE_VENDOR=	cauldrondevelopment
USE_CXXSTD=	gnu++17
USE_GITHUB=	yes
GH_ACCOUNT=	CauldronDevelopmentLLC
USE_LDCONFIG=	yes

MAKE_ARGS=	cc="${CC}" \
		ccflags="${CCFLAGS}" \
		compiler="${CHOSEN_COMPILER_TYPE:C/gcc/gnu/}" \
		cxx="${CXX}" \
		cxxflags="${CXXFLAGS}" \
		cxxstd="c++17" \
		disable_local="zlib bzip2 lz4 sqlite3 expat libevent re2 libyaml" \
		libpath="/lib" \
		prefix="${STAGEDIR}${PREFIX}" \
		sharedlib=1
# With boost in disable_local, libcbang-boost.a is not built
#		disable_local="zlib bzip2 lz4 sqlite3 expat boost libevent re2 libyaml"
MAKE_ENV=	LIBPATH="${LIBPATH}" \
		LIBRARY_PATH="${LIBPATH}:${LIBPATH}/mysql"

DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${TEST_ARGS}
TEST_WRKSRC=	${WRKSRC}/tests
PLIST_SUB=	VER=${LIBVER}

OPTIONS_DEFINE=		DEBUG DOCS V8
V8_DESC=		Add V8 support
DEBUG_BUILD_DEPENDS=	gnulibiberty>0:devel/gnulibiberty
DEBUG_LIB_DEPENDS=	libbfd.so:devel/binutils
V8_LIB_DEPENDS=		libv8.so:lang/vv8

LIBVER=		1.7.2

_CBANG_HOME=	${PREFIX}/libexec/cbang

post-patch:
	${RM} ${WRKSRC}/config/cbang/__init__.py.orig

pre-configure:
	${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|'	\
		${TEST_WRKSRC}/testHarness

post-install:
	cd ${STAGEDIR}${PREFIX}/lib &&	\
		${LN} -sf libcbang0.so.${LIBVER} libcbang0.so	&&	\
		${LN} -sf libcbang0.so.${LIBVER} libcbang0.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcbang0.so.${LIBVER}
# The config.h file is needed to build dependent ports like
# cad/camotics and biology/foldingathome.
	${INSTALL_DATA} ${WRKSRC}/include/cbang/config.h	\
		${STAGEDIR}${PREFIX}/include/cbang/
	${INSTALL_DATA} ${WRKSRC}/lib/libcbang-boost.a	\
		${STAGEDIR}${PREFIX}/lib
# Assemble CBANG_HOME as expected by dependent ports.
# 1. Create CBANG_HOME.
	${MKDIR} ${STAGEDIR}${_CBANG_HOME}
# 2. Install the config tool there.
	(cd ${WRKSRC} && ${COPYTREE_SHARE} config ${STAGEDIR}${_CBANG_HOME})
# 2. Put links to ${DATDIR}/include and ${PREFIX}/lib into CBANG_HOME.
	${MKDIR} ${STAGEDIR}${_CBANG_HOME}/include
	${RLN} ${STAGEDIR}${PREFIX}/include/cbang ${STAGEDIR}${_CBANG_HOME}/include/cbang
	${RLN} ${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${_CBANG_HOME}/lib

do-test:
	(cd ${TEST_WRKSRC} && ${DO_MAKE_TEST} && ./testHarness)

.include <bsd.port.mk>
