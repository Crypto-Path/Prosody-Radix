@echo off
setlocal

:: Set the project directory (modify if needed)
set DIR=%CD%

:: Compile the project using Emscripten
emcc main.c -o index.html -s USE_GLFW=3 -s WASM=1 ^
    -I %DIR%\raylib\src ^
    -L %DIR%\raylib\src ^
    -lraylib.web -s ERROR_ON_UNDEFINED_SYMBOLS=0

if %ERRORLEVEL% neq 0 (
    echo Compilation failed!
    exit /b %ERRORLEVEL%
)

echo Compilation successful! index.html and WebAssembly output generated.

endlocal