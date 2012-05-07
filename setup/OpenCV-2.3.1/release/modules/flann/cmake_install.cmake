# Install script for directory: /home/jharvard/Downloads/OpenCV-2.3.1/modules/flann

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
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libopencv_flann.so.2.3.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libopencv_flann.so.2.3"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libopencv_flann.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "/usr/local/lib")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/jharvard/Downloads/OpenCV-2.3.1/release/lib/libopencv_flann.so.2.3.1"
    "/home/jharvard/Downloads/OpenCV-2.3.1/release/lib/libopencv_flann.so.2.3"
    "/home/jharvard/Downloads/OpenCV-2.3.1/release/lib/libopencv_flann.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libopencv_flann.so.2.3.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libopencv_flann.so.2.3"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libopencv_flann.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/jharvard/Downloads/OpenCV-2.3.1/release/lib:"
           NEW_RPATH "/usr/local/lib")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/flann" TYPE FILE FILES
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/dist.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/linear_index.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/flann_base.hpp"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/result_set.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/simplex_downhill.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/ground_truth.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/heap.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/index_testing.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/miniflann.hpp"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/autotuned_index.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/sampling.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/kmeans_index.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/dynamic_bitset.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/timer.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/composite_index.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/flann.hpp"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/object_factory.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/logger.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/any.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/config.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/params.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/kdtree_index.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/hdf5.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/defines.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/matrix.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/kdtree_single_index.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/general.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/lsh_index.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/dummy.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/allocator.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/random.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/all_indices.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/lsh_table.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/nn_index.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/saving.h"
    "/home/jharvard/Downloads/OpenCV-2.3.1/modules/flann/include/opencv2/flann/hierarchical_clustering_index.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")

