#!/bin/bash

ARCHIVE="oblikue-strategies"
SRCDIR="sources"
FILES="README"
IGNORELIST="CMakeLists.txt.user"
VERSION=`grep Version ${SRCDIR}/*.desktop | awk -F "=" '{print $2}'`

# create archive
[[ -e ${ARCHIVE}-${VERSION}.tar.xz ]] && rm -f ${ARCHIVE}-${VERSION}.tar.xz
[[ -d ${ARCHIVE} ]] && rm -rf ${ARCHIVE}
cp -r ${SRCDIR} $ARCHIVE
for FILE in ${FILES[*]}; do cp $FILE ${ARCHIVE}; done
for FILE in ${IGNORELIST[*]}; do rm -f ${ARCHIVE}/${FILE}; done
tar cvJf ${ARCHIVE}-${VERSION}.tar.xz ${ARCHIVE} > /dev/null
rm -rf ${ARCHIVE}

# update md5sum
MD5SUMS=`md5sum ${ARCHIVE}-${VERSION}.tar.xz | awk '{print $1}'`
sed -i "/md5sums=('[0-9A-Fa-f]*/s/[^'][^)]*/md5sums=('${MD5SUMS}'/" PKGBUILD
sed -i "s/pkgver=[0-9.]*/pkgver=${VERSION}/" PKGBUILD
