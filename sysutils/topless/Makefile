PORTNAME=	topless
PORTVERSION=	1.52
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://people.freebsd.org/~daichi/src/

MAINTAINER=	koma2@lovepeers.org
COMMENT=	Display command output on the whole screen like "top"
WWW=		https://people.freebsd.org/~daichi/

LICENSE=	BSD2CLAUSE

USES=		perl5
USE_PERL5=	build
NO_ARCH=	yes

MAKE_ARGS=	MANDIR=${PREFIX}/share/man

PLIST_FILES=	bin/topless share/man/man1/topless.1.gz

.include <bsd.port.mk>
