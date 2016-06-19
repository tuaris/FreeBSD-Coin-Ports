# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD$

PORTNAME=	digitalcoin
PORTVERSION=	3.0.1.0
PORTREVISION=	1
CATEGORIES=	net-p2p finance

MAINTAINER=	myst3r10n@rocketmail.com
COMMENT=	Decentralized peer-to-peer multi-algorithm cryptographic currency

LICENSE=	MIT

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs

USES=	autoreconf compiler:c++0x gmake libtool pkgconfig
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	DGCDev
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	c8b3697
GH_TAGNAME=	c8b3697

#WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME}

OPTIONS_DEFINE=	X11 UPNP WALLET CLI TEST
OPTIONS_SUB=	yes

WALLET_DESC=	Build wallet or P2P server node only
QRCODES_DESC=	Enable QR code display when building graphical interface
CLI_DESC=	Build command line RPC client

OPTIONS_DEFAULT=	X11 WALLET QRCODES
OPTIONS_GROUP=	X11
OPTIONS_GROUP_X11=	QRCODES

UPNP_CONFIGURE_WITH=	miniupnpc
UPNP_LIB_DEPENDS=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
UPNP_LIBS=	-L${LOCALBASE}/lib

X11_CONFIGURE_WITH=	gui
X11_CONFIGURE_ON=	--without-daemon
X11_CONFIGURE_OFF=	--with-daemon
X11_BUILD_DEPENDS=	protoc:${PORTSDIR}/devel/protobuf
X11_USE=	qt4=corelib,gui,qmake_build,linguist,uic,moc,rcc,qtestlib_build
X11_USES=	desktop-file-utils

WALLET_CONFIGURE_ENABLE=	wallet
WALLET_CXXFLAGS=	-I${BDB_INCLUDE_DIR}
WALLET_LIBS=		-L${BDB_LIB_DIR}
WALLET_USE=	bdb=48

QRCODES_LIB_DEPENDS=	libqrencode.so:${PORTSDIR}/graphics/libqrencode
QRCODES_CONFIGURE_WITH=	qrencode

CLI_CONFIGURE_WITH=	cli

TEST_CONFIGURE_ENABLE=	tests
TEST_ALL_TARGET=	check

CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
				SSL_CFLAGS="-I${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl"
CONFIGURE_ARGS?=	--disable-reduce-exports
MAKE_ENV+=	V=1

USE_OPENSSL=	yes

CXXFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-Wno-invalid-offsetof

QT_BINARY=		${PORTNAME}-qt
CLI_BINARY=		${PORTNAME}-cli
DAEMON=		${PORTNAME}d

PLIST_SUB+=	EXECUTABLE_QT=bin/${QT_BINARY} \
			EXECUTABLE_CLI=bin/${CLI_BINARY} \
			EXECUTABLE_DAEMON=bin/${DAEMON} \
			PORTNAME=${PORTNAME}

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MX11) && !empty(PORT_OPTIONS:MQRCODES)
BROKEN=	QRCODES requires X11 support.  Run 'make config' again!
.endif

# tests will currently fail
.if ${PORT_OPTIONS:MTEST}
BROKEN=	automated testing fails
.endif

.if ! ${PORT_OPTIONS:MX11}
USE_RC_SUBR=	${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
.endif

do-install:
.if ${PORT_OPTIONS:MCLI}
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${CLI_BINARY} ${STAGEDIR}${PREFIX}/bin/${CLI_BINARY}
.endif

.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/qt/${QT_BINARY} ${STAGEDIR}${PREFIX}/bin/${QT_BINARY}
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		-e 's,bitcoin,${PORTNAME},g' \
		-e 's,Bitcoin,Digitalcoin,g' \
		-e 's,128,,g' ${WRKSRC}/contrib/debian/${PORTNAME}-qt.desktop
	${INSTALL} ${WRKSRC}/contrib/debian/${PORTNAME}-qt.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}-qt.desktop
	${INSTALL} ${WRKSRC}/src/qt/res/icons/bitcoin.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
.else
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${DAEMON} ${STAGEDIR}${PREFIX}/bin/${DAEMON}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
.endif

.include <bsd.port.mk>
