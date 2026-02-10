@echo off
cd /d c:\a_VsCode\clessons\exercises
echo Compilazione in corso...
C:\msys64\ucrt64\bin\g++.exe -std=c++17 es_19_rifatto.cpp -o es_19_rifatto.exe
if %errorlevel% neq 0 (
    echo Errore di compilazione!
    pause
    exit /b 1
)
echo Compilazione completata!
echo.
echo Esecuzione del programma:
echo ========================
es_19_rifatto.exe
pause
