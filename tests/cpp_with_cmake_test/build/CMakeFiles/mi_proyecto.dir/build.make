# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jbutragu/compu_II/tests/cpp_with_cmake_test/build

# Include any dependencies generated for this target.
include CMakeFiles/mi_proyecto.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mi_proyecto.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mi_proyecto.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mi_proyecto.dir/flags.make

CMakeFiles/mi_proyecto.dir/main.cpp.o: CMakeFiles/mi_proyecto.dir/flags.make
CMakeFiles/mi_proyecto.dir/main.cpp.o: /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2/main.cpp
CMakeFiles/mi_proyecto.dir/main.cpp.o: CMakeFiles/mi_proyecto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jbutragu/compu_II/tests/cpp_with_cmake_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mi_proyecto.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mi_proyecto.dir/main.cpp.o -MF CMakeFiles/mi_proyecto.dir/main.cpp.o.d -o CMakeFiles/mi_proyecto.dir/main.cpp.o -c /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2/main.cpp

CMakeFiles/mi_proyecto.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mi_proyecto.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2/main.cpp > CMakeFiles/mi_proyecto.dir/main.cpp.i

CMakeFiles/mi_proyecto.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mi_proyecto.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2/main.cpp -o CMakeFiles/mi_proyecto.dir/main.cpp.s

CMakeFiles/mi_proyecto.dir/func_1.cpp.o: CMakeFiles/mi_proyecto.dir/flags.make
CMakeFiles/mi_proyecto.dir/func_1.cpp.o: /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2/func_1.cpp
CMakeFiles/mi_proyecto.dir/func_1.cpp.o: CMakeFiles/mi_proyecto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jbutragu/compu_II/tests/cpp_with_cmake_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mi_proyecto.dir/func_1.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mi_proyecto.dir/func_1.cpp.o -MF CMakeFiles/mi_proyecto.dir/func_1.cpp.o.d -o CMakeFiles/mi_proyecto.dir/func_1.cpp.o -c /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2/func_1.cpp

CMakeFiles/mi_proyecto.dir/func_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mi_proyecto.dir/func_1.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2/func_1.cpp > CMakeFiles/mi_proyecto.dir/func_1.cpp.i

CMakeFiles/mi_proyecto.dir/func_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mi_proyecto.dir/func_1.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2/func_1.cpp -o CMakeFiles/mi_proyecto.dir/func_1.cpp.s

CMakeFiles/mi_proyecto.dir/func_2.cpp.o: CMakeFiles/mi_proyecto.dir/flags.make
CMakeFiles/mi_proyecto.dir/func_2.cpp.o: /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2/func_2.cpp
CMakeFiles/mi_proyecto.dir/func_2.cpp.o: CMakeFiles/mi_proyecto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jbutragu/compu_II/tests/cpp_with_cmake_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mi_proyecto.dir/func_2.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mi_proyecto.dir/func_2.cpp.o -MF CMakeFiles/mi_proyecto.dir/func_2.cpp.o.d -o CMakeFiles/mi_proyecto.dir/func_2.cpp.o -c /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2/func_2.cpp

CMakeFiles/mi_proyecto.dir/func_2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mi_proyecto.dir/func_2.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2/func_2.cpp > CMakeFiles/mi_proyecto.dir/func_2.cpp.i

CMakeFiles/mi_proyecto.dir/func_2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mi_proyecto.dir/func_2.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2/func_2.cpp -o CMakeFiles/mi_proyecto.dir/func_2.cpp.s

# Object files for target mi_proyecto
mi_proyecto_OBJECTS = \
"CMakeFiles/mi_proyecto.dir/main.cpp.o" \
"CMakeFiles/mi_proyecto.dir/func_1.cpp.o" \
"CMakeFiles/mi_proyecto.dir/func_2.cpp.o"

# External object files for target mi_proyecto
mi_proyecto_EXTERNAL_OBJECTS =

mi_proyecto: CMakeFiles/mi_proyecto.dir/main.cpp.o
mi_proyecto: CMakeFiles/mi_proyecto.dir/func_1.cpp.o
mi_proyecto: CMakeFiles/mi_proyecto.dir/func_2.cpp.o
mi_proyecto: CMakeFiles/mi_proyecto.dir/build.make
mi_proyecto: CMakeFiles/mi_proyecto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jbutragu/compu_II/tests/cpp_with_cmake_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable mi_proyecto"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mi_proyecto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mi_proyecto.dir/build: mi_proyecto
.PHONY : CMakeFiles/mi_proyecto.dir/build

CMakeFiles/mi_proyecto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mi_proyecto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mi_proyecto.dir/clean

CMakeFiles/mi_proyecto.dir/depend:
	cd /home/jbutragu/compu_II/tests/cpp_with_cmake_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2 /home/jbutragu/compu_II/tests/cpp_with_cmake_test/test2 /home/jbutragu/compu_II/tests/cpp_with_cmake_test/build /home/jbutragu/compu_II/tests/cpp_with_cmake_test/build /home/jbutragu/compu_II/tests/cpp_with_cmake_test/build/CMakeFiles/mi_proyecto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mi_proyecto.dir/depend

