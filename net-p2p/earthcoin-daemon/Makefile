MASTERDIR=	${.CURDIR}/../earthcoin
PKGNAMESUFFIX=	-daemon

COMMENT=	Virtual Peer-to-Peer Currency (Daemon)

SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP ZMQ
OPTIONS_DEFAULT=	HARDENING UPNP WALLET_BDBMODERN ZMQ

USES+=		cpe
CPE_VERSION=	${PORTVERSION:R}

#USERS=		earthcoin
#GROUPS=		earthcoin

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils

PLIST_FILES=	bin/earthcoind
PLIST_FILES+=	share/man/man1/earthcoind.1.gz
PLIST_FILES+=	"@sample etc/earthcoin.conf.sample"

USE_RC_SUBR=	earthcoin
SUB_LIST+=	PORTNAME=earthcoin
SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${FILESDIR}/earthcoin.conf ${STAGEDIR}${PREFIX}/etc/earthcoin.conf.sample

.include "${MASTERDIR}/Makefile"
