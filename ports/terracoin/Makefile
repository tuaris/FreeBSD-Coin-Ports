# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD$

PORTNAME=	terracoin
PORTVERSION=	0.12.1.6
PORTREVISION= 1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p finance

MAINTAINER=	daniel@morante.net
COMMENT=	Peer-to-Peer crypto currency using scrypt as a proof-of-work algorithm

LICENSE=	MIT

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
				libevent.so:devel/libevent

USES+=		autoreconf compiler:c++14-lang gmake libtool pkgconfig shebangfix ssl

BROKEN_armv6=	AtomicPointer not implemented

USE_GITHUB=	yes

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

X11_CONFIGURE_WITH=	gui=qt5
X11_CONFIGURE_ON=	--without-daemon
X11_CONFIGURE_OFF=	--with-daemon
X11_BUILD_DEPENDS=	protoc:devel/protobuf
X11_LIB_DEPENDS=	libprotobuf.so:devel/protobuf
X11_USE=	qt5=core,gui,dbus,widgets,network,webkit,qmake_build,linguisttools,buildtools_build
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

CPPFLAGS+=	 -I${LOCALBASE}/include
LDFLAGS+=	 -L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
				SSL_CFLAGS="-I${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl" \
				OBJCXX="${CXX}" OBJCXXFLAGS="${CXXFLAGS}"

CONFIGURE_ARGS?=	--disable-reduce-exports

QT_BINARY=		${PORTNAME}-qt
CLI_BINARY=		${PORTNAME}-cli
TX_BINARY=		${PORTNAME}-tx
DAEMON=			${PORTNAME}d

PLIST_SUB+=	EXECUTABLE_QT=bin/${QT_BINARY} \
			EXECUTABLE_CLI=bin/${CLI_BINARY} \
			EXECUTABLE_TX=bin/${TX_BINARY} \
			EXECUTABLE_DAEMON=bin/${DAEMON} \
			PORTNAME=${PORTNAME}

.include <bsd.port.options.mk>

SUB_LIST+=	PORTNAME=${PORTNAME}
.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	X11=""
.else
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MX11}
QT_NONSTANDARD=	yes
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

.include <bsd.port.pre.mk>

do-install:
.if ${PORT_OPTIONS:MCLI}
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${PORTNAME}-cli ${STAGEDIR}${PREFIX}/bin/${CLI_BINARY}
.endif

.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/qt/${PORTNAME}-qt ${STAGEDIR}${PREFIX}/bin/${QT_BINARY}
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		-e 's,128,,g' ${WRKSRC}/contrib/debian/${PORTNAME}-qt.desktop
	${INSTALL} ${WRKSRC}/contrib/debian/${PORTNAME}-qt.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}-qt.desktop
	${INSTALL} ${WRKSRC}/src/qt/res/icons/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
.else
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${PORTNAME}-tx ${STAGEDIR}${PREFIX}/bin/${TX_BINARY}
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${PORTNAME}d ${STAGEDIR}${PREFIX}/bin/${DAEMON}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
.endif

.include <bsd.port.mk>
