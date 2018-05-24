# $FreeBSD$

PORTNAME=	miniserve
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.5
CATEGORIES=	www

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	HTTP server for file sharing with correct MIME types handling

# LICENSE.txt of the untrusted crate contains ISCL.
LICENSE=	APACHE20 BSD3CLAUSE CC0-1.0 ISCL MIT MPL20 UNLICENSE UNKNOWNRING
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_NAME_UNKNOWNRING=	Unknown Ring License
LICENSE_TEXT_UNKNOWNRING=	THE SOFTWARE IS PROVIDED "AS IS" AND BRIAN \
				SMITH AND THE AUTHORS DISCLAIM ALL WARRANTIES \
				WITH REGARD TO THIS SOFTWARE INCLUDING ALL \
				IMPLIED WARRANTIES OF MERCHANTABILITY AND \
				FITNESS. IN NO EVENT SHALL BRIAN SMITH OR THE \
				AUTHORS BE LIABLE FOR ANY SPECIAL, DIRECT, \
				INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY \
				DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, \
				DATA OR PROFITS, WHETHER IN AN ACTION OF \
				CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, \
				ARISING OUT OF OR IN CONNECTION WITH THE USE \
				OR PERFORMANCE OF THIS SOFTWARE.
LICENSE_PERMS_UNKNOWNRING=	dist-mirror pkg-mirror auto-accept

USES=	cargo
USE_GITHUB=	yes
GH_ACCOUNT=	svenstaro

PLIST_FILES=	bin/miniserve

CARGO_CRATES=	actix-0.5.6 \
		actix-web-0.6.5 \
		actix_derive-0.2.0 \
		aho-corasick-0.6.4 \
		ansi_term-0.11.0 \
		arrayvec-0.4.7 \
		atty-0.2.10 \
		backtrace-0.2.3 \
		backtrace-0.3.7 \
		backtrace-sys-0.1.16 \
		base64-0.6.0 \
		base64-0.9.1 \
		bitflags-0.9.1 \
		bitflags-1.0.3 \
		brotli-sys-0.3.2 \
		brotli2-0.3.2 \
		bytecount-0.3.1 \
		byteorder-1.2.3 \
		bytes-0.4.7 \
		cargo_metadata-0.5.4 \
		cc-1.0.15 \
		cfg-if-0.1.3 \
		chrono-0.4.2 \
		clap-2.31.2 \
		cookie-0.10.1 \
		crossbeam-channel-0.1.2 \
		crossbeam-deque-0.2.0 \
		crossbeam-deque-0.3.1 \
		crossbeam-epoch-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-epoch-0.4.1 \
		crossbeam-utils-0.2.2 \
		crossbeam-utils-0.3.2 \
		dbghelp-sys-0.2.0 \
		dtoa-0.4.2 \
		encoding-0.2.33 \
		encoding-index-japanese-1.20141219.5 \
		encoding-index-korean-1.20141219.5 \
		encoding-index-simpchinese-1.20141219.5 \
		encoding-index-singlebyte-1.20141219.5 \
		encoding-index-tradchinese-1.20141219.5 \
		encoding_index_tests-0.1.4 \
		error-chain-0.1.12 \
		error-chain-0.11.0 \
		error-chain-0.8.1 \
		failure-0.1.1 \
		failure_derive-0.1.1 \
		flate2-1.0.1 \
		fnv-1.0.6 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-0.1.21 \
		futures-cpupool-0.1.8 \
		gcc-0.3.54 \
		glob-0.2.11 \
		h2-0.1.7 \
		hostname-0.1.4 \
		http-0.1.5 \
		http-range-0.1.1 \
		httparse-1.2.4 \
		idna-0.1.4 \
		indexmap-1.0.1 \
		iovec-0.1.2 \
		ipconfig-0.1.6 \
		itoa-0.4.1 \
		kernel32-sys-0.2.2 \
		language-tags-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.0.0 \
		lazycell-0.6.0 \
		libc-0.2.40 \
		linked-hash-map-0.4.2 \
		log-0.4.1 \
		lru-cache-0.1.1 \
		matches-0.1.6 \
		memchr-2.0.1 \
		memoffset-0.1.0 \
		memoffset-0.2.1 \
		mime-0.3.7 \
		mime_guess-2.0.0-alpha.4 \
		miniz-sys-0.1.10 \
		mio-0.6.14 \
		mio-uds-0.6.6 \
		miow-0.2.1 \
		net2-0.2.32 \
		nodrop-0.1.12 \
		num-integer-0.1.38 \
		num-traits-0.2.4 \
		num_cpus-1.8.0 \
		owning_ref-0.3.3 \
		parking_lot-0.4.8 \
		parking_lot_core-0.2.14 \
		percent-encoding-1.0.1 \
		phf-0.7.22 \
		phf_codegen-0.7.22 \
		phf_generator-0.7.22 \
		phf_shared-0.7.22 \
		proc-macro2-0.3.8 \
		pulldown-cmark-0.1.2 \
		quick-error-1.2.1 \
		quote-0.3.15 \
		quote-0.5.2 \
		rand-0.3.22 \
		rand-0.4.2 \
		rayon-0.8.2 \
		rayon-core-1.4.0 \
		redox_syscall-0.1.37 \
		redox_termios-0.1.1 \
		regex-1.0.0 \
		regex-syntax-0.6.0 \
		remove_dir_all-0.5.1 \
		resolv-conf-0.6.0 \
		ring-0.12.1 \
		rustc-demangle-0.1.8 \
		safemem-0.2.0 \
		same-file-1.0.2 \
		scoped-tls-0.1.2 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.55 \
		serde_derive-1.0.55 \
		serde_json-1.0.17 \
		serde_urlencoded-0.5.2 \
		sha1-0.6.0 \
		simplelog-0.5.2 \
		siphasher-0.2.2 \
		skeptic-0.13.3 \
		slab-0.4.0 \
		smallvec-0.6.1 \
		socket2-0.3.5 \
		stable_deref_trait-1.0.0 \
		string-0.1.0 \
		strsim-0.7.0 \
		syn-0.11.11 \
		syn-0.13.10 \
		synom-0.11.3 \
		synstructure-0.6.1 \
		tempdir-0.3.7 \
		term-0.5.1 \
		termion-1.5.1 \
		textwrap-0.9.0 \
		thread_local-0.3.5 \
		time-0.1.40 \
		tokio-0.1.6 \
		tokio-core-0.1.17 \
		tokio-executor-0.1.2 \
		tokio-fs-0.1.0 \
		tokio-io-0.1.6 \
		tokio-reactor-0.1.1 \
		tokio-signal-0.1.5 \
		tokio-tcp-0.1.0 \
		tokio-threadpool-0.1.3 \
		tokio-timer-0.2.3 \
		tokio-udp-0.1.0 \
		trust-dns-proto-0.3.3 \
		trust-dns-resolver-0.8.2 \
		ucd-util-0.1.1 \
		unicase-1.4.2 \
		unicase-2.1.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.7 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		untrusted-0.5.1 \
		url-1.7.0 \
		utf8-ranges-1.0.0 \
		uuid-0.6.3 \
		vec_map-0.8.1 \
		version_check-0.1.3 \
		void-1.0.2 \
		walkdir-2.1.4 \
		widestring-0.2.2 \
		winapi-0.2.8 \
		winapi-0.3.4 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.5.0 \
		winutil-0.1.1 \
		ws2_32-sys-0.2.1

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/miniserve

.include <bsd.port.mk>
