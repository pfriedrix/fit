# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dnl-krsvch/Documents/Projects/FIT/algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mkr1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mkr1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mkr1.dir/flags.make

CMakeFiles/mkr1.dir/mkr.cpp.o: CMakeFiles/mkr1.dir/flags.make
CMakeFiles/mkr1.dir/mkr.cpp.o: ../mkr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mkr1.dir/mkr.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mkr1.dir/mkr.cpp.o -c /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/mkr.cpp

CMakeFiles/mkr1.dir/mkr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mkr1.dir/mkr.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/mkr.cpp > CMakeFiles/mkr1.dir/mkr.cpp.i

CMakeFiles/mkr1.dir/mkr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mkr1.dir/mkr.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/mkr.cpp -o CMakeFiles/mkr1.dir/mkr.cpp.s

# Object files for target mkr1
mkr1_OBJECTS = \
"CMakeFiles/mkr1.dir/mkr.cpp.o"

# External object files for target mkr1
mkr1_EXTERNAL_OBJECTS =

mkr1: CMakeFiles/mkr1.dir/mkr.cpp.o
mkr1: CMakeFiles/mkr1.dir/build.make
mkr1: CMakeFiles/mkr1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mkr1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mkr1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mkr1.dir/build: mkr1

.PHONY : CMakeFiles/mkr1.dir/build

CMakeFiles/mkr1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mkr1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mkr1.dir/clean

CMakeFiles/mkr1.dir/depend:
	cd /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dnl-krsvch/Documents/Projects/FIT/algorithms /Users/dnl-krsvch/Documents/Projects/FIT/algorithms /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug/CMakeFiles/mkr1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mkr1.dir/depend

