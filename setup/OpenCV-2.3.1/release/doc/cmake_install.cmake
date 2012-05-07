# Install script for directory: /home/jharvard/Downloads/OpenCV-2.3.1/doc

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

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/OpenCV/doc" TYPE FILE FILES
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/haartraining.htm"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/check_docs_whitelist.txt"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/packaging.txt"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/license.txt"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/CMakeLists.txt"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/opencv.jpg"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/opencv-logo2.png"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/acircles_pattern.png"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/opencv-logo.png"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/pattern.png"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/opencv_tutorials.pdf"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/opencv_user.pdf"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/opencv_cheatsheet.pdf"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/opencv2refman.pdf"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/OpenCV/doc/vidsurv" TYPE FILE FILES
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/vidsurv/Blob_Tracking_Tests.doc"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/vidsurv/TestSeq.doc"
    "/home/jharvard/Downloads/OpenCV-2.3.1/doc/vidsurv/Blob_Tracking_Modules.doc"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")

