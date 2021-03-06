# $NetBSD$

PKGNAME=	gopass-1.11.0
DISTNAME=	gopass-${GITHUB_TAG}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=gopasspw/}
GITHUB_PROJECT=	gopass
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://www.gopass.pw/
COMMENT=	The slightly more awesome Standard Unix Password Manager for Teams
LICENSE=	mit

EXTRACT_USING=	bsdtar

.include "go-modules.mk"

GO_BUILD_PATTERN=	.
CHECK_RELRO_SKIP+=	bin/gopass

INSTALLATION_DIRS+=	bin \
			share/bash-completion/completions \
			share/fish/vendor_completions.d \
			share/zsh/site-functions

do-build:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_BUILD_PATTERN}
	${RUN} for cmd in gopass-git-credentials gopass-hibp gopass-jsonapi gopass-summon-provider; do \
		cd ${WRKSRC}/cmd/$${cmd} && ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_BUILD_PATTERN}; \
	done

post-build:
	cd ${WRKDIR}/.gopath && \
	./bin/gopass completion bash > ${WRKSRC}/completion.bash && \
	./bin/gopass completion fish > ${WRKSRC}/completion.fish && \
	./bin/gopass completion zsh  > ${WRKSRC}/completion.zsh

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/* ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/completion.bash \
			${DESTDIR}${PREFIX}/share/bash-completion/completions/gopass
	${INSTALL_DATA} ${WRKSRC}/completion.fish \
			${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/gopass.fish
	${INSTALL_DATA} ${WRKSRC}/completion.zsh \
			${DESTDIR}${PREFIX}/share/zsh/site-functions/_gopass

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
