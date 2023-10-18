echo off
set arg1=%1
set arg2=%2
IF "%~1"=="--s" GOTO _SINGLE
IF "%~1"=="" GOTO _BUILD
IF "%~1"=="--clean" python build.py --clean
GOTO _END
:_BUILD
python build.py --clean
python build.py --project
GOTO _END
:_SINGLE
python build.py %arg2%
:_END
