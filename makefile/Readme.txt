This file contains makefiles and shell scripts for building the EPANET 2
engine in various formats on different C compilers. The files included in
this archive are:

VC6_DLL.ZIP - contains the makefile and instructions for building the
              Windows DLL version of the engine using Microsoft Visual
              C/C++ 6.

VC6_EXE.ZIP - contains the makefile and instructions for building the
              Windows command line version of the engine using Microsoft
              Visual C/C++ 6.

GNU_EXE.ZIP - contains the makefile and instructions for building the
              Linux command line version of the engine using the GNU C
              compiler.

GNU_SOL.ZIP - contains a shell script and instructions for building a
              shared object library on Linux using the GNU C compiler.

The DLL version of the engine is used with the EPANET 2 user interface
executable (epanet2w.exe) to form a complete Windows modeling package.
It also serves as the function library for the EPANET Programmer's Toolkit,
allowing developers to construct their own customized pipe network analysis
applications under the Windows operating system.

The shared object library version of the engine is used for building
custom applications under Linux using the same Programmer's Toolkit functions
that are available with the Windows DLL version of the engine.

The command line executable version of the engine is used to run EPANET as a
stand-alone water network analysis tool, under Windows or Linux, with no
graphical user interface.