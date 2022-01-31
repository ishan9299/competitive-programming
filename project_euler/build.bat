@echo off
if not exist build mkdir build
pushd build

cl /DCOMPILE_SOLVED_PROBLEMS=1 /wd4100 /wd4189 /W4 /Z7 ..\main.c

popd