MASTERDIR=	${.CURDIR}/../earthcoin
PKGNAMESUFFIX=	-utils

COMMENT=	Virtual Peer-to-Peer Currency (CLI and Utilities)
SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS ZMQ
OPTIONS_RADIO=

PKGHELP=	${NONEXISTENT}

CONFIGURE_ARGS=	--without-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-miniupnpc \
		--with-utils \
		--disable-wallet

PLIST_FILES=	bin/earthcoin-cli bin/earthcoin-tx \
		share/man/man1/earthcoin-cli.1.gz share/man/man1/earthcoin-tx.1.gz

.include "${MASTERDIR}/Makefile"
