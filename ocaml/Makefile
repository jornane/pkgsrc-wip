# $NetBSD: Makefile,v 1.137 2020/12/08 08:53:16 he Exp $

.include "Makefile.common"

#CONFIGURE_ENV+=		disable_x11=yes

BUILD_TARGET=		world
TEST_PROGRAM=		ocamltest
MAKE_JOBS_SAFE=		no
UNLIMIT_RESOURCES=	stacksize

USE_TOOLS+=		bash
USE_LANGUAGES+=		c
USE_LIBTOOL=		yes
USE_GNU_CONFIGURE_HOST=	no

#USE_GCC_RUNTIME=	yes

PLIST_VARS+=	ocaml-stub ocaml-prof ocaml-opt ocaml-nat ocaml-spacetime \
		instrumented_runtime

.include "options.mk"
###
### PLIST components
###

# Stub libraries for functions missing from base system.
.if !empty(MACHINE_PLATFORM:MDarwin-*-powerpc) || \
    !empty(MACHINE_PLATFORM:MDarwin-9.*-i386) || \
    !empty(MACHINE_PLATFORM:MDarwin-1[0-9].*) || \
    ${OPSYS} == "DragonFly" || ${OPSYS} == "NetBSD" || \
    ${OPSYS} == "FreeBSD" || ${OPSYS} == "SunOS" || \
    ${OPSYS} == "Linux"
PLIST.ocaml-stub=	yes
.endif

# Optional components built only on certain platforms.
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    !empty(MACHINE_ARCH:M*arm*) || (${MACHINE_ARCH} == "aarch64") || \
    (${MACHINE_ARCH} == "x86_64")
BUILD_TARGET+=		opt opt.opt
TEST_PROGRAM+=		ocamltest.opt
PLIST.ocaml-opt=	yes
.  if empty(MACHINE_PLATFORM:MDarwin-*-powerpc) && \
      empty(MACHINE_PLATFORM:MSunOS-*-i386) && \
      (${MACHINE_ARCH} != "aarch64")
PLIST.ocaml-prof=	yes
.  endif
.endif

# XXX This conditional is not complete.  It should match the
# conditional in ocaml-x.y.z/configure.
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "aarch64") || (${MACHINE_ARCH} == "powerpc")
.  if !empty(MACHINE_PLATFORM:MLinux-*-*) || \
      !empty(MACHINE_PLATFORM:MFreeBSD-*-*) || \
      !empty(MACHINE_PLATFORM:MDragonFly-*-*) || \
      !empty(MACHINE_PLATFORM:MNetBSD-*-*) || \
      !empty(MACHINE_PLATFORM:MDarwin-*-*) || \
      !empty(MACHINE_PLATFORM:MSunOS-*-*)
PLIST.ocaml-nat=	yes
.  endif
.endif

# Spacetime profiling is only available for native code on 64-bit targets.
.if (${MACHINE_ARCH} == "x86_64") || (${MACHINE_ARCH} == "aarch64")
PLIST.ocaml-spacetime=	yes
.endif

# clock_gettime(2), required by POSIX, is necessary for the
# instrumented_runtime feature.
# It is missing on macOS before 10.12.
.if ${OPSYS} != "Darwin" || ${OS_VERSION:R:R} >= 16
PLIST.instrumented_runtime=	yes
.endif

# This is needed because ${WRKSRC}/build/partial-install.sh uses
# $PWD as part of its script.  However, with /bin/sh on SunOS
# (cd work/foo-1.0 && echo $PWD) will show that the value of PWD is
# set before the cd takes place and is then passed down.  So the end
# result is when ./build/partial-install.sh is called, PWD is set
# to /usr/pkgsrc/devel/ocaml instead of ${WRKSRC}.  /bin/ksh, which
# is what ${SH} is on SunOS, doesn't exhibit this behaviour.
.if ${OPSYS} == "SunOS"
INSTALL_MAKE_FLAGS+=	SHELL=${SH:Q}
.endif

#INSTALLATION_DIRS=	${PKGMANDIR}/man1

OPSYSVARS+=		EXTRA_RT_LIBS
EXTRA_RT_LIBS.NetBSD=	-lcurses
EXTRA_RT_LIBS.*=

PRINT_PLIST_AWK+=	{ gsub(/lib\/ocaml\/${PKGMANDIR:S|/|\\/|}/, "lib/ocaml/$${PKGMANDIR}"); }

.if defined(PLIST.instrumented_runtime)
REPLACE_BASH+=		tools/ocaml-instr-graph
REPLACE_AWK+=		tools/ocaml-instr-report
.endif

do-test:
	cd ${WRKSRC} && ${MAKE_PROGRAM} ${TEST_PROGRAM}
	cd ${WRKSRC}/testsuite && ${MAKE_PROGRAM} all

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	for f in ${DESTDIR}${PREFIX}/lib/ocaml/*.so \
		${DESTDIR}${PREFIX}/lib/ocaml/stublibs/*.so; do \
		install_name_tool -id `${ECHO} $$f | ${SED} -e 's,${DESTDIR},,g'` $$f; \
	done
.endif

#post-install:
#	set -e ; cd ${DESTDIR}${PREFIX}/lib/ocaml/${PKGMANDIR}/man1;	\
#	for m in *; do							\
#	  ln -sf ${PREFIX}/lib/ocaml/${PKGMANDIR}/man1/$$m		\
#		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/$$m;		\
#	done

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
