@echo off

call arduino-cli core install esp32:esp32@2.0.17
call arduino-cli lib install NewPing@1.9.7
call arduino-cli lib install FastLED@3.7.0
call arduino-cli lib install ESP32Servo@1.2.1
call arduino-cli lib install "Adafruit BusIO@1.16.1"
call arduino-cli lib install "Adafruit TCS34725@1.4.4"

call explorer "%userProfile%\CVPro_Competition_Kit-main\Firmware\Bot Test Codes"
@REM call arduino-cli lib install "Adafruit SSD1306@2.5.10"
@REM call arduino-cli lib install "Adafruit GFX Library@1.11.10"