PORTNAME=	silo
DISTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
CATEGORIES=	www
PKGNAMEPREFIX=	pgsty-

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Object storage comaptible with MinIO and S3
WWW=		https://silo.pgsty.com

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	pgsty
GH_TAGNAME=	RELEASE.2026-08-06T00-00-00Z
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
		LOGFILE="${_LOGFILE}" \
		ROOT_PASSWORD="${_ROOT_PASSWORD}" \
		ROOT_USER="${_ROOT_USER}" \
		USER="${USERS}"

USERS=		${_NAME}
GROUPS=		${_NAME}

PLIST_FILES=	bin/${PORTNAME}

_COMMIT_ID=	3be10fcc1a44f6620ded0bd303461f9d688cca23
_DBDIR=		/var/db/${_NAME}
_LOGFILE=	/var/log/${_NAME}.log
_NAME=		${PORTNAME}
_ROOT_USER=	${_NAME}
_ROOT_PASSWORD=	${_NAME}

.include <bsd.port.mk>
