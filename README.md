# B2
<div style="text-align:right">A balanced quinary computer emulator</div>

---

B2 is a high-efficiency remake of a [project](https://www.github.com/somecollagist/Brubeck) I made in 2021, because present (and future?) me is smarter than past me.

# Table of contents
- [B2](#b2)
- [Table of contents](#table-of-contents)
- [Aims of B2](#aims-of-b2)
- [Usage](#usage)
	- [Installation](#installation)
		- [Windows](#windows)
		- [Linux](#linux)
	- [Compilation](#compilation)
- [Pull Requests](#pull-requests)

# Aims of B2
- Use C instead of C# for better portability and efficiency.
- Just use the standard output because a GUI is super hard to make crossplatform and it barely works anyway.
- Use ports so constant input is possible.
- Design a better logic system - B2 shouldn't rely on maths outside of its own logic gates.

# Usage
## Installation
B2 depends on the following programs:
- gcc
- make

### Windows
- Install the [Chocolately](https://chocolatey.org/install) package manager for Windows. (Just follow their instructions because they work.)
- Navigate to the `setup` directory and run `./setup-windows.cmd`.
### Linux
Navigate to the `setup` directory and run `./setup-distro.sh`, replacing `distro` with whatever base distribution your linux machine runs on.

## Compilation
Compiling B2 is super easy - just run `make` in this directory and the necessary makefile will be run, thus compiling your program. Please note that running `make` by itself will also run the program immediately after compiling - to avoid this behaviour, run `make build` instead.

# Pull Requests
Any pull requests would be much appreciated and will be merged ASAP. :)

If you are committing any changes, follow the rules below:
- Ensure that any changes you make are well-tested and that you don't depend on any quirks of your operating system - this is a cross-platform project after all.
- Stick to C. I really cannot be bothered with having to add extra compilers to the toolchain and if I could make the first version in C#, we can do it in C. (But feel free to invite me to your own port written in some other language :P)
- Comment your code, it's good practice for you and makes it less of a pain for others to understand.
- Follow the [style guide](STYLEGUIDE.md). If in doubt, just look at how I've done it.