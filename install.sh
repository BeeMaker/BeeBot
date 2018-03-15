#!/bin/sh

export PKG_CONFIG_PATH=./lib/libpqxx/:$PKG_CONFIG_PATH
mkdir -p ./build
cd build
cmake ..
make
cd ..
