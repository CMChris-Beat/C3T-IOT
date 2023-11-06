# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Espressif/frameworks/esp-idf-v5.0/components/bootloader/subproject"
  "C:/Users/zhcne/Desktop/C3T-IOT/C3T/cmake-build-debug-esp32/bootloader"
  "C:/Users/zhcne/Desktop/C3T-IOT/C3T/cmake-build-debug-esp32/bootloader-prefix"
  "C:/Users/zhcne/Desktop/C3T-IOT/C3T/cmake-build-debug-esp32/bootloader-prefix/tmp"
  "C:/Users/zhcne/Desktop/C3T-IOT/C3T/cmake-build-debug-esp32/bootloader-prefix/src/bootloader-stamp"
  "C:/Users/zhcne/Desktop/C3T-IOT/C3T/cmake-build-debug-esp32/bootloader-prefix/src"
  "C:/Users/zhcne/Desktop/C3T-IOT/C3T/cmake-build-debug-esp32/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/zhcne/Desktop/C3T-IOT/C3T/cmake-build-debug-esp32/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
