@echo off
cd /d %~dp0

if not exist build mkdir build

g++ -std=c++17 -Wall -Wextra -g src/main.cpp -o build/game.exe -lraylib -lopengl32 -lgdi32 -lwinmm

if %errorlevel% neq 0 (
    echo.
    echo Build fehlgeschlagen.
    pause
    exit /b %errorlevel%
)

echo.
echo Build erfolgreich. Starte Spiel...
build\game.exe