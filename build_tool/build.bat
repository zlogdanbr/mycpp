echo off
set arg1=%1
set arg2=%2
IF "%~1"=="--s" GOTO _SINGLE
IF "%~1"=="" GOTO _BUILD
IF "%~1"=="--clean" python C:\Users\Administrador\Documents\GitHub\mycpp\build_tool\build.py --clean
GOTO _END
:_BUILD
python C:\Users\Administrador\Documents\GitHub\mycpp\build_tool\build.py --clean
python C:\Users\Administrador\Documents\GitHub\mycpp\build_tool\build.py --project
GOTO _END
:_SINGLE
python C:\Users\Administrador\Documents\GitHub\mycpp\build_tool\build.py %arg2%
:_END
