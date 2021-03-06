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

# Utility rule file for pch_Generate_opencv_gpu.

# Include the progress variables for this target.
include modules/gpu/CMakeFiles/pch_Generate_opencv_gpu.dir/progress.make

modules/gpu/CMakeFiles/pch_Generate_opencv_gpu: modules/gpu/precomp.hpp.gch/opencv_gpu_RELEASE.gch

modules/gpu/precomp.hpp.gch/opencv_gpu_RELEASE.gch: ../modules/gpu/src/precomp.hpp
modules/gpu/precomp.hpp.gch/opencv_gpu_RELEASE.gch: modules/gpu/precomp.hpp
modules/gpu/precomp.hpp.gch/opencv_gpu_RELEASE.gch: lib/libopencv_gpu_pch_dephelp.a
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating precomp.hpp.gch/opencv_gpu_RELEASE.gch"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && /usr/bin/cmake -E make_directory /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/precomp.hpp.gch
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && /usr/bin/c++ -O3 -DNDEBUG -fomit-frame-pointer -msse -msse2 -mfpmath=387 -DNDEBUG -fPIC -I"/home/jharvard/Downloads/OpenCV-2.3.1/." -I"/home/jharvard/Downloads/OpenCV-2.3.1/release" -I"/home/jharvard/Downloads/OpenCV-2.3.1/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/include/opencv" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu/src/cuda" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu/src" -I"/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu/../core/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu/../imgproc/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu/../objdetect/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu/../features2d/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu/../flann/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu/../calib3d/include" -DHAVE_CVCONFIG_H -DCVAPI_EXPORTS -DHAVE_CVCONFIG_H -Wall -pthread -march=i686 -ffunction-sections -x c++-header -o /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/precomp.hpp.gch/opencv_gpu_RELEASE.gch /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/precomp.hpp

modules/gpu/precomp.hpp: ../modules/gpu/src/precomp.hpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating precomp.hpp"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && /usr/bin/cmake -E copy /home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu/src/precomp.hpp /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/precomp.hpp

pch_Generate_opencv_gpu: modules/gpu/CMakeFiles/pch_Generate_opencv_gpu
pch_Generate_opencv_gpu: modules/gpu/precomp.hpp.gch/opencv_gpu_RELEASE.gch
pch_Generate_opencv_gpu: modules/gpu/precomp.hpp
pch_Generate_opencv_gpu: modules/gpu/CMakeFiles/pch_Generate_opencv_gpu.dir/build.make
.PHONY : pch_Generate_opencv_gpu

# Rule to build all files generated by this target.
modules/gpu/CMakeFiles/pch_Generate_opencv_gpu.dir/build: pch_Generate_opencv_gpu
.PHONY : modules/gpu/CMakeFiles/pch_Generate_opencv_gpu.dir/build

modules/gpu/CMakeFiles/pch_Generate_opencv_gpu.dir/clean:
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_opencv_gpu.dir/cmake_clean.cmake
.PHONY : modules/gpu/CMakeFiles/pch_Generate_opencv_gpu.dir/clean

modules/gpu/CMakeFiles/pch_Generate_opencv_gpu.dir/depend:
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jharvard/Downloads/OpenCV-2.3.1 /home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu /home/jharvard/Downloads/OpenCV-2.3.1/release /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/CMakeFiles/pch_Generate_opencv_gpu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/gpu/CMakeFiles/pch_Generate_opencv_gpu.dir/depend

