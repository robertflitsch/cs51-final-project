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

# Utility rule file for pch_Generate_opencv_contrib.

# Include the progress variables for this target.
include modules/contrib/CMakeFiles/pch_Generate_opencv_contrib.dir/progress.make

modules/contrib/CMakeFiles/pch_Generate_opencv_contrib: modules/contrib/precomp.hpp.gch/opencv_contrib_RELEASE.gch

modules/contrib/precomp.hpp.gch/opencv_contrib_RELEASE.gch: ../modules/contrib/src/precomp.hpp
modules/contrib/precomp.hpp.gch/opencv_contrib_RELEASE.gch: modules/contrib/precomp.hpp
modules/contrib/precomp.hpp.gch/opencv_contrib_RELEASE.gch: lib/libopencv_contrib_pch_dephelp.a
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating precomp.hpp.gch/opencv_contrib_RELEASE.gch"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/contrib && /usr/bin/cmake -E make_directory /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/contrib/precomp.hpp.gch
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/contrib && /usr/bin/c++ -O3 -DNDEBUG -fomit-frame-pointer -msse -msse2 -mfpmath=387 -DNDEBUG -fPIC -I"/home/jharvard/Downloads/OpenCV-2.3.1/." -I"/home/jharvard/Downloads/OpenCV-2.3.1/release" -I"/home/jharvard/Downloads/OpenCV-2.3.1/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/include/opencv" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib/src" -I"/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/contrib" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib/../core/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib/../imgproc/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib/../calib3d/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib/../features2d/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib/../highgui/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib/../ml/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib/../video/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib/../objdetect/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib/../flann/include" -DHAVE_CVCONFIG_H -DCVAPI_EXPORTS -DHAVE_CVCONFIG_H -Wall -pthread -march=i686 -ffunction-sections -x c++-header -o /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/contrib/precomp.hpp.gch/opencv_contrib_RELEASE.gch /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/contrib/precomp.hpp

modules/contrib/precomp.hpp: ../modules/contrib/src/precomp.hpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating precomp.hpp"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/contrib && /usr/bin/cmake -E copy /home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib/src/precomp.hpp /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/contrib/precomp.hpp

pch_Generate_opencv_contrib: modules/contrib/CMakeFiles/pch_Generate_opencv_contrib
pch_Generate_opencv_contrib: modules/contrib/precomp.hpp.gch/opencv_contrib_RELEASE.gch
pch_Generate_opencv_contrib: modules/contrib/precomp.hpp
pch_Generate_opencv_contrib: modules/contrib/CMakeFiles/pch_Generate_opencv_contrib.dir/build.make
.PHONY : pch_Generate_opencv_contrib

# Rule to build all files generated by this target.
modules/contrib/CMakeFiles/pch_Generate_opencv_contrib.dir/build: pch_Generate_opencv_contrib
.PHONY : modules/contrib/CMakeFiles/pch_Generate_opencv_contrib.dir/build

modules/contrib/CMakeFiles/pch_Generate_opencv_contrib.dir/clean:
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/contrib && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_opencv_contrib.dir/cmake_clean.cmake
.PHONY : modules/contrib/CMakeFiles/pch_Generate_opencv_contrib.dir/clean

modules/contrib/CMakeFiles/pch_Generate_opencv_contrib.dir/depend:
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jharvard/Downloads/OpenCV-2.3.1 /home/jharvard/Downloads/OpenCV-2.3.1/modules/contrib /home/jharvard/Downloads/OpenCV-2.3.1/release /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/contrib /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/contrib/CMakeFiles/pch_Generate_opencv_contrib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/contrib/CMakeFiles/pch_Generate_opencv_contrib.dir/depend

