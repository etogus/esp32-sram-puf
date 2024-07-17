# ESP32-S3 SRAM

This project aims to analyze the contents of SRAM on an ESP32-S3 microcontroller at different stages of the boot process, specifically before bootloader initialization and after the main application starts running.

This project is a part of the larger project "Extraction of the SRAM-based PUF on the ESP32 platform".<br>
Next step is to capture the SRAM values from serial output:<br>
https://github.com/etogus/capture-esp32-output

## Features

- Reads SRAM content at two critical points: pre- and post- bootloader initialization
- Displays SRAM content in both hexadecimal and binary formats
- Allows for easy comparison of SRAM states to analyze initialization effects

## Purpose

This project is useful for developers working on low-level ESP32-S3 firmware who need to understand:

- Initial SRAM content before any system initialization
- How the bootloader and system initialization process affects SRAM contents
- Potential memory layout and usage patterns in the early boot stages

## Usage

To use this project, clone the repository and build it using the ESP-IDF toolchain. The output will show SRAM contents at two different stages, allowing for analysis and comparison.<br>

<b>Note</b>: This project is specifically designed for the ESP32-S3 microcontroller and may need modifications for other ESP32 variants.
