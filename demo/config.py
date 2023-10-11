#cl /EHsc /GA /MT simple.cpp User32.lib
#kernel32.lib, user32.lib, and gdi32.lib

#LIB_WINDOWS     = " kernel32.lib user32.lib gdi32.lib Shell32.lib"
LIB_WINDOWS     = ""
BUILD           =  "cl /W4 /EHsc /std:c++17 /GA /MT "  
LINK            = " /link"
TEMPLATE_LIB    = "/I"+"C:\\Users\\Administrador\\Documents\\GitHub\\mycpp\\mycpp\\template_lib "
#INCLUDE         = "/I"+"C:\\CImg-3.3.1 "
INCLUDE         = ""