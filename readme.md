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
  
- Download the contents of 
https://github.com/zlogdanbr/mycpp/tree/main/build_tool
And add the folder you downloaded them to your windows path

Once you do that you may edit the config.py file and configure your build. 
They are easy to use and more fun than makefiles. I suspect that you can port than to Linux easily.

build --s yoursource.cpp 	# builds the select source ignoring the SRC variable
build						# expects you to have set the SRC variable at config.py
build --clean				# removes OBJs and EXEs files

You can use it at your will, and please remember to mention me if possible.

-----------------------------------------------------------------------------------------------
As you will notice I have left examples on how to use the following libraries, using my python script.


Install and configure libcurl Windows/VS Studio Command Line:

https://juhilee.hashnode.dev/configuring-libcurl-in-visual-studio-2022

-----------------------------------------------------------------------------------------------

Single header REST API:

https://github.com/yhirose/cpp-httplib

-----------------------------------------------------------------------------------------------

Single header JSON API:

https://github.com/nlohmann/json

-----------------------------------------------------------------------------------------------

Windows C++ System Programming:

https://caiorss.github.io/C-Cpp-Notes/WindowsAPI-cpp.html#org9c1b3fd

-----------------------------------------------------------------------------------------------

CImg Single Header C++ Image Processing:

http://cimg.eu

needs the following Windows libraries
kernel32.lib user32.lib gdi32.lib Shell32.lib

-----------------------------------------------------------------------------------------------

Libcurl:

https://curl.se/libcurl/

-----------------------------------------------------------------------------------------------

OpenSSL:

https://www.openssl.org

Use chocolatey to download

https://community.chocolatey.org/packages/openssl



-----------------------------------------------------------------------------------------------

Eigen:

Great lib for manipulating matrix and linear algebra ( this is what basically you do with Machine Learning and AI )

https://eigen.tuxfamily.org/index.php?title=Main_Page

-----------------------------------------------------------------------------------------------

Windows package manager:

https://chocolatey.org

-----------------------------------------------------------------------------------------------
_________________________________________________
**2020, 2021, 2022, 2023 Daniel Vasconcelos Gomes**
**You can use this freely but I don't take responsibility for whatever problems this will likely cause. I use this as a library for my code.**
