@echo off
title Compilador RPG C++

echo Comprobando el compilador g++ (MinGW)...
where g++ >nul 2>&1
if %errorlevel% neq 0 (
    echo [ERROR] No se encontro g++ (MinGW) instalado o en las variables de entorno (PATH).
    echo Para compilar el codigo C++, debes instalar MinGW o abrir los archivos en un IDE como Visual Studio o Code::Blocks.
    echo.
    pause
    exit /b
)

echo [1/2] Compilando archivos C++...
if not exist "bin" mkdir bin
g++ src\main.cpp -o bin\RPG_Juego.exe

if %errorlevel% neq 0 (
    echo [ERROR] Hubo un problema al compilar.
    pause
    exit /b
)

echo [2/2] Ejecutando juego en consola...
echo.
cd bin
RPG_Juego.exe
cd ..
pause
