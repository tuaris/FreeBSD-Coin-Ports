PORTNAME=       kaspad
DISTVERSIONPREFIX=	v
DISTVERSION=    0.12.17
CATEGORIES=     net-p2p
PKGNAMESUFFIX=	-go

MAINTAINER=     ports@FreeBSD.org
COMMENT=        Reference full node Kaspa implementation written in Go
WWW=            https://github.com/kaspanet/kaspad/

LICENSE=        ISCL
LICENSE_FILE=   ${WRKSRC}/LICENSE

USES=			go:modules
USE_GITHUB=		yes
GH_ACCOUNT=		kaspanet

GO_TARGET=		.:kaspad \
				./cmd/genkeypair:genkeypair \
				./cmd/kaspactl:kaspactl \
				./cmd/kaspaminer:kaspaminer \
				./cmd/kaspawallet:kaspawallet \

USE_RC_SUBR=	${PORTNAME}
SUB_LIST=		PORTNAME=${PORTNAME}

GH_TUPLE=	\
		btcsuite:btcutil:v1.0.2:btcsuite_btcutil/vendor/github.com/btcsuite/btcutil \
		btcsuite:go-socks:4720035b7bfd:btcsuite_go_socks/vendor/github.com/btcsuite/go-socks \
		btcsuite:winsvc:v1.0.0:btcsuite_winsvc/vendor/github.com/btcsuite/winsvc \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gofrs:flock:v0.8.1:gofrs_flock/vendor/github.com/gofrs/flock \
		golang:crypto:v0.1.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:bcd21879b8fd:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.7.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:v0.5.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.5.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.7.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:392c879c8b08:google_go_genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.38.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		jrick:logrotate:v1.0.0:jrick_logrotate/vendor/github.com/jrick/logrotate \
		kaspanet:go-muhash:v0.0.4:kaspanet_go_muhash/vendor/github.com/kaspanet/go-muhash \
		kaspanet:go-secp256k1:v0.0.7:kaspanet_go_secp256k1/vendor/github.com/kaspanet/go-secp256k1 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		protocolbuffers:protobuf-go:v1.28.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		syndtr:goleveldb:758128399b1d:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tyler-smith:go-bip39:v1.1.0:tyler_smith_go_bip39/vendor/github.com/tyler-smith/go-bip39

PLIST_FILES=    bin/kaspad \
				bin/genkeypair \
				bin/kaspactl \
				bin/kaspaminer \
				bin/kaspawallet \
				"@sample etc/${PORTNAME}.conf.sample" \
				"@dir /var/run/${PORTNAME}"

post-install:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}

.include <bsd.port.mk>
