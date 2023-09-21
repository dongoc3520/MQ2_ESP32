# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/EMBEDDED/ESP32/ESP32_IDF/Espressif/frameworks/esp-idf-v4.4.5/components/bootloader/subproject"
  "E:/EMBEDDED/ESP32/ESP32_IDF/Espressif/frameworks/esp-idf-v4.4.5/examples/get-started/BAI2_GPIO_INPUT/build/bootloader"
  "E:/EMBEDDED/ESP32/ESP32_IDF/Espressif/frameworks/esp-idf-v4.4.5/examples/get-started/BAI2_GPIO_INPUT/build/bootloader-prefix"
  "E:/EMBEDDED/ESP32/ESP32_IDF/Espressif/frameworks/esp-idf-v4.4.5/examples/get-started/BAI2_GPIO_INPUT/build/bootloader-prefix/tmp"
  "E:/EMBEDDED/ESP32/ESP32_IDF/Espressif/frameworks/esp-idf-v4.4.5/examples/get-started/BAI2_GPIO_INPUT/build/bootloader-prefix/src/bootloader-stamp"
  "E:/EMBEDDED/ESP32/ESP32_IDF/Espressif/frameworks/esp-idf-v4.4.5/examples/get-started/BAI2_GPIO_INPUT/build/bootloader-prefix/src"
  "E:/EMBEDDED/ESP32/ESP32_IDF/Espressif/frameworks/esp-idf-v4.4.5/examples/get-started/BAI2_GPIO_INPUT/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/EMBEDDED/ESP32/ESP32_IDF/Espressif/frameworks/esp-idf-v4.4.5/examples/get-started/BAI2_GPIO_INPUT/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
