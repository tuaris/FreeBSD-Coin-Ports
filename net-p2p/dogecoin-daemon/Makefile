MASTERDIR=	${.CURDIR}/../dogecoin
PKGNAMESUFFIX=	-daemon

COMMENT=	Virtual Peer-to-Peer Currency (Daemon)

SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP ZMQ
OPTIONS_DEFAULT=	HARDENING UPNP WALLET_BDBMODERN ZMQ

USES+=		cpe
CPE_VERSION=	${PORTVERSION:R}

#USERS=		dogecoin
#GROUPS=		dogecoin

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils

PLIST_FILES=	bin/dogecoind
PLIST_FILES+=	share/man/man1/dogecoind.1.gz
PLIST_FILES+=	"@sample etc/dogecoin.conf.sample"

USE_RC_SUBR=	dogecoin
SUB_LIST+=	PORTNAME=dogecoin
SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${FILESDIR}/dogecoin.conf ${STAGEDIR}${PREFIX}/etc/dogecoin.conf.sample

.include "${MASTERDIR}/Makefile"
