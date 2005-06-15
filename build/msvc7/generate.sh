#! /bin/sh
#
# This script generates the Visual Studio 6 build files for Windows.
#
# 20041214 larsa

rm -f sowin1.dsp sowin1.dsw installsowinheaders.bat

../../configure --prefix=/cygdrive/c/Coin3D --enable-msvcdsp --with-msvcrt=mt || exit 1
make || exit 1

build_pwd=`pwd`
build="`cygpath -w $build_pwd | sed -e 's/\\\\/\\\\\\\\/g'`"
build_pwd="`pwd | sed -e 's/\\//\\\\\\\\/g'`\\\\"

source_pwd=`cd ../..; pwd`
source="`cygpath -w $source_pwd | sed -e 's/\\\\/\\\\\\\\/g'`"
source_pwd="`(cd ../..; pwd) | sed -e 's/\\//\\\\\\\\/g'`"

sed \
  -e "s/$build/./g" \
  -e "s/$build_pwd//g" \
  -e "s/$source/..\\\\../g" \
  -e "s/$source_pwd/..\\\\../g" \
  -e 's/$/\r/g' \
  <sowin1.dsp >new.dsp

mv new.dsp sowin1.dsp

sed \
  -e "s/$build/./g" \
  -e "s/$build_pwd//g" \
  -e "s/$source/..\\\\../g" \
  -e "s/$source_pwd/..\\\\../g" \
  -e 's/$/\r/g' \
  <installsowinheaders.bat >new.bat

mv new.bat installsowinheaders.bat

echo "Run 'devenv sowin1.dsw' and save all solution files."
# echo "Then run './fixvcproj.sh'."

