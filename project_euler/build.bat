@echo off
if not exist build mkdir build
pushd build

cl /wd4100 /wd4189 /W4 /Z7 ..\main.c

popd