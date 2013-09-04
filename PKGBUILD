# Author: Evgeniy "arcanis" Alexeev <esalexeev@gmail.com>
# Maintainer: Evgeniy "arcanis" Alexeev <esalexeev@gmail.com>

pkgname=kdeplasma-applets-oblikuestrategies
_pkgname=oblikue-strategies
pkgver=1.4
pkgrel=1
pkgdesc="Plasmoid that displays a random draw from Brian Eno and Peter Schmidt's Oblique Strategies"
arch=(any)
url="https://github.com/arcan1s/oblikuestrategies"
license=('GPL')
depends=('kdebase-workspace')
makedepends=('cmake' 'automoc4')
source=(https://github.com/arcan1s/oblikuestrategies/releases/download/V.${pkgver}/${_pkgname}-${pkgver}.tar.xz)
install=${pkgname}.install
md5sums=('3240aae830cbacc24c872534f1fa38e6')

build ()
{
  if [ -d ${srcdir}/build ]; then
    rm -r ${srcdir}/build
  fi
  mkdir ${srcdir}/build && cd ${srcdir}/build
  cmake -DCMAKE_INSTALL_PREFIX=`kde4-config --prefix` -DCMAKE_BUILD_TYPE=Release ../${_pkgname}/
  make || return 1
}

package() 
{
  cd ${srcdir}/build
  make DESTDIR=${pkgdir} install || return 1
}
