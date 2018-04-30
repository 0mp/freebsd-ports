# $FreeBSD$

PORTNAME=	vm-bhyve
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.8 # XXX WIP
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	churchers@gmail.com
COMMENT=	Management system for bhyve virtual machines

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_DESC=	Install example guest templates

USE_GITHUB=	yes
GH_ACCOUNT=	0mp
GH_TAGNAME=	3786ac553e5cc2b82

NO_ARCH=	yes
NO_BUILD=	yes

post-install-EXAMPLES-off:
	@${RM} -rf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
