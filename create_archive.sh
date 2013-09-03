#!/bin/bash

cd sources

FILES="CMakeLists.txt configwindow.ui oblikue-strategies.cpp oblikue-strategies.h oblikue-strategies.png plasma-applet-oblikue-strategies.desktop ../README"
ARCHIVE="oblikue-strategies"
VERSION=`cat plasma-applet-oblikue-strategies.desktop| grep Version | awk -F "=" '{print $2}'`

# create archive
if [ -e ${ARCHIVE}-${VERSION}.tar.xz ]; then
  rm -f ${ARCHIVE}-${VERSION}.tar.xz
fi
if [ -d ${ARCHIVE} ]; then
  rm -rf ${ARCHIVE}
fi
mkdir ${ARCHIVE}
for FILE in ${FILES[*]}; do
  cp $FILE ${ARCHIVE}
done
tar cvJf ../${ARCHIVE}-${VERSION}.tar.xz ${ARCHIVE}
rm -rf ${ARCHIVE}

# update md5sum
cd ..
MD5SUMS=`md5sum ${ARCHIVE}-${VERSION}.tar.xz| awk '{print $1}'`
sed -i "/md5sums=('[0-9A-Fa-f]*/s/[^'][^)]*/md5sums=('${MD5SUMS}'/" PKGBUILD
sed -i "s/pkgver=[0-9.]*/pkgver=${VERSION}/" PKGBUILD
