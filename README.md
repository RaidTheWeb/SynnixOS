# SynnixOS

Epic Hobby OS targeting x86_64 CPUs, it includes some hacked together functionality for most essential OSs although, with interactivity via QEMU serial0

Grab the latest stable release [here](https://github.com/RaidTheWeb/SynnixOS/releases)

And pick up a nightly build [here](https://github.com/RaidTheWeb/SynnixOS/actions/workflows/build.yml)

Latest releases are released when I upload it manually, and nightly are at 10:30am everyday.

## Requirements

- Atleast 5GB is required to store the full compiled source and toolchain

- 2GB or more available RAM is recommended for building the project

- Dual Core at the bare minimum is recommended

## Features

- ELF Loader

- Multiboot support

- POSIX Compliance

- Lua port

- Userspace

- Kernel Modules

- Serial communications

- Multi-threading

- Virtual File System

- TTY

- PCI support

- Syscall tracing for debugging

- Decent LibC

- LibM 

- InitFS

- Interactive Shell supporting piping, file redirection and executable search path

- x86_64 support

- Networking stack (Sockets, Maybe TCP in the future)

- Proc File System

- Unix-like enviroment

- GRUB Bootloader, not sweaty limine. (Could probably port it though :thinking:)

## Contributing

[Learn more about how you can help here!](https://github.com/RaidTheWeb/SynnixOS/blob/master/CONTRIBUTING.md)

## Building

For building SynnixOS you'll need a few dependencies. Please install the following on your **unix-like** system (If on windows consider [WSL](https://en.wikipedia.org/wiki/Windows_Subsystem_for_Linux))

(These follow Ubuntu package names for APT)

- `mtools`
- `grub-pc-bin`
- `nasm`
- `libgmp-dev`
- `libmpc-dev`
- `libmpfr-dev`
- `xorriso`
- `ruby`
- `make`

After installing these dependencies you'll need to build the `x86_64-synnixos` toolchain for cross compiling the OS and it's programs. Run the `./scripts/build_toolchain.bash` file from the root of the git repository and wait around 10 or so minutes for it to complete.

Once the toolchain has finished compiling you can run `make` in the root of the repo to build the OS it should optimaly take only around 30 seconds to compile the OS.

Then after compiling the OS initially `cd` into `external` and run `./make.bash` to build the various ports of third party software, then go `cd ..` back into the root directory and run `make` once more to package the ports into the ISO

After completing all these steps, you may run `./run.rb` to run the [QEMU](https://www.qemu.org/) emulator with the `synnixos.iso` ISO

## References

### Books and resources

OSDev Wiki - [https://osdev.org](https://osdev.org)

The Little OS Book - [https://littleosbook.github.io/](https://littleosbook.github.io/)

### Projects

Sortix - [https://sortix.org/](https://sortix.org/)

Pedigree Project - [https://miselin.github.io/pedigree/](https://miselin.github.io/pedigree/)

Aenix - [https://github.com/littleosbook/aenix](https://github.com/littleosbook/aenix)

The Managram Project - [https://github.com/managarm](https://github.com/managarm)

Toaruos - [https://github.com/klange/toaruos](https://github.com/klange/toaruos)

mOS - [https://github.com/MQuy/mos](https://github.com/MQuy/mos)


## Other awesome OS projects

VisualOS - [https://github.com/nothotscott/VisualOS](https://github.com/nothotscott/VisualOS)

Aero - [https://github.com/Andy-Python-Programmer/aero](https://github.com/Andy-Python-Programmer/aero)

## License

SynnixOS is licensed under the [MIT License](https://opensource.org/licenses/MIT)