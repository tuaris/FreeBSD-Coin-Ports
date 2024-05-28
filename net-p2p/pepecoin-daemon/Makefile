MASTERDIR=	${.CURDIR}/../pepecoin
PKGNAMESUFFIX=	-daemon

COMMENT=	Virtual Peer-to-Peer Currency (Daemon)

SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP ZMQ
OPTIONS_DEFAULT=	HARDENING UPNP WALLET_BDBMODERN ZMQ

USES+=		cpe
CPE_VERSION=	${PORTVERSION:R}

#USERS=		pepecoin
#GROUPS=		pepecoin

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils

PLIST_FILES=	bin/pepecoind
PLIST_FILES+=	share/man/man1/pepecoind.1.gz
PLIST_FILES+=	"@sample etc/pepecoin.conf.sample"

USE_RC_SUBR=	pepecoin
SUB_LIST+=	PORTNAME=pepecoin
SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${FILESDIR}/pepecoin.conf ${STAGEDIR}${PREFIX}/etc/pepecoin.conf.sample

.include "${MASTERDIR}/Makefile"
