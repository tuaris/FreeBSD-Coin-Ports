# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD $

PORTNAME=	dash
PORTVERSION=	0.12.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p finance

MAINTAINER=	daniel@morante.net
COMMENT=	Open sourced, privacy-centric digital currency

LICENSE=	MIT

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
				libevent.so:devel/libevent

USES+=	autoreconf compiler:c++0x gmake libtool pkgconfig shebangfix ssl
SHEBANG_FILES= src/test/*.py
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}
GH_ACCOUNT=	${PORTNAME}pay

OPTIONS_DEFINE=	X11 UPNP WALLET CLI TEST
OPTIONS_SUB=	yes

WALLET_DESC=	Build wallet or P2P server node only
QRCODES_DESC=	Enable QR code display when building graphical interface
CLI_DESC=	Build command line RPC client

OPTIONS_DEFAULT=	X11 WALLET QRCODES
OPTIONS_GROUP=	X11
OPTIONS_GROUP_X11=	QRCODES

UPNP_CONFIGURE_WITH=	miniupnpc
UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_CPPFLAGS=		-I${LOCALBASE}/include
UPNP_LIBS=			-L${LOCALBASE}/lib

X11_CONFIGURE_WITH=	gui
X11_CONFIGURE_ON=	--without-daemon
X11_CONFIGURE_OFF=	--with-daemon
X11_BUILD_DEPENDS=	protoc:devel/protobuf
X11_USE=	qt5=core,gui,dbus,widgets,network,qmake_build,linguisttools,buildtools_build
X11_USES=	desktop-file-utils

WALLET_CONFIGURE_ENABLE=	wallet
WALLET_CXXFLAGS=	-I${BDB_INCLUDE_DIR}
WALLET_LIBS=		-L${BDB_LIB_DIR}
WALLET_USES=	bdb:48

QRCODES_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode
QRCODES_CONFIGURE_WITH=	qrencode

CLI_CONFIGURE_WITH=	cli

TEST_CONFIGURE_ENABLE=	tests
TEST_ALL_TARGET=	check

CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
				SSL_CFLAGS="-I${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl"
CONFIGURE_ENV+= OBJC="${CC}" OBJCFLAGS="${CFLAGS}" OBJCXX="${CXX}" OBJCXXFLAGS="${CXXFLAGS}"
CONFIGURE_ARGS?=	--disable-reduce-exports
MAKE_ENV+=	V=1

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

post-patch:
	${MKDIR} ${WRKSRC}/src/build-aux

do-install:
.if ${PORT_OPTIONS:MCLI}
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${CLI_BINARY} ${STAGEDIR}${PREFIX}/bin/${CLI_BINARY}
.endif

.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/qt/${QT_BINARY} ${STAGEDIR}${PREFIX}/bin/${QT_BINARY}
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		-e 's,128,,g' ${WRKSRC}/contrib/debian/${PORTNAME}-qt.desktop
	${INSTALL} ${WRKSRC}/contrib/debian/${PORTNAME}-qt.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}-qt.desktop
	${INSTALL} ${WRKSRC}/src/qt/res/icons/bitcoin.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
.else
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${DAEMON} ${STAGEDIR}${PREFIX}/bin/${DAEMON}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
.endif

.include <bsd.port.mk>
