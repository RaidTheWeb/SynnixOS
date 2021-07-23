#!/usr/bin/env bash
# set -x
function build() {
    cd lua
    CC=~/.local/bin/x86_64-synnixos-gcc SYSUSR=../../../sysroot/usr CFLAGS="-g -static" LDFLAGS="-g -static" make -j 8
    SYSUSR=../../../sysroot/usr make install
    cd -

    cd Epic8C
    make snx
    cd -

    #cd tinyvm
    #CC=~/.local/bin/x86_64-synnixos-gcc make
    #INSTALL_PREFIX=../../sysroot/usr make install 
    #cd -

    #cd kuroko
    #CC=~/.local/bin/x86_64-synnixos-gcc DESTDIR=../../../sysroot/usr CFLAGS="-g -static" LDFLAGS="-g -static" make -j 8
    #DESTDIR=../../../sysroot/usr make install
    #cd -
}

function clean() {
    cd lua
    make clean
    cd -

    cd Epic8C
    rm epic8
    cd -

    #cd tinyvm
    #make clean
    #cd -

    #cd kuroko
    #make clean
    #cd -
}

if [[ "$1" == "clean" ]]; then
    clean
else
    build
fi