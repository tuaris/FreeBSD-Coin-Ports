# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD$

PORTNAME=	sentaro
PORTVERSION=	1.0.0.0
CATEGORIES=	net-p2p finance
MASTER_SITES=	GH

MAINTAINER=	daniel@morante.net
COMMENT=	Peer-to-Peer crypto currency of with PoS

LICENSE=	MIT

BROKEN=         fails to build with latest tree and platforms
IGNORE=			Depends on missing libexecinfo and secp256k1

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
				libsecp256k1.so:${PORTSDIR}/security/secp256k1

BUILD_DEPENDS+=   ${LOCALBASE}/include/secp256k1.h:${PORTSDIR}/security/secp256k1

OPTIONS_DEFINE=	X11 UPNP QRCODES STATIC
OPTIONS_DEFAULT=	X11 QRCODES
UPNP_DESC=	Build with UPNP support
QRCODES_DESC=	Build with QR code display

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}coin
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	43f78e2
GH_TAGNAME=	43f78e2

USES=		gmake
USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	48

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
CXXFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
CXXFLAGS+=	-Wno-invalid-offsetof

.include <bsd.port.options.mk>

SUB_LIST+=	PORTNAME=${PORTNAME}
.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	X11=""
SUB_FILES=	${PORTNAME}-qt.desktop
.else
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MX11}
USE_QT5=	core gui dbus widgets network qmake_build linguisttools buildtools_build
BINARY=		${PORTNAME}-qt
PLIST_SUB+=	HEADLESS="@comment "
.else
BINARY=		${PORTNAME}d
MAKE_ARGS+=	-C ${WRKSRC}/src
PLIST_SUB+=	HEADLESS=""
.endif

.if ${PORT_OPTIONS:MSTATIC}
MAKE_ARGS+=	STATIC=1
.endif

.if ${PORT_OPTIONS:MQRCODES}
LIB_DEPENDS+=	libqrencode.so:${PORTSDIR}/graphics/libqrencode
QMAKE_USE_QRCODE=1
.else
QMAKE_USE_QRCODE=0
.endif

PLIST_SUB+=	EXECUTABLE="bin/${BINARY}" \
			PORTNAME=${PORTNAME}

.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
QMAKE_USE_UPNP=	1
.else
QMAKE_USE_UPNP=	-
.endif



.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
#EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-smessage.patch
.endif

post-extract:
	@${RM} -f ${WRKSRC}/build/*.o

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/makefile.bsd
	@${CHMOD} +x ${WRKSRC}/src/leveldb/build_detect_platform
	@${MKDIR} -p ${WRKSRC}/src/obj/crypto
.if !${PORT_OPTIONS:MX11}
	@cd ${WRKSRC}/src && ${CP} -p makefile.bsd Makefile
	@${REINPLACE_CMD} \
		-e 's|^USE_UPNP.*$$|USE_UPNP=${QMAKE_USE_UPNP}|' \
		-e 's|-l pthread|${PTHREAD_LIBS}|g' \
		-e 's:-l dl::' \
		${WRKSRC}/src/Makefile
.endif

do-configure:
.if ${PORT_OPTIONS:MX11}
	cd ${WRKSRC} && ${SETENV} ${QMAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS} USE_UPNP=${QMAKE_USE_UPNP} USE_QRCODE=${QMAKE_USE_QRCODE} \
		QMAKE_LRELEASE=lrelease-qt4 PREFIX=${PREFIX} INCLUDEPATH=${BDB_INCLUDE_DIR} \
		QMAKE_LIBDIR+=${BDB_LIB_DIR} ${PORTNAME}.pro
.endif

do-install:
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} -s ${WRKSRC}/${BINARY} ${STAGEDIR}${PREFIX}/bin/${BINARY}
	${INSTALL} ${WRKDIR}/${PORTNAME}-qt.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}-qt.desktop
	${INSTALL} ${WRKSRC}/src/qt/res/icons/sentaro_logo_64x64.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.else
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${BINARY} ${STAGEDIR}${PREFIX}/bin/${BINARY}
	${INSTALL} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${CP} -p ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf; \
	fi
.endif

.include <bsd.port.post.mk>
