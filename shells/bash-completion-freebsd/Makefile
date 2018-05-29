# $FreeBSD$

PORTNAME=	bash-completion-freebsd
PORTVERSION=	0.2.0
CATEGORIES=	shells

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	FreeBSD-oriented extension to the Bash completion library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/bash-completion/bash_completion.sh:shells/bash-completion

PLIST_FILES=	share/bash-completion/completions/mandoc \
		share/bash-completion/completions/service

NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	0mp

.include <bsd.port.mk>
