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
include modules/stitching/CMakeFiles/opencv_stitching.dir/depend.make

# Include the progress variables for this target.
include modules/stitching/CMakeFiles/opencv_stitching.dir/progress.make

# Include the compile flags for this target's objects.
include modules/stitching/CMakeFiles/opencv_stitching.dir/flags.make

modules/stitching/CMakeFiles/opencv_stitching.dir/util.o: modules/stitching/CMakeFiles/opencv_stitching.dir/flags.make
modules/stitching/CMakeFiles/opencv_stitching.dir/util.o: ../modules/stitching/util.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/stitching/CMakeFiles/opencv_stitching.dir/util.o"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_stitching.dir/util.o -c /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/util.cpp

modules/stitching/CMakeFiles/opencv_stitching.dir/util.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_stitching.dir/util.i"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/util.cpp > CMakeFiles/opencv_stitching.dir/util.i

modules/stitching/CMakeFiles/opencv_stitching.dir/util.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_stitching.dir/util.s"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/util.cpp -o CMakeFiles/opencv_stitching.dir/util.s

modules/stitching/CMakeFiles/opencv_stitching.dir/util.o.requires:
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/util.o.requires

modules/stitching/CMakeFiles/opencv_stitching.dir/util.o.provides: modules/stitching/CMakeFiles/opencv_stitching.dir/util.o.requires
	$(MAKE) -f modules/stitching/CMakeFiles/opencv_stitching.dir/build.make modules/stitching/CMakeFiles/opencv_stitching.dir/util.o.provides.build
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/util.o.provides

modules/stitching/CMakeFiles/opencv_stitching.dir/util.o.provides.build: modules/stitching/CMakeFiles/opencv_stitching.dir/util.o

modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o: modules/stitching/CMakeFiles/opencv_stitching.dir/flags.make
modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o: ../modules/stitching/seam_finders.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_stitching.dir/seam_finders.o -c /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/seam_finders.cpp

modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_stitching.dir/seam_finders.i"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/seam_finders.cpp > CMakeFiles/opencv_stitching.dir/seam_finders.i

modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_stitching.dir/seam_finders.s"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/seam_finders.cpp -o CMakeFiles/opencv_stitching.dir/seam_finders.s

modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o.requires:
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o.requires

modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o.provides: modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o.requires
	$(MAKE) -f modules/stitching/CMakeFiles/opencv_stitching.dir/build.make modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o.provides.build
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o.provides

modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o.provides.build: modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o

modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o: modules/stitching/CMakeFiles/opencv_stitching.dir/flags.make
modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o: ../modules/stitching/warpers.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_stitching.dir/warpers.o -c /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/warpers.cpp

modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_stitching.dir/warpers.i"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/warpers.cpp > CMakeFiles/opencv_stitching.dir/warpers.i

modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_stitching.dir/warpers.s"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/warpers.cpp -o CMakeFiles/opencv_stitching.dir/warpers.s

modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o.requires:
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o.requires

modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o.provides: modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o.requires
	$(MAKE) -f modules/stitching/CMakeFiles/opencv_stitching.dir/build.make modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o.provides.build
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o.provides

modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o.provides.build: modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o

modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o: modules/stitching/CMakeFiles/opencv_stitching.dir/flags.make
modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o: ../modules/stitching/exposure_compensate.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_stitching.dir/exposure_compensate.o -c /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/exposure_compensate.cpp

modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_stitching.dir/exposure_compensate.i"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/exposure_compensate.cpp > CMakeFiles/opencv_stitching.dir/exposure_compensate.i

modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_stitching.dir/exposure_compensate.s"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/exposure_compensate.cpp -o CMakeFiles/opencv_stitching.dir/exposure_compensate.s

modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o.requires:
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o.requires

modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o.provides: modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o.requires
	$(MAKE) -f modules/stitching/CMakeFiles/opencv_stitching.dir/build.make modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o.provides.build
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o.provides

modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o.provides.build: modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o

modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o: modules/stitching/CMakeFiles/opencv_stitching.dir/flags.make
modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o: ../modules/stitching/precomp.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_stitching.dir/precomp.o -c /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/precomp.cpp

modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_stitching.dir/precomp.i"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/precomp.cpp > CMakeFiles/opencv_stitching.dir/precomp.i

modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_stitching.dir/precomp.s"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/precomp.cpp -o CMakeFiles/opencv_stitching.dir/precomp.s

modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o.requires:
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o.requires

modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o.provides: modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o.requires
	$(MAKE) -f modules/stitching/CMakeFiles/opencv_stitching.dir/build.make modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o.provides.build
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o.provides

modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o.provides.build: modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o

modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o: modules/stitching/CMakeFiles/opencv_stitching.dir/flags.make
modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o: ../modules/stitching/motion_estimators.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_stitching.dir/motion_estimators.o -c /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/motion_estimators.cpp

modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_stitching.dir/motion_estimators.i"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/motion_estimators.cpp > CMakeFiles/opencv_stitching.dir/motion_estimators.i

modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_stitching.dir/motion_estimators.s"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/motion_estimators.cpp -o CMakeFiles/opencv_stitching.dir/motion_estimators.s

modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o.requires:
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o.requires

modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o.provides: modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o.requires
	$(MAKE) -f modules/stitching/CMakeFiles/opencv_stitching.dir/build.make modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o.provides.build
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o.provides

modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o.provides.build: modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o

modules/stitching/CMakeFiles/opencv_stitching.dir/main.o: modules/stitching/CMakeFiles/opencv_stitching.dir/flags.make
modules/stitching/CMakeFiles/opencv_stitching.dir/main.o: ../modules/stitching/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/stitching/CMakeFiles/opencv_stitching.dir/main.o"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_stitching.dir/main.o -c /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/main.cpp

modules/stitching/CMakeFiles/opencv_stitching.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_stitching.dir/main.i"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/main.cpp > CMakeFiles/opencv_stitching.dir/main.i

modules/stitching/CMakeFiles/opencv_stitching.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_stitching.dir/main.s"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/main.cpp -o CMakeFiles/opencv_stitching.dir/main.s

modules/stitching/CMakeFiles/opencv_stitching.dir/main.o.requires:
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/main.o.requires

modules/stitching/CMakeFiles/opencv_stitching.dir/main.o.provides: modules/stitching/CMakeFiles/opencv_stitching.dir/main.o.requires
	$(MAKE) -f modules/stitching/CMakeFiles/opencv_stitching.dir/build.make modules/stitching/CMakeFiles/opencv_stitching.dir/main.o.provides.build
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/main.o.provides

modules/stitching/CMakeFiles/opencv_stitching.dir/main.o.provides.build: modules/stitching/CMakeFiles/opencv_stitching.dir/main.o

modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o: modules/stitching/CMakeFiles/opencv_stitching.dir/flags.make
modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o: ../modules/stitching/autocalib.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_stitching.dir/autocalib.o -c /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/autocalib.cpp

modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_stitching.dir/autocalib.i"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/autocalib.cpp > CMakeFiles/opencv_stitching.dir/autocalib.i

modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_stitching.dir/autocalib.s"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/autocalib.cpp -o CMakeFiles/opencv_stitching.dir/autocalib.s

modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o.requires:
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o.requires

modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o.provides: modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o.requires
	$(MAKE) -f modules/stitching/CMakeFiles/opencv_stitching.dir/build.make modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o.provides.build
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o.provides

modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o.provides.build: modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o

modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o: modules/stitching/CMakeFiles/opencv_stitching.dir/flags.make
modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o: ../modules/stitching/blenders.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_stitching.dir/blenders.o -c /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/blenders.cpp

modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_stitching.dir/blenders.i"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/blenders.cpp > CMakeFiles/opencv_stitching.dir/blenders.i

modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_stitching.dir/blenders.s"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/blenders.cpp -o CMakeFiles/opencv_stitching.dir/blenders.s

modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o.requires:
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o.requires

modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o.provides: modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o.requires
	$(MAKE) -f modules/stitching/CMakeFiles/opencv_stitching.dir/build.make modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o.provides.build
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o.provides

modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o.provides.build: modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o

modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o: modules/stitching/CMakeFiles/opencv_stitching.dir/flags.make
modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o: ../modules/stitching/matchers.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jharvard/Downloads/OpenCV-2.3.1/release/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/opencv_stitching.dir/matchers.o -c /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/matchers.cpp

modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_stitching.dir/matchers.i"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/matchers.cpp > CMakeFiles/opencv_stitching.dir/matchers.i

modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_stitching.dir/matchers.s"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching/matchers.cpp -o CMakeFiles/opencv_stitching.dir/matchers.s

modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o.requires:
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o.requires

modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o.provides: modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o.requires
	$(MAKE) -f modules/stitching/CMakeFiles/opencv_stitching.dir/build.make modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o.provides.build
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o.provides

modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o.provides.build: modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o

# Object files for target opencv_stitching
opencv_stitching_OBJECTS = \
"CMakeFiles/opencv_stitching.dir/util.o" \
"CMakeFiles/opencv_stitching.dir/seam_finders.o" \
"CMakeFiles/opencv_stitching.dir/warpers.o" \
"CMakeFiles/opencv_stitching.dir/exposure_compensate.o" \
"CMakeFiles/opencv_stitching.dir/precomp.o" \
"CMakeFiles/opencv_stitching.dir/motion_estimators.o" \
"CMakeFiles/opencv_stitching.dir/main.o" \
"CMakeFiles/opencv_stitching.dir/autocalib.o" \
"CMakeFiles/opencv_stitching.dir/blenders.o" \
"CMakeFiles/opencv_stitching.dir/matchers.o"

# External object files for target opencv_stitching
opencv_stitching_EXTERNAL_OBJECTS =

bin/opencv_stitching: modules/stitching/CMakeFiles/opencv_stitching.dir/util.o
bin/opencv_stitching: modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o
bin/opencv_stitching: modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o
bin/opencv_stitching: modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o
bin/opencv_stitching: modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o
bin/opencv_stitching: modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o
bin/opencv_stitching: modules/stitching/CMakeFiles/opencv_stitching.dir/main.o
bin/opencv_stitching: modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o
bin/opencv_stitching: modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o
bin/opencv_stitching: modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o
bin/opencv_stitching: lib/libopencv_core.so.2.3.1
bin/opencv_stitching: lib/libopencv_imgproc.so.2.3.1
bin/opencv_stitching: lib/libopencv_highgui.so.2.3.1
bin/opencv_stitching: lib/libopencv_features2d.so.2.3.1
bin/opencv_stitching: lib/libopencv_calib3d.so.2.3.1
bin/opencv_stitching: lib/libopencv_gpu.so.2.3.1
bin/opencv_stitching: lib/libopencv_objdetect.so.2.3.1
bin/opencv_stitching: lib/libopencv_calib3d.so.2.3.1
bin/opencv_stitching: lib/libopencv_features2d.so.2.3.1
bin/opencv_stitching: lib/libopencv_highgui.so.2.3.1
bin/opencv_stitching: lib/libopencv_imgproc.so.2.3.1
bin/opencv_stitching: lib/libopencv_flann.so.2.3.1
bin/opencv_stitching: lib/libopencv_core.so.2.3.1
bin/opencv_stitching: /usr/lib/libz.so
bin/opencv_stitching: modules/stitching/CMakeFiles/opencv_stitching.dir/build.make
bin/opencv_stitching: modules/stitching/CMakeFiles/opencv_stitching.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/opencv_stitching"
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_stitching.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/stitching/CMakeFiles/opencv_stitching.dir/build: bin/opencv_stitching
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/build

modules/stitching/CMakeFiles/opencv_stitching.dir/requires: modules/stitching/CMakeFiles/opencv_stitching.dir/util.o.requires
modules/stitching/CMakeFiles/opencv_stitching.dir/requires: modules/stitching/CMakeFiles/opencv_stitching.dir/seam_finders.o.requires
modules/stitching/CMakeFiles/opencv_stitching.dir/requires: modules/stitching/CMakeFiles/opencv_stitching.dir/warpers.o.requires
modules/stitching/CMakeFiles/opencv_stitching.dir/requires: modules/stitching/CMakeFiles/opencv_stitching.dir/exposure_compensate.o.requires
modules/stitching/CMakeFiles/opencv_stitching.dir/requires: modules/stitching/CMakeFiles/opencv_stitching.dir/precomp.o.requires
modules/stitching/CMakeFiles/opencv_stitching.dir/requires: modules/stitching/CMakeFiles/opencv_stitching.dir/motion_estimators.o.requires
modules/stitching/CMakeFiles/opencv_stitching.dir/requires: modules/stitching/CMakeFiles/opencv_stitching.dir/main.o.requires
modules/stitching/CMakeFiles/opencv_stitching.dir/requires: modules/stitching/CMakeFiles/opencv_stitching.dir/autocalib.o.requires
modules/stitching/CMakeFiles/opencv_stitching.dir/requires: modules/stitching/CMakeFiles/opencv_stitching.dir/blenders.o.requires
modules/stitching/CMakeFiles/opencv_stitching.dir/requires: modules/stitching/CMakeFiles/opencv_stitching.dir/matchers.o.requires
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/requires

modules/stitching/CMakeFiles/opencv_stitching.dir/clean:
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching && $(CMAKE_COMMAND) -P CMakeFiles/opencv_stitching.dir/cmake_clean.cmake
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/clean

modules/stitching/CMakeFiles/opencv_stitching.dir/depend:
	cd /home/jharvard/Downloads/OpenCV-2.3.1/release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jharvard/Downloads/OpenCV-2.3.1 /home/jharvard/Downloads/OpenCV-2.3.1/modules/stitching /home/jharvard/Downloads/OpenCV-2.3.1/release /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching /home/jharvard/Downloads/OpenCV-2.3.1/release/modules/stitching/CMakeFiles/opencv_stitching.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/stitching/CMakeFiles/opencv_stitching.dir/depend

