@echo off

cd /d %~dp0

if not exist release mkdir release

g++ -std=c++17 -O2 -Wall -Wextra src/main.cpp src/playground.cpp src/gameplay.cpp icon.res -o release/TicTacToe.exe -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows

if %errorlevel% neq 0 (
    echo.
    echo Release-Build fehlgeschlagen.
    pause
    exit /b %errorlevel%
)

echo.
echo Release-Build erfolgreich.
echo Datei: release\TicTacToe.exe

pause