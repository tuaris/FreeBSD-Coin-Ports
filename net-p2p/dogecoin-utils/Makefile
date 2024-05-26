MASTERDIR=	${.CURDIR}/../dogecoin
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

PLIST_FILES=	bin/dogecoin-cli bin/dogecoin-tx \
		share/man/man1/dogecoin-cli.1.gz share/man/man1/dogecoin-tx.1.gz \
		bin/dogecoin-wallet \
		share/man/man1/dogecoin-wallet.1.gz

.include "${MASTERDIR}/Makefile"
