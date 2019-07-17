FreeBSD Coin Ports
==================

## About
These are FreeBSD Ports for several alternative crypto currencies (Altcoins) that are not officionaly part of the FreeBSD ports tree. These are basicly shell archives that you would download and extract to your ports/net-p2p folder.  Then run "make install clean".  Complete instructions on how to use these files can be found at:

http://www.unibia.com/unibianet/freebsd/freebsd-ports-many-alternative-crypto-currencies

Some of these ports have an external library dependencies that may not be in the default FreeBSD ports tree

- secp256k1: https://github.com/tuaris/secp256k1-freebsd
- torlibs: https://github.com/tuaris/torlibs-freebsd

## Build Logs

Build logs for some of the ports for select FreeBSD releases can be seen at:

http://pkg.morante.net/poudriere/data/93amd64-default-wallets/latest-per-pkg  
http://pkg.morante.net/poudriere/data/10amd64-default-qtwallets/latest-per-pkg  
http://pkg.morante.net/poudriere/data/93amd64-default-qtwallets/latest-per-pkg  

## PKG Repository

If you would like to use the QT Wallets for X11 Desktops you can add the following PKG repository to your system by creating the file `/usr/local/etc/pkg/repos/QTWallets.conf` with the following contents:

```
QTWallets: {
	url: "http://pkg.morante.net/qtwallets/${ABI}",
	enabled: yes
}
```

Or, To use the non-x11 daemons `/usr/local/etc/pkg/repos/Wallets.conf`:

```
Wallets: {
	url: "http://pkg.morante.net/wallets/${ABI}",
	enabled: yes
}
```

Install packages from the console:

```
pkg update
pkg install octocoin
```

OctoPkg can be used instead if you prefer a GUI.

## Your own PKG-NG Repository

If you would like to build your own pkg repository, copy the following into poudriere's `/usr/local/etc/poudriere.d/<jailname>-make.conf`. 

```
OPTIONS_UNSET=SSL PORTS_SSL
DEFAULT_VERSIONS+= ssl=base "java=1.8+"
```

For best results, we recommend using a blank poudriere build jail only for building wallet related things, as this allows you to build packages that do not rely on `openssl/libreessl` and won't give you a headache later. These ports only build with openssl anyway (like all bitcoin forks).


## Using with Portshaker

Create a file `/usr/local/etc/portshaker.d/coins` with the following contents.
```
#!/bin/sh
. /usr/local/share/portshaker/portshaker.subr
method="git"
if	[ "$1" != '--' ]; then
	err 1 "Extra arguments"
fi
shift
git_clone_uri="https://github.com/tuaris/FreeBSD-Coin-Ports.git"
git_branch="master"
run_portshaker_command $*
```

Then add **coins** to your **_merge_from** line in `/usr/local/etc/portshaker.conf`.  For example.

```
#---[ Base directory for mirrored Ports Trees ]---
mirror_base_dir="/var/cache/portshaker"

#---[ Directories where to merge ports ]---
ports_trees="default"

use_zfs="yes"
poudriere_dataset="poudriere/poudriere"
poudriere_ports_mountpoint="/usr/local/poudriere/ports"
default_poudriere_tree="default"
default_merge_from="ports coins"
```

## The current list of crypto currencies:

- aricoin
- auroracoin
- b1bl3coin
- bitcoindark
- binarycoin
- bonuscoin
- bytecoin
- camcoin
- catcoin
- chococoin
- continuumcoin
- crown
- cryptobuck
- dash
- DarkCrave
- dimecoin
- digitalcoin
- dnotes
- dogecoin
- dotcoin
- eMark
- earthcoin
- eags
- eccoin
- emerald
- emoticoin
- fireflycoin
- giftcoin
- Gimpcoin
- GoldReserve
- Greed
- Guldencoin
- halfcoin
- hamstercoin
- heavycoin
- html5coin
- joulecoin
- kittehcoin
- KolschCoin
- legendarycoin
- linX
- lynx
- mazacoin
- microcoin
- mintcoin
- MMXIVCoin
- mooncoin
- mobiuscoin
- mustachecoin
- muniti
- Nanite
- nautiluscoin
- nbcoin
- octocoin
- orangecat
- Orangecoin
- Peercoin
- Rainbowcoin
- Riecoin
- starcoin
- startcoin
- stashcoin
- suncoin
- takeicoin
- teacoin
- tekcoin
- terracoin
- tetcoin
- thorcoin
- UniversalCurrency
- Unobtanium
- unbreakablecoin
- uro
- VeniVidiVici
- VERGE
- xaucoin
- xmascoin

It's possible some of these coins may eventually be submitted into the ports tree after they gain enough demand and popularity.  If you found this work helpful and would like to show your thanks you may send

BTC to: 1B6eyXVRPxdEitW5vWrUnzzXUy6o38P9wN

ZET to: ZK6kdE5H5q7H6QRNRAuqLF6RrVD4cFbiNX
