# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD: head/net-p2p/ethereum/Makefile 394175 2015-08-13 17:39:53Z pgollucci $

PORTNAME=	ethereum
PORTVERSION=	1.0.1
CATEGORIES=	net-p2p finance

MAINTAINER=	daniel@morante.net
COMMENT=	Peer-to-Peer crypto currency with quick transactions

LICENSE=	MIT

BROKEN=         Incomplete port
IGNORE=			Incomplete

BUILD_DEPENDS=	llvm-config${LLVM_VER}:${PORTSDIR}/devel/llvm${LLVM_VER}

LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs \
				libboost_date_time.so:${PORTSDIR}/devel/boost-libs \
				libleveldb.so:${PORTSDIR}/databases/leveldb \
				libgmp.so:${PORTSDIR}/math/gmp \
				libcryptopp.so:${PORTSDIR}/security/cryptopp \
				libjsoncpp.so:${PORTSDIR}/devel/jsoncpp \
				libminiupnpc.so:${PORTSDIR}/net/miniupnpc \
				#libjsonrpccpp-common.so:${PORTSDIR}/devel/libjson-rpc-cpp \
				libmicrohttpd.so:${PORTSDIR}/www/libmicrohttpd

USES+=		compiler:c++0x cmake

USE_GITHUB=	yes
GH_PROJECT=	webthree-umbrella

.include <bsd.port.options.mk>


.include <bsd.port.mk>
