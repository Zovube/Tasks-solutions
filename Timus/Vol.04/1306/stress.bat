@echo off
:start
gen.exe
ML.exe
ggg.exe
fc ML.out xxx.out
if errorlevel 1 goto finish
goto start
:finish