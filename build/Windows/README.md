# Setup Procedure

We build for Windows using the GCC 13.1.0 MinGW (SEH) - 64-bit version of SFML.
The SFML Library can be downloaded from:

https://www.sfml-dev.org/download/sfml/2.6.0/

For Windows, a specific version of the C++ compiler is required. The one linked on the page above works and can be found below:

https://github.com/brechtsanders/winlibs_mingw/releases/download/13.1.0-16.0.5-11.0.0-msvcrt-r5/winlibs-x86_64-posix-seh-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5.7z

If you drag the include, lib, and bin directories from SFML2.6.0 into mingw64, the makefile here should work.

If you don't have make on Windows, you can find it here:

https://gnuwin32.sourceforge.net/packages/make.htm

Alternatively, run g++ in the terminal.