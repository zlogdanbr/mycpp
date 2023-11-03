# My CPP files, projects and tools


## Description:

This repo contains a large header file with the useful code I wrote or found on books, the internet, or forums. 
( The sources are always mentioned when applicable ). 
It is a large header file with a few namespaces. 
It contains useful code for search, debug, file, buffer handling, etc.


The usage is simple:

Copy the util.h header file to your project and include it. 


### Namespaces

>namespace mytools::algo
Contains code to be used with STL, DS and algorithms]

>namespace mytools::util
Contains useful code not buffer/string related

>namespace mytools::unittest
Unit testing functions

>namespace mytools::mymath
Linear algebra, matrix, numerical methods

It also contains a few examples of using some important C++ libraries for Image Processing, Linear Algebra, networking, etc

## Sqlite

There are a small class written to be used with sqlite. It assumes you had it installed in your system and that the compiler and linker know where it is.


**IMPORTANT:**
I use STL and C++17

## Building files:

It is possible to use Microsoft C++ compiler without VS IDE.  See below, how.


* git clone this repo
* Install python 3.10 or above
* Install Visual Studio 2022 and C++ tools
* Install https://chocolatey.org
* Download the contents of https://github.com/zlogdanbr/mycpp/tree/main/build_tool
* And add the folder you downloaded them to your windows path

Once you do that you may edit the config.py file and configure your build. 
They are easy to use and more fun than makefiles. I suspect that you can port than to Linux easily.

* build --s yoursource.cpp 	 (builds the select source ignoring the SRC variable see below )
* build						 (expects you to have set the SRC variable at config.py)
* build --clean				 (removes OBJs and EXEs files)


If you want to build only one source, please change your local config.sys to have 

BUILD_CMD     = COMPILER + FLAGS + TEMPLATE_LIB + "%%SRC%%" + LINK + LIB

this will allow the option to build a single source.


As you will notice I have left examples on how to use the a few important libraries as well, 
using my python script. 

## Useful links

The list of the libraries with examples is below along with some recommended sites and tools.

-----------------------------------------------------------------------------------------------
Microsoft C/C++ Compiler: 

https://learn.microsoft.com/en-us/cpp/build/building-on-the-command-line?view=msvc-170
https://learn.microsoft.com/en-us/cpp/build/reference/compiler-options-listed-by-category?view=msvc-170


-----------------------------------------------------------------------------------------------
Boost:

https://www.boost.org
Easiest way to install, using 

https://community.chocolatey.org/packages/boost-msvc-14.3


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
https://curl.se/libcurl/c/libcurl-tutorial.html
https://everything.curl.dev/libcurl/getinfo


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
