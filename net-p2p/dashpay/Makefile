# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD$

PORTNAME=	dashpay
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.1.1
CATEGORIES=	net-p2p finance

MAINTAINER=	daniel@morante.net
COMMENT=	Open sourced, privacy-centric digital currency

LICENSE=	MIT

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
				libevent.so:devel/libevent \
				libgmp.so:math/gmp

USES+=	autoreconf compiler:c++11-lib gmake libtool pkgconfig shebangfix ssl

REALNAME=	${PORTNAME:S/pay//}

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME} codablock:bls rust-lang-nursery:lbt
GH_PROJECT=	${REALNAME} bls-signatures:bls libbacktrace:lbt
GH_TAGNAME=	v20181101:bls f4d02bb:lbt
GNU_CONFIGURE=	yes

SLAVE_PORT?=	no

PLIST_FILES?=	bin/dash-qt man/man1/dash-qt.1.gz \
				share/applications/dash-qt.desktop share/pixmaps/dashpay128.png

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"
USES+=		desktop-file-utils qt:5
USE_QT=		core gui network widgets \
		buildtools_build linguisttools_build qmake_build

BUILD_DEPENDS+=	protoc:devel/protobuf				
LIB_DEPENDS+=	libprotobuf.so:devel/protobuf

TESTS_USE=		QT=testlib
TESTS_PLIST_FILES=	bin/test_dash-qt \
					bin/test_dash
.endif

OPTIONS_DEFINE?=	DBUS DEBUG HARDENING QRCODES TESTS UPNP WALLET ZMQ
OPTIONS_DEFAULT?=	DBUS HARDENING QRCODES UPNP WALLET ZMQ
OPTIONS_SUB=	yes

HARDENING_DESC=	Attempt to harden binaries (PIE for ASLR, NX Stack)
QRCODES_DESC=	Display QR Codes
TESTS_DESC=	Build test binary and unit tests
WALLET_DESC=	Wallet Management Support
ZMQ_DESC=	Block and transaction broadcasting with ZeroMQ

DBUS_CONFIGURE_WITH=	dbus
DBUS_USE=		QT=dbus

DEBUG_CONFIGURE_ENABLE=		debug
DEBUG_INSTALL_TARGET_OFF=	install-strip

HARDENING_CONFIGURE_ENABLE=	hardening

TESTS_CONFIGURE_ENABLE=	tests bench
.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "yes"
TESTS_PLIST_FILES=	bin/test_dsh
.endif
TESTS_PLIST_FILES+=	bin/bench_dash

UPNP_CONFIGURE_WITH=	miniupnpc
UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc
UPNP_CPPFLAGS=		-I${LOCALBASE}/include
UPNP_LIBS=		-L${LOCALBASE}/lib

QRCODES_CONFIGURE_WITH=	qrencode
QRCODES_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode

WALLET_CONFIGURE_OFF=	--disable-wallet
WALLET_CONFIGURE_ON=	--enable-wallet \
			--with-incompatible-bdb \
			BDB_CFLAGS=-I${BDB_INCLUDE_DIR} \
			BDB_LIBS="-L${BDB_LIB_DIR} \
				-Wl,-rpath=${BDB_LIB_DIR} \
				-l${BDB_LIB_CXX_NAME}"
WALLET_USES=		bdb:5+

ZMQ_CONFIGURE_ENABLE=	zmq
ZMQ_BUILD_DEPENDS=	libzmq4>0:net/libzmq4
ZMQ_RUN_DEPENDS=	libzmq4>0:net/libzmq4

CONFIGURE_ARGS?=	--without-libs \
			--with-gui=qt5 \
			--without-daemon \
			--without-utils

CONFIGURE_ENV=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lcrypto" \
		SSL_CFLAGS="-I${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl" \
		OBJCXX="${CXX}" OBJCXXFLAGS="${CXXFLAGS}"
MAKE_ENV+=	V=1

# Include paths for bundled libbacktrace and bls-signatures
CPPFLAGS+=	-I${WRKSRC}/chiabls/include -I${WRKSRC}/libbacktrace/include
LIBS+=		-L${WRKSRC}/chiabls/lib -L${WRKSRC}/libbacktrace/lib

post-extract:
	${MKDIR} ${WRKSRC_bls}/build

pre-configure:
	# Configure for bundled bls-signatures dependency
	(cd ${WRKSRC_bls}/build && \
	cmake ../)
	# Configure for bundled libbacktrace dependency
	(cd ${WRKSRC_lbt} && \
	./configure --disable-shared --enable-host-shared --prefix=${WRKSRC}/libbacktrace CC=${CC} CXX=${CXX})

pre-build:
	# Build bundled bls-signatures dependency and install into a subdirectory under ${WRKSRC}
	(cd ${WRKSRC_bls}/build && \
	cmake --build . && \
	cmake --install ${WRKSRC_bls}/build --prefix ${WRKSRC}/chiabls)
	# Build bundled libbacktrace dependency and install into a subdirectory under ${WRKSRC}
	(cd ${WRKSRC_lbt} && \
	${MAKE_CMD} && \
	${MAKE_CMD} install)

.if defined(SLAVE_PORT) && ${SLAVE_PORT} == "no"

post-patch:
	${MKDIR} ${WRKSRC}/src/build-aux
	${REINPLACE_CMD} -e 's,=/usr,=${PREFIX},' \
		-e 's,Icon=dash,Icon=dashpay,g' ${WRKSRC}/contrib/debian/${REALNAME}-qt.desktop

post-install:
	${INSTALL} ${WRKSRC}/contrib/debian/${REALNAME}-qt.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL} ${WRKSRC}/src/qt/res/icons/bitcoin.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}128.png

.endif

regression-test: build
	# To use this sucessfully, remove --without-daemon and --without-utils
	# from CONFIGURE_ARGS above.

	@cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.mk>
