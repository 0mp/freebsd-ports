# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	ripperx
PORTVERSION=	2.8.0
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK program to rip CD audio tracks and encode them

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtag.so:audio/taglib
RUN_DEPENDS=	cdparanoia:audio/cdparanoia

MAKE_ARGS=	CC=${CXX}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_lib_id3_ID3Tag_Link=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gmake pathfix pkgconfig
USE_GNOME=	gtk20

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} 's/-lstdc++/-lm/' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/^CCLD =/s/=.*/= $$(CXX)/' \
		${WRKSRC}/plugins/Makefile.in ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
