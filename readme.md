_________________________________________________

This repository contains
=========================

template_lib
===============

A large header file with the useful code I wrote or found on books, the internet, or forums. ( The sources are always mentioned when applicable ). 
It is a large header file with a few namespaces. It contains useful code for search, debug, file, buffer handling, etc.


The usage is simple. Copy the util.h header file to your project and include it. Or:

If you want to build them, more easily, on Windows automatically, please:
	- install python
	- Visual Studio 2022 compiler/SDK
	- Then go to the folder demo and type:
		build your_cpp.cpp
		
It also includes examples of their usage in the subfolder demo, plus some examples of modern C++ I have been learning.		

**IMPORTANT:**
I use STL and C++17

>namespace mytools::algo
Contains code to be used with STL, DS and algorithms]

>namespace mytools::util
Contains useful code not buffer/string related

>namespace mytools::unittest
Unit testing functions

>namespace mytools::mymath
Linear algebra, matrix, numerical methods


Building files:

In order to use:

- git clone https://github.com/zlogdanbr/images.git
- Install python 3.10 or above
- Install Visual Studio 2022 and C++ tools
- This is the configuration file that will run the building
   https://github.com/zlogdanbr/mycpp/blob/main/demo/config.py
  So, edit your config file and import it in the build.py script
  
- I added the build_tool/folder with build.bat to my windows path so I can call it anytime and build using
  build mycpp.cpp

  But it also supports building projects using build --projects, just remember to change the config.py file.
  There is an example of this at:

  https://github.com/zlogdanbr/mycpp/tree/main/demo/proj_demo

You can use it at your will, and please remember to mention me if possible.


_________________________________________________
**2020, 2021, 2022, 2023 Daniel Vasconcelos Gomes**
**You can use this freely but I don't take responsibility for whatever problems this will likely cause. I use this as a library for my code.**
