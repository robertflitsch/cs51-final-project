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

# Utility rule file for pch_Generate_opencv_video.

# Include the progress variables for this target.
include modules/video/CMakeFiles/pch_Generate_opencv_video.dir/progress.make

modules/video/CMakeFiles/pch_Generate_opencv_video: modules/video/precomp.hpp.gch/opencv_video_RELEASE.gch

modules/video/precomp.hpp.gch/opencv_video_RELEASE.gch: ../modules/video/src/precomp.hpp
modules/video/precomp.hpp.gch/opencv_video_RELEASE.gch: modules/video/precomp.hpp
modules/video/precomp.hpp.gch/opencv_video_RELEASE.gch: lib/libopencv_video_pch_dephelp.a
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating precomp.hpp.gch/opencv_video_RELEASE.gch"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/video && /usr/bin/cmake -E make_directory /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/video/precomp.hpp.gch
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/video && /usr/bin/c++ -O3 -DNDEBUG -fomit-frame-pointer -msse -msse2 -mfpmath=387 -DNDEBUG -fPIC -I"/home/jharvard/Downloads/OpenCV-2.3.1/." -I"/home/jharvard/Downloads/OpenCV-2.3.1/release" -I"/home/jharvard/Downloads/OpenCV-2.3.1/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/include/opencv" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/video/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/video/src" -I"/home/jharvard/Downloads/OpenCV-2.3.1/release/modules/video" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/video/../core/include" -I"/home/jharvard/Downloads/OpenCV-2.3.1/modules/video/../imgproc/include" -DHAVE_CVCONFIG_H -DCVAPI_EXPORTS -DHAVE_CVCONFIG_H -Wall -pthread -march=i686 -ffunction-sections -x c++-header -o /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/video/precomp.hpp.gch/opencv_video_RELEASE.gch /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/video/precomp.hpp

modules/video/precomp.hpp: ../modules/video/src/precomp.hpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating precomp.hpp"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/video && /usr/bin/cmake -E copy /home/jharvard/Downloads/OpenCV-2.3.1/modules/video/src/precomp.hpp /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/video/precomp.hpp

pch_Generate_opencv_video: modules/video/CMakeFiles/pch_Generate_opencv_video
pch_Generate_opencv_video: modules/video/precomp.hpp.gch/opencv_video_RELEASE.gch
pch_Generate_opencv_video: modules/video/precomp.hpp
pch_Generate_opencv_video: modules/video/CMakeFiles/pch_Generate_opencv_video.dir/build.make
.PHONY : pch_Generate_opencv_video

# Rule to build all files generated by this target.
modules/video/CMakeFiles/pch_Generate_opencv_video.dir/build: pch_Generate_opencv_video
.PHONY : modules/video/CMakeFiles/pch_Generate_opencv_video.dir/build

modules/video/CMakeFiles/pch_Generate_opencv_video.dir/clean:
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/video && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_opencv_video.dir/cmake_clean.cmake
.PHONY : modules/video/CMakeFiles/pch_Generate_opencv_video.dir/clean

modules/video/CMakeFiles/pch_Generate_opencv_video.dir/depend:
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jharvard/Downloads/OpenCV-2.3.1 /home/jharvard/Downloads/OpenCV-2.3.1/modules/video /home/jharvard/Downloads/OpenCV-2.3.1/release /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/video /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/video/CMakeFiles/pch_Generate_opencv_video.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/video/CMakeFiles/pch_Generate_opencv_video.dir/depend

