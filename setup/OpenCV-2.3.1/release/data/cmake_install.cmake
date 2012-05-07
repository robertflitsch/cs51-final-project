# Install script for directory: /home/jharvard/Downloads/OpenCV-2.3.1/data

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/OpenCV/haarcascades" TYPE FILE FILES
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_lefteye_2splits.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_frontalface_alt_tree.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_eye.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_mcs_leftear.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_frontalface_alt2.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_mcs_eyepair_small.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_righteye_2splits.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_profileface.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_mcs_nose.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_mcs_righteye.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_upperbody.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_mcs_rightear.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_mcs_eyepair_big.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_fullbody.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_mcs_lefteye.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_lowerbody.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_mcs_mouth.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_mcs_upperbody.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_frontalface_alt.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_frontalface_default.xml"
    "/home/jharvard/Downloads/OpenCV-2.3.1/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/OpenCV/lbpcascades" TYPE FILE FILES "/home/jharvard/Downloads/OpenCV-2.3.1/data/lbpcascades/lbpcascade_frontalface.xml")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")

