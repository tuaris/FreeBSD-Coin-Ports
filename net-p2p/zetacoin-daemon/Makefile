MASTERDIR=	${.CURDIR}/../zetacoin
PKGNAMESUFFIX=	-daemon

COMMENT=	Virtual Peer-to-Peer Currency (Daemon)

SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP ZMQ
OPTIONS_DEFAULT=	HARDENING UPNP WALLET_BDBMODERN ZMQ

USES+=		cpe
CPE_VERSION=	${PORTVERSION:R}

#USERS=		zetacoin
#GROUPS=		zetacoin

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils

PLIST_FILES=	bin/zetacoind
PLIST_FILES+=	"@sample etc/zetacoin.conf.sample"

USE_RC_SUBR=	zetacoin
SUB_LIST+=	PORTNAME=zetacoin
SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${FILESDIR}/zetacoin.conf ${STAGEDIR}${PREFIX}/etc/zetacoin.conf.sample

.include "${MASTERDIR}/Makefile"
