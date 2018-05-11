# $FreeBSD$

PORTNAME=	mtm
DISTVERSION=	g20180507
CATEGORIES=	sysutils

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Terminal multiplexer focued on simplicity, compatibility and stability

LICENSE=	GPLv3+

USES=		ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	deadpixi
GH_TAGNAME=	b861104

PLIST_FILES=	bin/mtm \
		man/man1/mtm.1.gz

MAKE_ARGS+=	LIBS='-lutil -lncursesw'

PORTDATA=	mtm.ti

post-install:
	@${MKDIR} -p ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mtm.ti ${STAGEDIR}${DATADIR}/mtm.ti
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mtm

.include <bsd.port.mk>
