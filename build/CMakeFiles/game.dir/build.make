# CMAKE generated file: DO NOT EDIT!
# Generated by "Borland Makefiles" Generator, CMake Version 3.15

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force: NUL

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\s5006074\gep_sdk\opt\cmake-3.15.1\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\s5006074\gep_sdk\opt\cmake-3.15.1\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\s5006074\Gamengine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\s5006074\Gamengine\build

# Include any dependencies generated for this target.
!include CMakeFiles\game.dir\depend.make

# Include the progress variables for this target.
!include CMakeFiles\game.dir\progress.make

# Include the compile flags for this target's objects.
!include CMakeFiles\game.dir\flags.make

CMakeFiles\game.dir\src\game\main.cpp.obj: CMakeFiles\game.dir\flags.make
CMakeFiles\game.dir\src\game\main.cpp.obj: src\game\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\s5006074\Gamengine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/src/game/main.cpp.obj"
	C:\Users\s5006074\gep_sdk\opt\bcc-10.1\bin\bcc32c.exe -tR -DWIN32 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -oCMakeFiles\game.dir\src\game\main.cpp.obj -P -c C:\Users\s5006074\Gamengine\build\src\game\main.cpp

CMakeFiles\game.dir\src\game\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/game/main.cpp.i"
	cpp32 -DWIN32 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -oCMakeFiles\game.dir\src\game\main.cpp.i -P -c C:\Users\s5006074\Gamengine\build\src\game\main.cpp

CMakeFiles\game.dir\src\game\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/game/main.cpp.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_ASSEMBLY_SOURCE

# Object files for target game
game_OBJECTS = \
"CMakeFiles\game.dir\src\game\main.cpp.obj"

# External object files for target game
game_EXTERNAL_OBJECTS =

game.exe: CMakeFiles\game.dir\src\game\main.cpp.obj
game.exe: CMakeFiles\game.dir\build.make
game.exe: Gameengine.lib
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\s5006074\Gamengine\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable game.exe"
	C:\Users\s5006074\gep_sdk\opt\bcc-10.1\bin\bcc32c.exe -tR -egame.exe -tM -lS:1048576 -lSc:4098 -lH:1048576 -lHc:8192  -LC:/Users/s5006074/gep_sdk/lib/bcc -v -tC -IC:/Users/s5006074/gep_sdk/include/bcc -IC:/Users/s5006074/gep_sdk/include/common  -tM -Od -v @&&|
 Gameengine.lib SDL2.lib opengl32.lib glew32.lib import32.lib  $(game_OBJECTS) $(game_EXTERNAL_OBJECTS)
|

# Rule to build all files generated by this target.
CMakeFiles\game.dir\build: game.exe

.PHONY : CMakeFiles\game.dir\build

CMakeFiles\game.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\game.dir\cmake_clean.cmake
.PHONY : CMakeFiles\game.dir\clean

CMakeFiles\game.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "Borland Makefiles" C:\Users\s5006074\Gamengine C:\Users\s5006074\Gamengine C:\Users\s5006074\Gamengine\build C:\Users\s5006074\Gamengine\build C:\Users\s5006074\Gamengine\build\CMakeFiles\game.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\game.dir\depend

