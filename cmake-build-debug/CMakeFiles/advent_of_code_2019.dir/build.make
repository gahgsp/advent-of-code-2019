# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Web Projects\C++\advent-of-code-2019"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Web Projects\C++\advent-of-code-2019\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/advent_of_code_2019.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/advent_of_code_2019.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/advent_of_code_2019.dir/flags.make

CMakeFiles/advent_of_code_2019.dir/day08/main.cpp.obj: CMakeFiles/advent_of_code_2019.dir/flags.make
CMakeFiles/advent_of_code_2019.dir/day08/main.cpp.obj: ../day08/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Web Projects\C++\advent-of-code-2019\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/advent_of_code_2019.dir/day08/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\advent_of_code_2019.dir\day08\main.cpp.obj -c "C:\Web Projects\C++\advent-of-code-2019\day08\main.cpp"

CMakeFiles/advent_of_code_2019.dir/day08/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advent_of_code_2019.dir/day08/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Web Projects\C++\advent-of-code-2019\day08\main.cpp" > CMakeFiles\advent_of_code_2019.dir\day08\main.cpp.i

CMakeFiles/advent_of_code_2019.dir/day08/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advent_of_code_2019.dir/day08/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Web Projects\C++\advent-of-code-2019\day08\main.cpp" -o CMakeFiles\advent_of_code_2019.dir\day08\main.cpp.s

# Object files for target advent_of_code_2019
advent_of_code_2019_OBJECTS = \
"CMakeFiles/advent_of_code_2019.dir/day08/main.cpp.obj"

# External object files for target advent_of_code_2019
advent_of_code_2019_EXTERNAL_OBJECTS =

advent_of_code_2019.exe: CMakeFiles/advent_of_code_2019.dir/day08/main.cpp.obj
advent_of_code_2019.exe: CMakeFiles/advent_of_code_2019.dir/build.make
advent_of_code_2019.exe: CMakeFiles/advent_of_code_2019.dir/linklibs.rsp
advent_of_code_2019.exe: CMakeFiles/advent_of_code_2019.dir/objects1.rsp
advent_of_code_2019.exe: CMakeFiles/advent_of_code_2019.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Web Projects\C++\advent-of-code-2019\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable advent_of_code_2019.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\advent_of_code_2019.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/advent_of_code_2019.dir/build: advent_of_code_2019.exe

.PHONY : CMakeFiles/advent_of_code_2019.dir/build

CMakeFiles/advent_of_code_2019.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\advent_of_code_2019.dir\cmake_clean.cmake
.PHONY : CMakeFiles/advent_of_code_2019.dir/clean

CMakeFiles/advent_of_code_2019.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Web Projects\C++\advent-of-code-2019" "C:\Web Projects\C++\advent-of-code-2019" "C:\Web Projects\C++\advent-of-code-2019\cmake-build-debug" "C:\Web Projects\C++\advent-of-code-2019\cmake-build-debug" "C:\Web Projects\C++\advent-of-code-2019\cmake-build-debug\CMakeFiles\advent_of_code_2019.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/advent_of_code_2019.dir/depend

