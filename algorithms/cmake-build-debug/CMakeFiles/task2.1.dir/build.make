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
include CMakeFiles/task2.1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task2.1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task2.1.dir/flags.make

CMakeFiles/task2.1.dir/lab2/task1.cpp.o: CMakeFiles/task2.1.dir/flags.make
CMakeFiles/task2.1.dir/lab2/task1.cpp.o: ../lab2/task1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task2.1.dir/lab2/task1.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task2.1.dir/lab2/task1.cpp.o -c /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/lab2/task1.cpp

CMakeFiles/task2.1.dir/lab2/task1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task2.1.dir/lab2/task1.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/lab2/task1.cpp > CMakeFiles/task2.1.dir/lab2/task1.cpp.i

CMakeFiles/task2.1.dir/lab2/task1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task2.1.dir/lab2/task1.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/lab2/task1.cpp -o CMakeFiles/task2.1.dir/lab2/task1.cpp.s

# Object files for target task2.1
task2_1_OBJECTS = \
"CMakeFiles/task2.1.dir/lab2/task1.cpp.o"

# External object files for target task2.1
task2_1_EXTERNAL_OBJECTS =

task2.1: CMakeFiles/task2.1.dir/lab2/task1.cpp.o
task2.1: CMakeFiles/task2.1.dir/build.make
task2.1: CMakeFiles/task2.1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task2.1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task2.1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task2.1.dir/build: task2.1

.PHONY : CMakeFiles/task2.1.dir/build

CMakeFiles/task2.1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task2.1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task2.1.dir/clean

CMakeFiles/task2.1.dir/depend:
	cd /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dnl-krsvch/Documents/Projects/FIT/algorithms /Users/dnl-krsvch/Documents/Projects/FIT/algorithms /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug /Users/dnl-krsvch/Documents/Projects/FIT/algorithms/cmake-build-debug/CMakeFiles/task2.1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task2.1.dir/depend

