#! /bin/sh

if [[ "$OSTYPE" == "msys"* ]]; then
    cmake -G "MinGW Makefiles" -DGLFW_BUILD_DOCS=OFF -S . -B build
else
    cmake -DGLFW_BUILD_DOCS=OFF -S . -B build
fi