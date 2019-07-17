# $FreeBSD: head/net-p2p/bitcoin-utils/Makefile 465909 2018-03-29 17:52:54Z vd $

MASTERDIR=	${.CURDIR}/../zetacoin
PKGNAMESUFFIX=	-utils

COMMENT=	Peer-to-Peer crypto currency with quick transactions (CLI and Utilities)
SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS
OPTIONS_RADIO=
OPTIONS_DEFAULT=	HARDENING

PKGHELP=	${NONEXISTENT}

CONFIGURE_ARGS=	--without-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-miniupnpc \
		--with-utils \
		--disable-wallet

PLIST_FILES=	bin/${PORTNAME}-cli bin/${PORTNAME}-tx

.include "${MASTERDIR}/Makefile"
