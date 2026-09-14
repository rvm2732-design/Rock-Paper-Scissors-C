@echo off
setlocal enabledelayedexpansion

echo =========================================
echo   Rock Paper Scissors - Build Verification
echo =========================================
echo.

set MISSING=0

echo Checking required files...
for %%F in (main.c game.c game.h menu.c menu.h RockPaperScissorsanimation\animation.c RockPaperScissorsanimation\animation.h) do (
    if exist "%%F" (
        echo   [OK]   %%F
    ) else (
        echo   [MISS] %%F
        set MISSING=1
    )
)

echo.

if %MISSING%==1 (
    echo One or more files are missing. Fix the paths above before building.
    goto :end
)

echo All files found. Attempting to compile...
echo.

gcc -Wall -Wextra -std=c11 main.c game.c menu.c RockPaperScissorsanimation\animation.c -o rps.exe

if %ERRORLEVEL%==0 (
    echo.
    echo =========================================
    echo   BUILD SUCCESSFUL - rps.exe created
    echo =========================================
    echo Run it with: rps.exe
) else (
    echo.
    echo =========================================
    echo   BUILD FAILED - see errors above
    echo =========================================
)

:end
echo.
pause