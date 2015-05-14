# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD$

PORTNAME=	octocoin
PORTVERSION=	1.8.0.0
PORTREVISION=	1
CATEGORIES=	net-p2p finance
MASTER_SITES=	GH

MAINTAINER=	daniel@morante.net
COMMENT=	Peer-to-Peer crypto currency using scrypt as a proof-of-work algorithm

LICENSE=	MIT

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	X11 WALLET UPNP QRCODES
OPTIONS_DEFAULT=	X11 WALLET QRCODES
UPNP_DESC=	Build with UPNP support
WALLET_DESC=	Build the binaries with support to create and manage a wallet.
QRCODES_DESC=	Build with QR code display

AUTOMAKE_ARGS+=	--add-missing
USE_AUTOTOOLS=	aclocal autoheader automake autoconf
CONFIGURE_ENV=	SSL_LIBS="-lssl" CRYPTO_LIBS="-lcrypto" SSL_CFLAGS="-I/usr/include" CRYPTO_CFLAGS="-I/usr/include"

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	9afdcf3
GH_TAGNAME=	9afdcf3

USES=		gmake
USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	5

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
CXXFLAGS+=	-Wno-invalid-offsetof

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=--disable-tests
CONFIGURE_ARGS+=--with-incompatible-bdb

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	X11=""
.else
SUB_LIST+=	PORTNAME=${PORTNAME}
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
PLIST_SUB+=	X11="@comment "
.endif

CLI_BINARY=		${PORTNAME}-cli
DAEMON=		${PORTNAME}d

.if ${PORT_OPTIONS:MX11}
USE_QT4=	corelib gui qmake_build linguist uic moc rcc qtestlib_build
USES+=		desktop-file-utils
QT_BINARY=		${PORTNAME}-qt
BUILD_DEPENDS+=	protoc:${PORTSDIR}/devel/protobuf
CONFIGURE_ARGS+=--with-gui
PLIST_SUB+=	HEADLESS="@comment "
.else
CONFIGURE_ARGS+=--without-gui
PLIST_SUB+=	HEADLESS=""
.endif

.if ${PORT_OPTIONS:MQRCODES}
LIB_DEPENDS+=	libqrencode.so:${PORTSDIR}/graphics/libqrencode
CONFIGURE_ARGS+=--with-qrencode
.else
CONFIGURE_ARGS+=--without-qrencode
.endif

PLIST_SUB+=	EXECUTABLE_QT=bin/${QT_BINARY} \
			EXECUTABLE_CLI=bin/${CLI_BINARY} \
			EXECUTABLE_DAEMON=bin/${DAEMON} \
			PORTNAME=${PORTNAME}

.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
CONFIGURE_ARGS+=--with-miniupnpc
.else
CONFIGURE_ARGS+=--without-miniupnpc
.endif

.if ${PORT_OPTIONS:MWALLET}
CONFIGURE_ARGS+=--enable-wallet
.else
CONFIGURE_ARGS+=--disable-wallet
.endif

.include <bsd.port.pre.mk>

post-patch:
	${MKDIR} ${WRKSRC}/src/build-aux

do-install:
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${CLI_BINARY} ${STAGEDIR}${PREFIX}/bin/${CLI_BINARY}
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${DAEMON} ${STAGEDIR}${PREFIX}/bin/${DAEMON}

.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/qt/${QT_BINARY} ${STAGEDIR}${PREFIX}/bin/${QT_BINARY}
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		-e 's,128,,g' ${FILESDIR}/${PORTNAME}-qt.desktop
	${INSTALL} ${FILESDIR}/${PORTNAME}-qt.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}-qt.desktop
	${INSTALL} ${WRKSRC}/src/qt/res/icons/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
.else
	${INSTALL} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${CP} -p ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf; \
	fi
.endif

.include <bsd.port.post.mk>
