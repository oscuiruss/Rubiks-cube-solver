# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\clion\2sem\cube

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\clion\2sem\cube\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\cube.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\cube.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\cube.dir\flags.make

CMakeFiles\cube.dir\main.cpp.obj: CMakeFiles\cube.dir\flags.make
CMakeFiles\cube.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\clion\2sem\cube\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cube.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\cube.dir\main.cpp.obj /FdCMakeFiles\cube.dir\ /FS -c C:\clion\2sem\cube\main.cpp
<<

CMakeFiles\cube.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cube.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\cube.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\clion\2sem\cube\main.cpp
<<

CMakeFiles\cube.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cube.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\cube.dir\main.cpp.s /c C:\clion\2sem\cube\main.cpp
<<

CMakeFiles\cube.dir\cube.cpp.obj: CMakeFiles\cube.dir\flags.make
CMakeFiles\cube.dir\cube.cpp.obj: ..\cube.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\clion\2sem\cube\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cube.dir/cube.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\cube.dir\cube.cpp.obj /FdCMakeFiles\cube.dir\ /FS -c C:\clion\2sem\cube\cube.cpp
<<

CMakeFiles\cube.dir\cube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cube.dir/cube.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\cube.dir\cube.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\clion\2sem\cube\cube.cpp
<<

CMakeFiles\cube.dir\cube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cube.dir/cube.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\cube.dir\cube.cpp.s /c C:\clion\2sem\cube\cube.cpp
<<

# Object files for target cube
cube_OBJECTS = \
"CMakeFiles\cube.dir\main.cpp.obj" \
"CMakeFiles\cube.dir\cube.cpp.obj"

# External object files for target cube
cube_EXTERNAL_OBJECTS =

cube.exe: CMakeFiles\cube.dir\main.cpp.obj
cube.exe: CMakeFiles\cube.dir\cube.cpp.obj
cube.exe: CMakeFiles\cube.dir\build.make
cube.exe: CMakeFiles\cube.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\clion\2sem\cube\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cube.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\cube.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\cube.dir\objects1.rsp @<<
 /out:cube.exe /implib:cube.lib /pdb:C:\clion\2sem\cube\cmake-build-debug\cube.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\cube.dir\build: cube.exe

.PHONY : CMakeFiles\cube.dir\build

CMakeFiles\cube.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cube.dir\cmake_clean.cmake
.PHONY : CMakeFiles\cube.dir\clean

CMakeFiles\cube.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\clion\2sem\cube C:\clion\2sem\cube C:\clion\2sem\cube\cmake-build-debug C:\clion\2sem\cube\cmake-build-debug C:\clion\2sem\cube\cmake-build-debug\CMakeFiles\cube.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\cube.dir\depend

