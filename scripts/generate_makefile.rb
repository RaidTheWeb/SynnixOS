#!/usr/bin/env ruby

require_relative 'magpie_build'

DYNAMIC = false

COMMON_FLAGS = [
  "-Wall",
  "-Wextra",
  "-Werror",
  "-g",
  "-O2",
  "-Wno-unused-variable",
  "-Wno-unused-parameter",
  "-Wno-unused-function",
  "-Wno-sign-compare",
  "-Wno-address-of-packed-member",
]

COMMON_CFLAGS = [
  "-std=c11",
  *COMMON_FLAGS,
  "$(CFLAGS)",
]

COMMON_CXXFLAGS = [
  "-std=c++2a",
  "-fno-exceptions",
  *COMMON_FLAGS,
  "$(CXXFLAGS)",
]

USER_CFLAGS = [
  *COMMON_CFLAGS,
  "-Wno-builtin-declaration-mismatch",
  "-Wno-format",
  "$(USER_CFLAGS)",
]

USER_CFLAGS << "-static" unless DYNAMIC

USER_CXXFLAGS = [
  *COMMON_CXXFLAGS,
  "-Wno-builtin-declaration-mismatch",
  "$(USER_CXXFLAGS)",
]

USER_CXXFLAGS << "-static" unless DYNAMIC

USER_LDFLAGS = [
  "-g",
]

USER_LDFLAGS << "-static" unless DYNAMIC

KERNEL_CFLAGS = [
  *COMMON_CFLAGS,
  "-pedantic",
  "-ffreestanding",
  "-mno-red-zone",
  "-mno-80387",
  "-mno-mmx",
  "-mno-sse",
  "-mno-sse2",
  "-nostdlib",
  "-fno-asynchronous-unwind-tables",
  "-fno-omit-frame-pointer",
  "-DSYNNIXOS_VERSION=\\\"$(SYNNIXOS_VERSION)\\\"",
  "-D__kernel__=1",
  "-D_SNX=1",
  "-mcmodel=kernel",
  "-fsanitize=undefined",
  "$(KERNEL_CFLAGS)",
]

KERNEL_LDFLAGS = [
  "-nostdlib",
  "-Tx86/link_hh.ld",
  "-zmax-page-size=0x1000",
  "-g",
]

KERNEL_ASFLAGS = [
  "-felf64",
]

PROGRAM_EXTRA_LIBS = {
  "mb" => ["m"],
  "step" => ["elf"],
}

build = MagpieBuild.define do
  build_dir "build-x86_64"

  mode :user do
    cflags USER_CFLAGS
    cxxflags USER_CXXFLAGS
    ldflags USER_LDFLAGS
    cc "~/.local/bin/x86_64-synnixos-gcc"
    cxx "~/.local/bin/x86_64-synnixos-gcc"
    ld "~/.local/bin/x86_64-synnixos-gcc"
  end

  mode :libc do
    cflags [*USER_CFLAGS, "-fno-builtin"]
    ldflags USER_LDFLAGS
    cc "~/.local/bin/x86_64-synnixos-gcc"
    ld "ar"
  end

  mode :crt do
    as "~/.local/bin/x86_64-synnixos-gcc"
    ld nil
  end

  mode :so do
    # TODO factor this into COMMON -- it has no Wextra or pedanic
    # because that hits printf("%p\n", (non-void *)) -- I'm not sure
    # how I feel about that (and it's just "Werror=format")
    cflags [
      *COMMON_CFLAGS,
      "-fpic",
      "-shared",
    ]
    ldflags [
      "-nostdlib",
      "-fpic",
      "-shared",
      "-g",
    ]
    cc "~/.local/bin/x86_64-synnixos-gcc"
    ld "~/.local/bin/x86_64-synnixos-gcc"
  end

  mode :kernel do
    cflags KERNEL_CFLAGS
    ldflags KERNEL_LDFLAGS + ["-L#{build_dir}"]
    asflags KERNEL_ASFLAGS
    as "nasm"
    cc "~/.local/bin/x86_64-synnixos-gcc"
    ld "~/.local/bin/x86_64-synnixos-gcc"
  end

  mode :libk do
    cflags KERNEL_CFLAGS
    asflags KERNEL_CFLAGS
    as "~/.local/bin/x86_64-synnixos-gcc"
    cc "~/.local/bin/x86_64-synnixos-gcc"
    ld "ar"
  end

  mode :module do
    cflags KERNEL_CFLAGS
    cc "~/.local/bin/x86_64-synnixos-gcc"
    ld nil
  end

  target "libc.a" do
    language "C", "asm"
    mode :libc
    sources "libc/**/*.c", "libc/**/*.S"
    install "sysroot/usr/lib"
  end

  target "libsocs.a" do
    depends "libc.a"
    language "C"
    mode :libc
    sources "libsocs/**/*.c"
    install "sysroot/usr/lib"
  end

  target "libm.a" do
    language "C"
    mode :libc
    sources "libm/**/*.c"
    install "sysroot/usr/lib"
  end

  target "libelf.a" do
    language "C"
    mode :libc
    sources "linker/elf-snx.c"
    install "sysroot/usr/lib"
    alt_dir "libelf"
  end

  target "libc.so" do
    language "C", "asm"
    mode :so
    sources "libc/**/*.c", "libc/**/*.S"
    install "sysroot/usr/lib"
    alt_dir "libc_so"
  end

  target "libk.a" do
    language "C", "asm"
    sources [
      "libc/ctype.c",
      "libc/string.c",
      "libc/stdio.c",
      "libc/stdlib.c",
      "libc/malloc.c",
      "libc/errno.c",
      "libc/signal.c",
      "libc/x86_64/synnixos.c",
      "libc/setjmp.S",
    ]
    mode :libk
    alt_dir "libk"
  end

  target "snxk.elf" do
    depends "libk.a"
    language "C", "asm"
    sources [
      "kernel/**/*.c",
      "linker/elf-snx.c",
      "linker/modld.c",
      "fs/**/*.c",
      "x86/**/*.c",
      "x86/**/*.asm",
    ]
    mode :kernel
    link "k", "gcc"
    install "."
  end

  target "crt0.o" do
    mode :crt
    sources "libc/crt0.S"
    install "sysroot/usr/lib"
    alt_dir "crt"
  end

  target "sh" do
    depends "libc.a" ,"crt0.o"
    sources "sh/**/*.c"
    mode :user
    alt_dir "sh-"
    install "sysroot/bin"
  end

  target "init" do
    depends "libc.a", "crt0.o"
    sources "init/init.c"
    mode :user
    alt_dir "init-"
    install "sysroot/"
  end

  target "ld-snx.so" do
    sources [
      "linker/elf-snx.c",
      "linker/ldso.c",
      "linker/pltstub.S",
      "libc/syscall.c",
      "libc/syscalls.c",
    ]
    mode :so
    alt_dir "ld-snx"
    install "sysroot/bin"
  end

  Pathname.glob "modules/*.c" do |program_source|
    program = program_source.basename(".c").sub_ext(".ko")
    target program do
      sources program_source
      mode :module
      install "sysroot/bin"
    end
  end

  Pathname.glob "user/*.c" do |program_source|
    program = program_source.basename(".c")
    target program do
      depends "libc.so", "libc.a", "libm.a", "libelf.a"
      libs = PROGRAM_EXTRA_LIBS[program.to_s]
      link(*libs) if libs && !libs.empty?
      sources program_source
      mode :user
      install "sysroot/bin"
    end
  end
end

File.open("build.mk", "w") do |f|
  f.puts build.render
end
