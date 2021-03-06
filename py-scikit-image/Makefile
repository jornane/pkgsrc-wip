# $NetBSD$

DISTNAME=	scikit-image-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scikit-image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://scikit-image.org/
COMMENT=	Image processing routines for SciPy
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.21:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-numpy>=0.19.0:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.0.1:../../wip/py-scipy
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.2.2:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-Pillow>=4.3.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-imageio>=2.3.0:../../graphics/py-imageio
DEPENDS+=	${PYPKGPREFIX}-pywavelets>=1.1.1:../../wip/py-pywavelets
DEPENDS+=	${PYPKGPREFIX}-networkx>=2.0:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} skivi skivi-${PYVERSSUFFIX} || ${TRUE}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
