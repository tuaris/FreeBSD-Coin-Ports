# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD$

PORTNAME=	lynxcore
PORTVERSION=	0.14.99.0
PORTREVISION=	1
CATEGORIES=	net-p2p finance

MAINTAINER=	daniel@morante.net
COMMENT=	Peer-to-Peer crypto currency using scrypt as a proof-of-work algorithm

LICENSE=	MIT

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs\
				libevent.so:devel/libevent

USES+=		autoreconf gmake libtool pkgconfig ssl

BROKEN_armv6=	AtomicPointer not implemented

USE_GITHUB=	yes
GH_ACCOUNT=	doh9Xiet7weesh9va9th
GH_PROJECT=	lynx
GH_COMMIT=	21441a1
GH_TAGNAME=	21441a1

OPTIONS_DEFINE=	X11 UPNP WALLET CLI TEST
OPTIONS_SUB=	yes

WALLET_DESC=	Build wallet or P2P server node only
QRCODES_DESC=	Enable QR code display when building graphical interface
CLI_DESC=	Build command line RPC client

OPTIONS_DEFAULT=	X11 WALLET QRCODES
OPTIONS_GROUP=		X11
OPTIONS_GROUP_X11=	QRCODES

UPNP_CONFIGURE_WITH=	miniupnpc
UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_CPPFLAGS=		-I${LOCALBASE}/include
UPNP_LIBS=			-L${LOCALBASE}/lib

X11_CONFIGURE_WITH=	gui=qt5
X11_CONFIGURE_ON=	--without-daemon
X11_CONFIGURE_OFF=	--with-daemon
X11_BUILD_DEPENDS=	protoc:devel/protobuf
X11_LIB_DEPENDS=	libprotobuf.so:devel/protobuf
X11_USE=	qt5=core,gui,dbus,widgets,network,qmake_build,linguisttools,buildtools_build
X11_USES=	desktop-file-utils

WALLET_CONFIGURE_ENABLE=	wallet
WALLET_CXXFLAGS=	-I${BDB_INCLUDE_DIR}
WALLET_LIBS=		-L${BDB_LIB_DIR}
WALLET_USES=		bdb:48

QRCODES_IMPLIES=	X11
QRCODES_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode
QRCODES_CONFIGURE_WITH=	qrencode

CLI_CONFIGURE_WITH=	cli

TEST_CONFIGURE_ENABLE=	tests
TEST_ALL_TARGET=	check

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
				SSL_CFLAGS="-I${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl"
CONFIGURE_ENV+= OBJC="${CC}" OBJCFLAGS="${CFLAGS}" OBJCXX="${CXX}" OBJCXXFLAGS="${CXXFLAGS}"

CONFIGURE_ARGS?=	--disable-reduce-exports

QT_BINARY=		${GH_PROJECT}-qt
CLI_BINARY=		${GH_PROJECT}-cli
TX_BINARY=		${GH_PROJECT}-tx
DAEMON=			${GH_PROJECT}d

PLIST_SUB+=	EXECUTABLE_QT=bin/${QT_BINARY} \
			EXECUTABLE_CLI=bin/${CLI_BINARY} \
			EXECUTABLE_TX=bin/${TX_BINARY} \
			EXECUTABLE_DAEMON=bin/${DAEMON} \
			PORTNAME=${GH_PROJECT}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
QT_NONSTANDARD=	yes
.endif

# tests will currently fail
.if ${PORT_OPTIONS:MTEST}
BROKEN=	automated testing fails
.endif

.if ! ${PORT_OPTIONS:MX11}
USE_RC_SUBR=	${GH_PROJECT}
SUB_LIST+=	PORTNAME=${GH_PROJECT}
SUB_FILES=	pkg-message
.endif

do-install:
.if ${PORT_OPTIONS:MCLI}
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${GH_PROJECT}-cli ${STAGEDIR}${PREFIX}/bin/${CLI_BINARY}
.endif

.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/qt/${QT_BINARY} ${STAGEDIR}${PREFIX}/bin/${QT_BINARY}
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		-e 's,bitcoin,lynx,g' \
		-e 's,Bitcoin,Lynx,g' \
		-e 's,xpm,png,g' \
		-e 's,128,,g' ${WRKSRC}/contrib/debian/bitcoin-qt.desktop		
	${INSTALL} ${WRKSRC}/contrib/debian/bitcoin-qt.desktop ${STAGEDIR}${PREFIX}/share/applications/${GH_PROJECT}-qt.desktop
	${INSTALL} ${WRKSRC}/src/qt/res/icons/bitcoin.png ${STAGEDIR}${PREFIX}/share/pixmaps/${GH_PROJECT}.png
.else
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${GH_PROJECT}-tx ${STAGEDIR}${PREFIX}/bin/${TX_BINARY}
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${GH_PROJECT}d ${STAGEDIR}${PREFIX}/bin/${DAEMON}
	${INSTALL_DATA} ${FILESDIR}/${GH_PROJECT}.conf.sample ${STAGEDIR}${PREFIX}/etc/${GH_PROJECT}.conf.sample
.endif

.include <bsd.port.mk>
