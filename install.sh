#!/bin/sh

export PKG_CONFIG_PATH=./library/libpqxx:$PKG_CONFIG_PATH
mkdir -p ./build
cd build
cmake ..
make
cd ..
