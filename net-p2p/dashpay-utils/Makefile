# $FreeBSD$

MASTERDIR=	${.CURDIR}/../dashpay
PKGNAMESUFFIX=	-utils
PORTREVISION=	0

COMMENT=	Open sourced, privacy-centric digital currency (CLI and Utilities)
SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS
OPTIONS_DEFAULT=	HARDENING

CONFIGURE_ARGS=	--without-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-miniupnpc \
		--with-utils \
		--disable-wallet

PLIST_FILES=	bin/dash-cli bin/dash-tx \
		man/man1/dash-cli.1.gz man/man1/dash-tx.1.gz

.include "${MASTERDIR}/Makefile"
