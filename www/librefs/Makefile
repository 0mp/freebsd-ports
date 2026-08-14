PORTNAME=	librefs
DISTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
CATEGORIES=	www

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Fork of MinIO, an S3-compatible object storage server
WWW=		https://librefs.org/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	libreFS
GH_PROJECT=	libreFS
GH_TAGNAME=	RELEASE.2026-05-04T00-42-47Z
USE_RC_SUBR=	${PORTNAME}

GO_MOD_DIST=	github
GO_MODULE=	github.com/minio/minio@${GH_TAGNAME}
GO_BUILDFLAGS=	-ldflags=' \
                -X github.com/minio/minio/cmd.Version=${GH_TAGNAME:C/RELEASE\.//:C|(..)-(..)-(..)Z|\1:\2:\3Z|} \
                -X github.com/minio/minio/cmd.ReleaseTag=${GH_TAGNAME} \
                -X github.com/minio/minio/cmd.CommitID=${_COMMIT_ID} \
                -X github.com/minio/minio/cmd.ShortCommitID=${_COMMIT_ID:C|(............).*|\1|} \
                -X github.com/minio/minio/cmd.GOPATH=${WRKSRC} ${STRIP} -w'

SUB_LIST=	DBDIR=${_DBDIR} \
		GROUP="${GROUPS}" \
		USER="${USERS}"

USERS=		minio
GROUPS=		minio

PLIST_FILES=	bin/${PORTNAME}

_COMMIT_ID=	e194bd779f36fdc08f310d2819d9356f0c1f991b
_DBDIR=		/var/db/minio

.include <bsd.port.mk>
