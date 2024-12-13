@echo off
:: Set text color to green (light green)
:: Header and copyright statement
color
echo ============================================
echo           Robotistan INC - 2024
echo      REX Board MicroPython Flasher
echo ============================================

setlocal enabledelayedexpansion

color 06
echo Listing COM ports and device paths...

:: COM portlarını listele ve her iki bilgiyi de yazdır
for /f "tokens=1,3" %%a in ('reg query "HKLM\HARDWARE\DEVICEMAP\SERIALCOMM" /s 2^>nul ^| findstr /v "HKEY_LOCAL_MACHINE\HARDWARE\DEVICEMAP\SERIALCOMM"') do (
    set COMPORT=%%a
    set DEVICEPATH=%%b
    echo !COMPORT! ^	COM Port: !DEVICEPATH!
)
echo.
echo Please enter the COM port you want to use (example: COM3):
set /p COMPORT=COM Port: 

:: Flash'i temizle ve dosyayi yazdir
echo Erasing ESP32 flash...
esptool.exe --port %COMPORT% erase_flash

echo Writing ESP32_V1.22.bin to port %COMPORT%...
esptool.exe --port %COMPORT% --baud 460800 write_flash 0x1000 ESP32_V1.22.bin

echo Process completed successfully.
pause

