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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\magicgh\Desktop\homework-cpp\Week 8"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\magicgh\Desktop\homework-cpp\Week 8\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Week_8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Week_8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Week_8.dir/flags.make

CMakeFiles/Week_8.dir/main.cpp.obj: CMakeFiles/Week_8.dir/flags.make
CMakeFiles/Week_8.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\magicgh\Desktop\homework-cpp\Week 8\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Week_8.dir/main.cpp.obj"
	D:\Software\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Week_8.dir\main.cpp.obj -c "C:\Users\magicgh\Desktop\homework-cpp\Week 8\main.cpp"

CMakeFiles/Week_8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Week_8.dir/main.cpp.i"
	D:\Software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\magicgh\Desktop\homework-cpp\Week 8\main.cpp" > CMakeFiles\Week_8.dir\main.cpp.i

CMakeFiles/Week_8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Week_8.dir/main.cpp.s"
	D:\Software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\magicgh\Desktop\homework-cpp\Week 8\main.cpp" -o CMakeFiles\Week_8.dir\main.cpp.s

CMakeFiles/Week_8.dir/school.cpp.obj: CMakeFiles/Week_8.dir/flags.make
CMakeFiles/Week_8.dir/school.cpp.obj: ../school.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\magicgh\Desktop\homework-cpp\Week 8\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Week_8.dir/school.cpp.obj"
	D:\Software\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Week_8.dir\school.cpp.obj -c "C:\Users\magicgh\Desktop\homework-cpp\Week 8\school.cpp"

CMakeFiles/Week_8.dir/school.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Week_8.dir/school.cpp.i"
	D:\Software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\magicgh\Desktop\homework-cpp\Week 8\school.cpp" > CMakeFiles\Week_8.dir\school.cpp.i

CMakeFiles/Week_8.dir/school.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Week_8.dir/school.cpp.s"
	D:\Software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\magicgh\Desktop\homework-cpp\Week 8\school.cpp" -o CMakeFiles\Week_8.dir\school.cpp.s

# Object files for target Week_8
Week_8_OBJECTS = \
"CMakeFiles/Week_8.dir/main.cpp.obj" \
"CMakeFiles/Week_8.dir/school.cpp.obj"

# External object files for target Week_8
Week_8_EXTERNAL_OBJECTS =

Week_8.exe: CMakeFiles/Week_8.dir/main.cpp.obj
Week_8.exe: CMakeFiles/Week_8.dir/school.cpp.obj
Week_8.exe: CMakeFiles/Week_8.dir/build.make
Week_8.exe: CMakeFiles/Week_8.dir/linklibs.rsp
Week_8.exe: CMakeFiles/Week_8.dir/objects1.rsp
Week_8.exe: CMakeFiles/Week_8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\magicgh\Desktop\homework-cpp\Week 8\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Week_8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Week_8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Week_8.dir/build: Week_8.exe

.PHONY : CMakeFiles/Week_8.dir/build

CMakeFiles/Week_8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Week_8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Week_8.dir/clean

CMakeFiles/Week_8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\magicgh\Desktop\homework-cpp\Week 8" "C:\Users\magicgh\Desktop\homework-cpp\Week 8" "C:\Users\magicgh\Desktop\homework-cpp\Week 8\cmake-build-debug" "C:\Users\magicgh\Desktop\homework-cpp\Week 8\cmake-build-debug" "C:\Users\magicgh\Desktop\homework-cpp\Week 8\cmake-build-debug\CMakeFiles\Week_8.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Week_8.dir/depend

