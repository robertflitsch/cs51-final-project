# Install script for directory: /home/jharvard/Downloads/OpenCV-2.3.1/modules

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "RELEASE")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/calib3d/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/core/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/features2d/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/flann/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/ts/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/highgui/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/imgproc/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/legacy/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/contrib/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/ml/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/objdetect/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/video/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/traincascade/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/haartraining/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/cmake_install.cmake")
  INCLUDE("/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

