# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leviathan/Documents/Projects_git/TrainingDataProcessor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leviathan/Documents/Projects_git/TrainingDataProcessor/build

# Include any dependencies generated for this target.
include CMakeFiles/trainingdataprocessor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/trainingdataprocessor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trainingdataprocessor.dir/flags.make

CMakeFiles/trainingdataprocessor.dir/main.cpp.o: CMakeFiles/trainingdataprocessor.dir/flags.make
CMakeFiles/trainingdataprocessor.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leviathan/Documents/Projects_git/TrainingDataProcessor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/trainingdataprocessor.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/trainingdataprocessor.dir/main.cpp.o -c /home/leviathan/Documents/Projects_git/TrainingDataProcessor/main.cpp

CMakeFiles/trainingdataprocessor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/trainingdataprocessor.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leviathan/Documents/Projects_git/TrainingDataProcessor/main.cpp > CMakeFiles/trainingdataprocessor.dir/main.cpp.i

CMakeFiles/trainingdataprocessor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/trainingdataprocessor.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leviathan/Documents/Projects_git/TrainingDataProcessor/main.cpp -o CMakeFiles/trainingdataprocessor.dir/main.cpp.s

CMakeFiles/trainingdataprocessor.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/trainingdataprocessor.dir/main.cpp.o.requires

CMakeFiles/trainingdataprocessor.dir/main.cpp.o.provides: CMakeFiles/trainingdataprocessor.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/trainingdataprocessor.dir/build.make CMakeFiles/trainingdataprocessor.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/trainingdataprocessor.dir/main.cpp.o.provides

CMakeFiles/trainingdataprocessor.dir/main.cpp.o.provides.build: CMakeFiles/trainingdataprocessor.dir/main.cpp.o


CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o: CMakeFiles/trainingdataprocessor.dir/flags.make
CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o: ../CSVdata.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leviathan/Documents/Projects_git/TrainingDataProcessor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o -c /home/leviathan/Documents/Projects_git/TrainingDataProcessor/CSVdata.cpp

CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leviathan/Documents/Projects_git/TrainingDataProcessor/CSVdata.cpp > CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.i

CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leviathan/Documents/Projects_git/TrainingDataProcessor/CSVdata.cpp -o CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.s

CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o.requires:

.PHONY : CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o.requires

CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o.provides: CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o.requires
	$(MAKE) -f CMakeFiles/trainingdataprocessor.dir/build.make CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o.provides.build
.PHONY : CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o.provides

CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o.provides.build: CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o


# Object files for target trainingdataprocessor
trainingdataprocessor_OBJECTS = \
"CMakeFiles/trainingdataprocessor.dir/main.cpp.o" \
"CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o"

# External object files for target trainingdataprocessor
trainingdataprocessor_EXTERNAL_OBJECTS =

trainingdataprocessor: CMakeFiles/trainingdataprocessor.dir/main.cpp.o
trainingdataprocessor: CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o
trainingdataprocessor: CMakeFiles/trainingdataprocessor.dir/build.make
trainingdataprocessor: CMakeFiles/trainingdataprocessor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leviathan/Documents/Projects_git/TrainingDataProcessor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable trainingdataprocessor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trainingdataprocessor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/trainingdataprocessor.dir/build: trainingdataprocessor

.PHONY : CMakeFiles/trainingdataprocessor.dir/build

CMakeFiles/trainingdataprocessor.dir/requires: CMakeFiles/trainingdataprocessor.dir/main.cpp.o.requires
CMakeFiles/trainingdataprocessor.dir/requires: CMakeFiles/trainingdataprocessor.dir/CSVdata.cpp.o.requires

.PHONY : CMakeFiles/trainingdataprocessor.dir/requires

CMakeFiles/trainingdataprocessor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/trainingdataprocessor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/trainingdataprocessor.dir/clean

CMakeFiles/trainingdataprocessor.dir/depend:
	cd /home/leviathan/Documents/Projects_git/TrainingDataProcessor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leviathan/Documents/Projects_git/TrainingDataProcessor /home/leviathan/Documents/Projects_git/TrainingDataProcessor /home/leviathan/Documents/Projects_git/TrainingDataProcessor/build /home/leviathan/Documents/Projects_git/TrainingDataProcessor/build /home/leviathan/Documents/Projects_git/TrainingDataProcessor/build/CMakeFiles/trainingdataprocessor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/trainingdataprocessor.dir/depend
