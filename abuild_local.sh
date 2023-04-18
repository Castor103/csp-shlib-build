#!/bin/bash

##############################################

cmake_argument="-DMAKE_OWN_MODE=True"

##############################################

echo "[Remove Build Files]"
rm -rf ./*

echo "[Execute Cmake]"
cmake .. ${cmake_argument}

echo "[Execute Make]"
time(make -j`nproc`)

echo "[Execute Install]"
make install;