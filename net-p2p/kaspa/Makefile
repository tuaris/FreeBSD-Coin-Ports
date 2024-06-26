PORTNAME=       kaspad
DISTVERSIONPREFIX=	v
DISTVERSION=    0.12.17
CATEGORIES=     net-p2p

MAINTAINER=     ports@FreeBSD.org
COMMENT=        Reference full node Kaspa implementation written in Go
WWW=            https://github.com/kaspanet/kaspad/

LICENSE=        ISCL
LICENSE_FILE=   ${WRKSRC}/LICENSE

USES=           go:modules
GO_MODULE=		github.com/kaspanet/kaspad

PLIST_FILES=    bin/kaspad \
				bin/genkeypair \
				bin/kaspactl \
				bin/kaspaminer \
				bin/kaspawallet

.include <bsd.port.mk>
