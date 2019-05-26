@echo off

echo ^<?xml version="1.0" encoding="utf-8"?^> > build_h.msbuild
echo ^<Project DefaultTargets="Build" ToolsVersion="15.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003"^> >> build_h.msbuild

msbuild_generator.exe --input ..\src\dev\ --mode h >> build_h.msbuild
msbuild_generator.exe --input ..\src\pch\ --mode h >> build_h.msbuild

echo ^</Project^> >> build_h.msbuild

echo ^<?xml version="1.0" encoding="utf-8"?^> > build_cpp.msbuild
echo ^<Project DefaultTargets="Build" ToolsVersion="15.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003"^> >> build_cpp.msbuild

msbuild_generator.exe --input ..\src\dev\ --mode cpp >> build_cpp.msbuild
msbuild_generator.exe --input ..\src\pch\ --mode cpp >> build_cpp.msbuild

echo ^</Project^> >> build_cpp.msbuild

echo ^<?xml version="1.0" encoding="utf-8"?^> > build_idl.msbuild
echo ^<Project DefaultTargets="Build" ToolsVersion="15.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003"^> >> build_idl.msbuild

msbuild_generator.exe --input ..\src\idl\ --mode idl >> build_idl.msbuild

echo ^</Project^> >> build_idl.msbuild



echo ^<?xml version="1.0" encoding="utf-8"?^> > build.vcxproj.filters
echo ^<Project DefaultTargets="Build" ToolsVersion="15.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003"^> >> build.vcxproj.filters

msbuild_generator.exe --type filters --input ..\src\dev\ --mode h >> build.vcxproj.filters
msbuild_generator.exe --type filters --input ..\src\pch\ --mode h >> build.vcxproj.filters
msbuild_generator.exe --type filters --input ..\src\dev\ --mode cpp >> build.vcxproj.filters
msbuild_generator.exe --type filters --input ..\src\pch\ --mode cpp >> build.vcxproj.filters
msbuild_generator.exe --type filters --input ..\src\idl\ --mode idl >> build.vcxproj.filters

echo ^</Project^> >> build.vcxproj.filters





