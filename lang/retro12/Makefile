# $FreeBSD$

PORTNAME=	retro12
DISTVERSION=	2018.4
CATEGORIES=	lang
MASTER_SITES=	https://forthworks.com/retro/r/
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Clean, elegant, and pragmatic dialect of Forth

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

CONFLICTS_INSTALL=	audio/listener mail/nmh japanese/mh

USES=	ncurses

OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	bin/embedimage \
		bin/extend \
		bin/injectimage-js \
		bin/listener \
		bin/muri \
		bin/repl \
		bin/retro-ri \
		bin/rre \
		bin/unu

PORTDATA=	bin/RETRO12.html \
		glossary.forth \
		ngaImage \
		tests \
		words.tsv

PORTDOCS=	doc \
		literate \
		README.md \
		RELEASE_NOTES.md

PORTEXAMPLES=	example

TEST_TARGET=	test

post-install:
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})
.for f in embedimage extend injectimage-js muri repl rre unu
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/bin/listener ${STAGEDIR}${PREFIX}/bin/listener
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ri ${STAGEDIR}${PREFIX}/bin/retro-ri

do-install-DOCS-on:
	cd ${WRKSRC} &&	${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	cd ${WRKSRC} &&	${COPYTREE_SHARE} "${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
