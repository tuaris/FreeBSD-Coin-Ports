# $FreeBSD$

MASTERDIR=	${.CURDIR}/../dashpay
PKGNAMESUFFIX=	-daemon
PORTREVISION=	0

COMMENT=	Open sourced, privacy-centric digital currency (Daemon)

SLAVE_PORT=	yes

RUN_DEPENDS+=	dash-cli:net-p2p/dashpay-utils

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP WALLET ZMQ
OPTIONS_DEFAULT=	HARDENING UPNP WALLET ZMQ

USERS=		bitcoin
GROUPS=		bitcoin

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils

PLIST_FILES=	bin/dashd \
				man/man1/dashd.1.gz \
				"@sample ${ETCDIR}.conf.sample"

USE_RC_SUBR=	dashpay
SUB_LIST+=	PORTNAME=${PORTNAME} REALNAME=${REALNAME}
SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${FILESDIR}/dashpay.conf ${STAGEDIR}${PREFIX}/etc/dashpay.conf.sample

.include "${MASTERDIR}/Makefile"
