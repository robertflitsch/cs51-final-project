# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jharvard/Downloads/OpenCV-2.3.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jharvard/Downloads/OpenCV-2.3.1/release

# Utility rule file for pch_Generate_opencv_test_highgui.

# Include the progress variables for this target.
include modules/highgui/CMakeFiles/pch_Generate_opencv_test_highgui.dir/progress.make

modules/highgui/CMakeFiles/pch_Generate_opencv_test_highgui: modules/highgui/test_precomp.hpp.gch/opencv_test_highgui_RELEASE.gch

modules/highgui/test_precomp.hpp.gch/opencv_test_highgui_RELEASE.gch: ../modules/highgui/test/test_precomp.hpp
modules/highgui/test_precomp.hpp.gch/opencv_test_highgui_RELEASE.gch: modules/highgui/test_precomp.hpp
modules/highgui/test_precomp.hpp.gch/opencv_test_highgui_RELEASE.gch: lib/libopencv_test_highgui_pch_dephelp.a
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating test_precomp.hpp.gch/opencv_test_highgui_RELEASE.gch"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/highgui && /usr/bin/cmake -E make_directory /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/highgui/test_precomp.hpp.gch
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/highgui && /usr/bin/c++ -O3 -DNDEBUG -fomit-frame-pointer -msse -msse2 -mfpmath=387 -DNDEBUG -I"/home/jharvard/Downloads/OpenCV-2.3.1/." -I"/home/jharvard/Downloads/OpenCV-2.3.1/release" -I"/home/jharvard/Downloads/OpenCV-2.3.1/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/include/opencv" -I"/usr/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui/../../3rdparty/libjpeg" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui/../../3rdparty/libpng" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui/../../3rdparty/libtiff" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui/../../3rdparty/libjasper" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui/../core/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui/../imgproc/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui/src" -I"/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/highgui" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui/test" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui/../ts/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui/../highgui/include" -DHAVE_CVCONFIG_H -DHAVE_JPEG -DHAVE_PNG -DHAVE_TIFF -DHAVE_JASPER -DHIGHGUI_EXPORTS -DCVAPI_EXPORTS -DHAVE_CVCONFIG_H -Wall -pthread -march=i686 -ffunction-sections -x c++-header -o /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/highgui/test_precomp.hpp.gch/opencv_test_highgui_RELEASE.gch /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/highgui/test_precomp.hpp

modules/highgui/test_precomp.hpp: ../modules/highgui/test/test_precomp.hpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating test_precomp.hpp"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/highgui && /usr/bin/cmake -E copy /home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui/test/test_precomp.hpp /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/highgui/test_precomp.hpp

pch_Generate_opencv_test_highgui: modules/highgui/CMakeFiles/pch_Generate_opencv_test_highgui
pch_Generate_opencv_test_highgui: modules/highgui/test_precomp.hpp.gch/opencv_test_highgui_RELEASE.gch
pch_Generate_opencv_test_highgui: modules/highgui/test_precomp.hpp
pch_Generate_opencv_test_highgui: modules/highgui/CMakeFiles/pch_Generate_opencv_test_highgui.dir/build.make
.PHONY : pch_Generate_opencv_test_highgui

# Rule to build all files generated by this target.
modules/highgui/CMakeFiles/pch_Generate_opencv_test_highgui.dir/build: pch_Generate_opencv_test_highgui
.PHONY : modules/highgui/CMakeFiles/pch_Generate_opencv_test_highgui.dir/build

modules/highgui/CMakeFiles/pch_Generate_opencv_test_highgui.dir/clean:
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/highgui && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_opencv_test_highgui.dir/cmake_clean.cmake
.PHONY : modules/highgui/CMakeFiles/pch_Generate_opencv_test_highgui.dir/clean

modules/highgui/CMakeFiles/pch_Generate_opencv_test_highgui.dir/depend:
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jharvard/Downloads/OpenCV-2.3.1 /home/jharvard/Downloads/OpenCV-2.3.1/modules/highgui /home/jharvard/Downloads/OpenCV-2.3.1/release /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/highgui /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/highgui/CMakeFiles/pch_Generate_opencv_test_highgui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/highgui/CMakeFiles/pch_Generate_opencv_test_highgui.dir/depend

