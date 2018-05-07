# $FreeBSD$

PORTNAME=	bat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	textproc

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	cat(1) with syntax highlighting and Git integration

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo cmake gmake
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

CARGO_CRATES= libc-0.2.40 \
	      aho-corasick-0.6.4 \
	      ansi_term-0.11.0 \
	      ansi_term-0.9.0 \
	      atty-0.2.8 \
	      backtrace-0.3.6 \
	      backtrace-sys-0.1.16 \
	      base64-0.8.0 \
	      bincode-1.0.0 \
	      bitflags-0.9.1 \
	      bitflags-1.0.1 \
	      byteorder-1.2.2 \
	      cc-1.0.9 \
	      cfg-if-0.1.2 \
	      chrono-0.4.1 \
	      clap-2.31.2 \
	      clicolors-control-0.2.0 \
	      cmake-0.1.29 \
	      console-0.6.1 \
	      curl-sys-0.4.2 \
	      directories-0.10.0 \
	      dtoa-0.4.2 \
	      duct-0.10.0 \
	      error-chain-0.11.0 \
	      flate2-1.0.1 \
	      fnv-1.0.6 \
	      fuchsia-zircon-0.3.3 \
	      fuchsia-zircon-sys-0.3.3 \
	      git2-0.6.11 \
	      idna-0.1.4 \
	      itoa-0.4.1 \
	      kernel32-sys-0.2.2 \
	      lazy_static-0.2.11 \
	      lazy_static-1.0.0 \
	      lazycell-0.6.0 \
	      libgit2-sys-0.6.19 \
	      libssh2-sys-0.2.6 \
	      libz-sys-1.0.18 \
	      linked-hash-map-0.5.1 \
	      matches-0.1.6 \
	      memchr-2.0.1 \
	      miniz-sys-0.1.10 \
	      nix-0.9.0 \
	      num-integer-0.1.36 \
	      num-traits-0.2.2 \
	      onig-3.2.2 \
	      onig_sys-68.0.1 \
	      openssl-probe-0.1.2 \
	      openssl-sys-0.9.28 \
	      os_pipe-0.6.0 \
	      owning_ref-0.3.3 \
	      parking_lot-0.5.4 \
	      parking_lot_core-0.2.13 \
	      percent-encoding-1.0.1 \
	      pkg-config-0.3.9 \
	      plist-0.2.4 \
	      proc-macro2-0.3.1 \
	      quote-0.5.1 \
	      rand-0.4.2 \
	      redox_syscall-0.1.37 \
	      redox_termios-0.1.1 \
	      regex-0.2.10 \
	      regex-syntax-0.4.2 \
	      regex-syntax-0.5.5 \
	      rustc-demangle-0.1.7 \
	      safemem-0.2.0 \
	      same-file-1.0.2 \
	      serde-1.0.37 \
	      serde_derive-1.0.37 \
	      serde_derive_internals-0.23.0 \
	      serde_json-1.0.13 \
	      shared_child-0.3.2 \
	      smallvec-0.6.0 \
	      stable_deref_trait-1.0.0 \
	      strsim-0.7.0 \
	      syn-0.13.1 \
	      syntect-2.0.1 \
	      term_size-0.3.1 \
	      termion-1.5.1 \
	      termios-0.2.2 \
	      textwrap-0.9.0 \
	      thread_local-0.3.5 \
	      time-0.1.39 \
	      ucd-util-0.1.1 \
	      unicode-bidi-0.3.4 \
	      unicode-normalization-0.1.5 \
	      unicode-width-0.1.4 \
	      unicode-xid-0.1.0 \
	      unreachable-1.0.0 \
	      url-1.7.0 \
	      utf8-ranges-1.0.0 \
	      vcpkg-0.2.3 \
	      void-1.0.2 \
	      walkdir-2.1.4 \
	      winapi-0.2.8 \
	      winapi-0.3.4 \
	      winapi-build-0.1.1 \
	      winapi-i686-pc-windows-gnu-0.4.0 \
	      winapi-x86_64-pc-windows-gnu-0.4.0 \
	      xml-rs-0.7.0 \
	      yaml-rust-0.4.0 \

PLIST_FILES=	bin/bat

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
