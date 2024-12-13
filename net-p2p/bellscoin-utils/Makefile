MASTERDIR=	${.CURDIR}/../bellscoin
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
		--with-sqlite=no \
		--with-utils

PLIST_FILES=	bin/bells-cli bin/bells-tx \
		share/man/man1/bells-cli.1.gz share/man/man1/bells-tx.1.gz

.include "${MASTERDIR}/Makefile"
