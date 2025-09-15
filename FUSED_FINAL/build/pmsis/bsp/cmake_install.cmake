# Install script for directory: /home/bomps/Scrivania/workfile/gap_sdk_private/rtos/pmsis/bsp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/adc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/boards/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/bt/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/buffer/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/camera/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/crc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/dac/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/display/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/eeprom/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/flash/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/gauge/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/gpio/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/mic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/powersupply/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/bomps/Scrivania/workfile/DATE_BEAMFORMING/FUSED_FINAL/build/pmsis/bsp/ram/cmake_install.cmake")
endif()

