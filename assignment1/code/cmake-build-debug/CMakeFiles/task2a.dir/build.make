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
CMAKE_COMMAND = /home/morningstar/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/morningstar/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/morningstar/Documents/s8mequad_2581654/assignment1/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/morningstar/Documents/s8mequad_2581654/assignment1/code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task2a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task2a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task2a.dir/flags.make

CMakeFiles/task2a.dir/task2a.cpp.o: CMakeFiles/task2a.dir/flags.make
CMakeFiles/task2a.dir/task2a.cpp.o: ../task2a.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morningstar/Documents/s8mequad_2581654/assignment1/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task2a.dir/task2a.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task2a.dir/task2a.cpp.o -c /home/morningstar/Documents/s8mequad_2581654/assignment1/code/task2a.cpp

CMakeFiles/task2a.dir/task2a.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task2a.dir/task2a.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morningstar/Documents/s8mequad_2581654/assignment1/code/task2a.cpp > CMakeFiles/task2a.dir/task2a.cpp.i

CMakeFiles/task2a.dir/task2a.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task2a.dir/task2a.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morningstar/Documents/s8mequad_2581654/assignment1/code/task2a.cpp -o CMakeFiles/task2a.dir/task2a.cpp.s

# Object files for target task2a
task2a_OBJECTS = \
"CMakeFiles/task2a.dir/task2a.cpp.o"

# External object files for target task2a
task2a_EXTERNAL_OBJECTS =

task2a: CMakeFiles/task2a.dir/task2a.cpp.o
task2a: CMakeFiles/task2a.dir/build.make
task2a: CMakeFiles/task2a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/morningstar/Documents/s8mequad_2581654/assignment1/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task2a"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task2a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task2a.dir/build: task2a

.PHONY : CMakeFiles/task2a.dir/build

CMakeFiles/task2a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task2a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task2a.dir/clean

CMakeFiles/task2a.dir/depend:
	cd /home/morningstar/Documents/s8mequad_2581654/assignment1/code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/morningstar/Documents/s8mequad_2581654/assignment1/code /home/morningstar/Documents/s8mequad_2581654/assignment1/code /home/morningstar/Documents/s8mequad_2581654/assignment1/code/cmake-build-debug /home/morningstar/Documents/s8mequad_2581654/assignment1/code/cmake-build-debug /home/morningstar/Documents/s8mequad_2581654/assignment1/code/cmake-build-debug/CMakeFiles/task2a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task2a.dir/depend

