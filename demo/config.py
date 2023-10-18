#-------------------------------------------------------------------------------------------------------------
#   HOME FOLDER
#-------------------------------------------------------------------------------------------------------------
HOME = "C:\\Users\\Administrador\\"
#-------------------------------------------------------------------------------------------------------------
#   COMMAND FLAGS FOR CL
#-------------------------------------------------------------------------------------------------------------
COMPILER         =  "cl "
FLAGS            =  "/W3 /EHsc /std:c++17 /GA /MT " 
#-------------------------------------------------------------------------------------------------------------
#   TELL CL TO LINK
#-------------------------------------------------------------------------------------------------------------
LINK            = " /link"
#-------------------------------------------------------------------------------------------------------------
#   MY TEMPLATE ONLY HEADER LIB
#-------------------------------------------------------------------------------------------------------------
TEMPLATE_LIB    = "/I"+ HOME + "Documents\\GitHub\\mycpp\\mycpp\\template_lib "
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
LIB_HEADERS   = ""
LIB           = ""
#-------------------------------------------------------------------------------------------------------------
#   CMD TO BUILD
#   if you want to build only one file using build.bat just leave as "%%SRC%%"
#   and use build yourfile.cpp
#   otherwise you can add sources above in the SRC variable
#-------------------------------------------------------------------------------------------------------------
BUILD_CMD     = COMPILER + FLAGS + TEMPLATE_LIB + "%%SRC%%" + LINK
#-------------------------------------------------------------------------------------------------------------