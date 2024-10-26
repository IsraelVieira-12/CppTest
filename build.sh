#! /bin/sh

cd build
if [[ "$OSTYPE" == "msys"* ]]; then
    mingw32-make
else
    make
fi