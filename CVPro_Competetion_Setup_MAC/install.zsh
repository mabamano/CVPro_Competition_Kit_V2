#!/bin/zsh

# Install the ESP32 core
arduino-cli core install esp32:esp32@2.0.17

# Install the required libraries
arduino-cli lib install NewPing@1.9.7
arduino-cli lib install FastLED@3.7.0
arduino-cli lib install ESP32Servo@1.2.1
arduino-cli lib install "Adafruit BusIO@1.16.1"
arduino-cli lib install "Adafruit TCS34725@1.4.4"
arduino-cli lib install "Adafruit SSD1306@2.5.10"
arduino-cli lib install "Adafruit GFX Library@1.11.10"

# Open the specified folder
open "$HOME/CVPro_Competition_Kit-main/Firmware/Bot Test Codes"
