#!/usr/bin/env bash

mkdir -p sysroot/home
mkdir -p sysroot/bin
mkdir -p sysroot/usr/include
mkdir -p sysroot/usr/man/man1
mkdir -p sysroot/usr/bin
mkdir -p sysroot/usr/lib
mkdir -p sysroot/usr/share

function copy() {
    cp --dereference --recursive --no-target-directory --preserve=timestamps "$1" "$2"
}

copy include sysroot/usr/include
copy libc/include sysroot/usr/include
copy libm/include sysroot/usr/include
copy kernel/include sysroot/usr/include
copy x86/include sysroot/usr/include
copy fs/include sysroot/usr/include
copy linker/include sysroot/usr/include
copy fakerootfs/ sysroot/

find user -maxdepth 1 -type f -not -name '*.c' -exec cp {} sysroot/bin \;

touch sysroot
