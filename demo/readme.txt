edit config.py by having

BUILD_CMD     = COMPILER + FLAGS + TEMPLATE_LIB + "%%SRC%%" + LINK + LIB


run 
build --s <source_file>.cpp
