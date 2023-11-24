#-------------------------------------------------------------------------------------------------------------
#   HOME FOLDER
#-------------------------------------------------------------------------------------------------------------
HOME = "C:\\Users\\Administrador\\"
BOOST_HOME = "C:\\local\\boost_1_82_0\\ "
#-------------------------------------------------------------------------------------------------------------
#   COMMAND FLAGS FOR CL
#-------------------------------------------------------------------------------------------------------------
COMPILER         =  "cl "
FLAGS            =  "/W3 /EHsc /std:c++17 /GA /MT -D_WIN32_WINNT=0x0601 " 
#-------------------------------------------------------------------------------------------------------------
#   TELL CL TO LINK
#-------------------------------------------------------------------------------------------------------------
LINK            = " /link "
#-------------------------------------------------------------------------------------------------------------
#   MY TEMPLATE ONLY HEADER LIB
#-------------------------------------------------------------------------------------------------------------
#TEMPLATE_LIB    = "/I"+ HOME + "Documents\\GitHub\\mycpp\\template_lib "
#-------------------------------------------------------------------------------------------------------------
#   INCLUDE FOLDERS AND SRC FOLDERS
#-------------------------------------------------------------------------------------------------------------
INCLUDE         = ""
SRC             = ""
#-------------------------------------------------------------------------------------------------------------
#   WINDOWS NECESSARY LIBS
#   Cimg for example requires:
#   " kernel32.lib user32.lib gdi32.lib Shell32.lib"
#-------------------------------------------------------------------------------------------------------------
LIB_WINDOWS     = ""
#-------------------------------------------------------------------------------------------------------------
#  HEADERS AND LIBS 
#-------------------------------------------------------------------------------------------------------------
LIB_HEADERS         = "/I" + BOOST_HOME
LIB                 = ""
#-------------------------------------------------------------------------------------------------------------
#   CMD TO BUILD
#   if you want to build only one file using build.bat just leave as "%%SRC%%"
#   and use build yourfile.cpp
#   otherwise you can add sources above in the SRC variable
#-------------------------------------------------------------------------------------------------------------
BUILD_CMD     = COMPILER + FLAGS + LIB_HEADERS + "%%SRC%%" + LINK
#-------------------------------------------------------------------------------------------------------------