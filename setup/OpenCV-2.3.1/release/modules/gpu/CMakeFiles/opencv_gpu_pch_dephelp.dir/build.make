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

# Include any dependencies generated for this target.
include modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/depend.make

# Include the progress variables for this target.
include modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/progress.make

# Include the compile flags for this target's objects.
include modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/flags.make

modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o: modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/flags.make
modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o: modules/gpu/opencv_gpu_pch_dephelp.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o -c /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/opencv_gpu_pch_dephelp.cxx

modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.i"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/opencv_gpu_pch_dephelp.cxx > CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.i

modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.s"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/opencv_gpu_pch_dephelp.cxx -o CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.s

modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o.requires:
.PHONY : modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o.requires

modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o.provides: modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o.requires
	$(MAKE) -f modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/build.make modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o.provides.build
.PHONY : modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o.provides

modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o.provides.build: modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o

modules/gpu/opencv_gpu_pch_dephelp.cxx: ../modules/gpu/src/precomp.hpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating opencv_gpu_pch_dephelp.cxx"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && /usr/bin/cmake -E echo \#include\ \"/home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu/src/precomp.hpp\" > /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/opencv_gpu_pch_dephelp.cxx
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && /usr/bin/cmake -E echo int\ testfunction\(\) >> /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/opencv_gpu_pch_dephelp.cxx
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && /usr/bin/cmake -E echo { >> /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/opencv_gpu_pch_dephelp.cxx
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && /usr/bin/cmake -E echo \ \ \ \ \return\ 0\; >> /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/opencv_gpu_pch_dephelp.cxx
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && /usr/bin/cmake -E echo } >> /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/opencv_gpu_pch_dephelp.cxx

# Object files for target opencv_gpu_pch_dephelp
opencv_gpu_pch_dephelp_OBJECTS = \
"CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o"

# External object files for target opencv_gpu_pch_dephelp
opencv_gpu_pch_dephelp_EXTERNAL_OBJECTS =

lib/libopencv_gpu_pch_dephelp.a: modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o
lib/libopencv_gpu_pch_dephelp.a: modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/build.make
lib/libopencv_gpu_pch_dephelp.a: modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../../lib/libopencv_gpu_pch_dephelp.a"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && $(CMAKE_COMMAND) -P CMakeFiles/opencv_gpu_pch_dephelp.dir/cmake_clean_target.cmake
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_gpu_pch_dephelp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/build: lib/libopencv_gpu_pch_dephelp.a
.PHONY : modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/build

modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/requires: modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/opencv_gpu_pch_dephelp.o.requires
.PHONY : modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/requires

modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/clean:
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu && $(CMAKE_COMMAND) -P CMakeFiles/opencv_gpu_pch_dephelp.dir/cmake_clean.cmake
.PHONY : modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/clean

modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/depend: modules/gpu/opencv_gpu_pch_dephelp.cxx
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jharvard/Downloads/OpenCV-2.3.1 /home/jharvard/Downloads/OpenCV-2.3.1/modules/gpu /home/jharvard/Downloads/OpenCV-2.3.1/release /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/gpu/CMakeFiles/opencv_gpu_pch_dephelp.dir/depend

