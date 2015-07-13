This is a C/C++ library that writes a progress bar to the terminal. It consists of a header file containing a templated function for C++, and a library of several functions for C. There are also 3 test programs: test.c, test2.c and test3.cpp.

Use the makefile to install it.

> make all
> make clean [--- remove \*.o files](optional.md)
> make install [--- cp C library and C/C++ header files to locations specified in environment variables, INSTALL\_DIR & INSTALL\_INC](optional.md)

Use the command,

> make distclean

to remove the 