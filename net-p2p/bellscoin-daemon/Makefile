MASTERDIR=	${.CURDIR}/../bellscoin
PKGNAMESUFFIX=	-daemon

COMMENT=	Virtual Peer-to-Peer Currency (Daemon)

SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP ZMQ
OPTIONS_DEFAULT=	HARDENING UPNP WALLET_BDBMODERN ZMQ

USES+=		cpe
CPE_VERSION=	${PORTVERSION:R}

#USERS=		bellscoin
#GROUPS=		bellscoin

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils

PLIST_FILES=	bin/bellsd
PLIST_FILES+=	share/man/man1/bellsd.1.gz
PLIST_FILES+=	"@sample etc/bells.conf.sample"

USE_RC_SUBR=	bellscoin
SUB_LIST+=	PORTNAME=bells
SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${FILESDIR}/bellscoin.conf ${STAGEDIR}${PREFIX}/etc/bells.conf.sample

.include "${MASTERDIR}/Makefile"
