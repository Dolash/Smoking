# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/Jack/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Jack/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Jack/CLionProjects/Smoking

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Jack/CLionProjects/Smoking/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Smoking.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Smoking.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Smoking.dir/flags.make

CMakeFiles/Smoking.dir/main.cpp.o: CMakeFiles/Smoking.dir/flags.make
CMakeFiles/Smoking.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Jack/CLionProjects/Smoking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Smoking.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smoking.dir/main.cpp.o -c /cygdrive/c/Users/Jack/CLionProjects/Smoking/main.cpp

CMakeFiles/Smoking.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smoking.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Jack/CLionProjects/Smoking/main.cpp > CMakeFiles/Smoking.dir/main.cpp.i

CMakeFiles/Smoking.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smoking.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Jack/CLionProjects/Smoking/main.cpp -o CMakeFiles/Smoking.dir/main.cpp.s

# Object files for target Smoking
Smoking_OBJECTS = \
"CMakeFiles/Smoking.dir/main.cpp.o"

# External object files for target Smoking
Smoking_EXTERNAL_OBJECTS =

Smoking.exe: CMakeFiles/Smoking.dir/main.cpp.o
Smoking.exe: CMakeFiles/Smoking.dir/build.make
Smoking.exe: CMakeFiles/Smoking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Jack/CLionProjects/Smoking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Smoking.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Smoking.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Smoking.dir/build: Smoking.exe
.PHONY : CMakeFiles/Smoking.dir/build

CMakeFiles/Smoking.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Smoking.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Smoking.dir/clean

CMakeFiles/Smoking.dir/depend:
	cd /cygdrive/c/Users/Jack/CLionProjects/Smoking/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Jack/CLionProjects/Smoking /cygdrive/c/Users/Jack/CLionProjects/Smoking /cygdrive/c/Users/Jack/CLionProjects/Smoking/cmake-build-debug /cygdrive/c/Users/Jack/CLionProjects/Smoking/cmake-build-debug /cygdrive/c/Users/Jack/CLionProjects/Smoking/cmake-build-debug/CMakeFiles/Smoking.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Smoking.dir/depend
