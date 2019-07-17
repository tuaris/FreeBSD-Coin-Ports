# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD$

PORTNAME=	legendarycoin
PORTVERSION=	1.0.4.3
PORTREVISION=	2
CATEGORIES=	net-p2p finance
MASTER_SITES=	GH

MAINTAINER=	daniel@morante.net
COMMENT=	Peer-to-Peer crypto currency using scrypt as a proof-of-work algorithm

LICENSE=	MIT

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	X11 UPNP QRCODES ZEROFEE
OPTIONS_DEFAULT=	X11 QRCODES
UPNP_DESC=	Build with UPNP support
QRCODES_DESC=	Build with QR code display
ZEROFEE_DESC=	Zero Transaction Fee Hack

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	07fa736
GH_TAGNAME=	07fa736

USES=		gmake bdb:48
USE_OPENSSL=	yes

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
LIBS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}
CXXFLAGS+=	-Wno-invalid-offsetof

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	X11=""
.else
SUB_LIST+=	PORTNAME=${PORTNAME}
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MX11}
USE_QT4=	corelib gui qmake_build linguist uic moc rcc
BINARY=		${PORTNAME}-qt
PLIST_SUB+=	HEADLESS="@comment "
.else
BINARY=		${PORTNAME}d
MAKE_ARGS+=	-C ${WRKSRC}/src
PLIST_SUB+=	HEADLESS=""
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

.if ${PORT_OPTIONS:MZEROFEE}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-zero-fee.patch
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1100000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-endian
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/src/makefile.bsd
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
		QMAKE_LIBDIR+=${BDB_LIB_DIR} ${PORTNAME}-qt.pro
.endif

do-install:
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} -s ${WRKSRC}/${BINARY} ${STAGEDIR}${PREFIX}/bin/${BINARY}
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		-e 's,bitcoin,${PORTNAME},g' \
		-e 's,Bitcoin,LegendaryCoin,g' \
		-e 's,128,,g' ${WRKSRC}/contrib/debian/bitcoin-qt.desktop
	${INSTALL} ${WRKSRC}/contrib/debian/bitcoin-qt.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}-qt.desktop
	${INSTALL} ${WRKSRC}/src/qt/res/icons/LegendaryCoin.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.else
	${INSTALL_PROGRAM} -s ${WRKSRC}/src/${GH_PROJECT}d ${STAGEDIR}${PREFIX}/bin/${BINARY}
	${INSTALL} ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${CP} -p ${FILESDIR}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf; \
	fi
.endif

.include <bsd.port.post.mk>
