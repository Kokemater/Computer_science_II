# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/build"

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/hi.cpp.obj: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/hi.cpp.obj: C:/Users/maris/OneDrive/Escritorio/Programacion\ verano/computationII/tests/cpp_with_cmake_test/hi.cpp
CMakeFiles/test.dir/hi.cpp.obj: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/hi.cpp.obj"
	C:/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/hi.cpp.obj -MF CMakeFiles/test.dir/hi.cpp.obj.d -o CMakeFiles/test.dir/hi.cpp.obj -c "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/hi.cpp"

CMakeFiles/test.dir/hi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test.dir/hi.cpp.i"
	C:/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/hi.cpp" > CMakeFiles/test.dir/hi.cpp.i

CMakeFiles/test.dir/hi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test.dir/hi.cpp.s"
	C:/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/hi.cpp" -o CMakeFiles/test.dir/hi.cpp.s

CMakeFiles/test.dir/my_func.cpp.obj: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/my_func.cpp.obj: C:/Users/maris/OneDrive/Escritorio/Programacion\ verano/computationII/tests/cpp_with_cmake_test/my_func.cpp
CMakeFiles/test.dir/my_func.cpp.obj: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/my_func.cpp.obj"
	C:/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/my_func.cpp.obj -MF CMakeFiles/test.dir/my_func.cpp.obj.d -o CMakeFiles/test.dir/my_func.cpp.obj -c "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/my_func.cpp"

CMakeFiles/test.dir/my_func.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test.dir/my_func.cpp.i"
	C:/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/my_func.cpp" > CMakeFiles/test.dir/my_func.cpp.i

CMakeFiles/test.dir/my_func.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test.dir/my_func.cpp.s"
	C:/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/my_func.cpp" -o CMakeFiles/test.dir/my_func.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/hi.cpp.obj" \
"CMakeFiles/test.dir/my_func.cpp.obj"

# External object files for target test
test_EXTERNAL_OBJECTS =

test.exe: CMakeFiles/test.dir/hi.cpp.obj
test.exe: CMakeFiles/test.dir/my_func.cpp.obj
test.exe: CMakeFiles/test.dir/build.make
test.exe: CMakeFiles/test.dir/linkLibs.rsp
test.exe: CMakeFiles/test.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/test.dir/objects.a
	C:/msys64/mingw64/bin/ar.exe qc CMakeFiles/test.dir/objects.a @CMakeFiles/test.dir/objects1.rsp
	C:/msys64/mingw64/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/test.dir/objects.a -Wl,--no-whole-archive -o test.exe -Wl,--out-implib,libtest.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/test.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test.exe
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test" "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test" "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/build" "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/build" "C:/Users/maris/OneDrive/Escritorio/Programacion verano/computationII/tests/cpp_with_cmake_test/build/CMakeFiles/test.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/test.dir/depend
