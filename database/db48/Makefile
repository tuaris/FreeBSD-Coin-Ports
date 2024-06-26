PORTNAME=	db48
PORTVERSION=	4.8.30.0
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/ \
				http://cdn.pacyworld.com/morante.net/freebsd/ports/distfiles/database/db48/
PKGNAMEPREFIX?=
DISTNAME=	db-${PORTVERSION:R}
DIST_SUBDIR=	bdb

MAINTAINER=	daniel@morante.net
COMMENT=	Berkeley DB package, revision 4.8
WWW=		http://www.oracle.com/us/products/database/berkeley-db/db/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE

BDBVER=		${PORTVERSION:R:R}
CONFIGURE_ARGS=	--enable-compat185 --enable-dump185 --enable-cxx \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME} \
		--bindir=${PREFIX}/bin/${PORTNAME}
CONFIGURE_SCRIPT=	../dist/configure
USES=		libtool:keepla
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install_include install_lib install_utilities
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == armv6 || ${ARCH} == armv7
# db48 uses a deprecated instruction for mutexes on ARM, fbsd bug#197227
CONFIGURE_ARGS+=	--enable-posixmutexes
.endif

post-patch:
	${REINPLACE_CMD} -Ee 's|--mode=install cp -p|--mode=install ${INSTALL} -s|;' ${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -Ee 's/[[:<:]]atomic_init[[:>:]]/db_atomic_init/g' ${WRKSRC}/../dbinc/atomic.h ${WRKSRC}/../mp/mp_*.c ${WRKSRC}/../mutex/mut_*.c

post-install:
.for i in libdb libdb_cxx
	${LN} -s -f ${PORTNAME}/${i}-${BDBVER}.so.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -s -f ${i}-${BDBVER}.so.0 ${STAGEDIR}${PREFIX}/lib/${i}-${BDBVER}.so
.endfor
	cd ${STAGEDIR}${PREFIX}/bin/${PORTNAME}; \
	for i in *; do ${LN} -s -f ${PORTNAME}/$$i ../$$i-${BDBVER}; done

.include <bsd.port.mk>
