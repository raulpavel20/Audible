# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /home/raulpavel/Documents/clion-2020.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/raulpavel/Documents/clion-2020.1.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/raulpavel/Downloads/Audible-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/raulpavel/Downloads/Audible-master/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Audible.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Audible.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Audible.dir/flags.make

CMakeFiles/Audible.dir/Audible_autogen/mocs_compilation.cpp.o: CMakeFiles/Audible.dir/flags.make
CMakeFiles/Audible.dir/Audible_autogen/mocs_compilation.cpp.o: Audible_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raulpavel/Downloads/Audible-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Audible.dir/Audible_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Audible.dir/Audible_autogen/mocs_compilation.cpp.o -c /home/raulpavel/Downloads/Audible-master/cmake-build-debug/Audible_autogen/mocs_compilation.cpp

CMakeFiles/Audible.dir/Audible_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Audible.dir/Audible_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raulpavel/Downloads/Audible-master/cmake-build-debug/Audible_autogen/mocs_compilation.cpp > CMakeFiles/Audible.dir/Audible_autogen/mocs_compilation.cpp.i

CMakeFiles/Audible.dir/Audible_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Audible.dir/Audible_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raulpavel/Downloads/Audible-master/cmake-build-debug/Audible_autogen/mocs_compilation.cpp -o CMakeFiles/Audible.dir/Audible_autogen/mocs_compilation.cpp.s

CMakeFiles/Audible.dir/main.cpp.o: CMakeFiles/Audible.dir/flags.make
CMakeFiles/Audible.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raulpavel/Downloads/Audible-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Audible.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Audible.dir/main.cpp.o -c /home/raulpavel/Downloads/Audible-master/main.cpp

CMakeFiles/Audible.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Audible.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raulpavel/Downloads/Audible-master/main.cpp > CMakeFiles/Audible.dir/main.cpp.i

CMakeFiles/Audible.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Audible.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raulpavel/Downloads/Audible-master/main.cpp -o CMakeFiles/Audible.dir/main.cpp.s

CMakeFiles/Audible.dir/UI.cpp.o: CMakeFiles/Audible.dir/flags.make
CMakeFiles/Audible.dir/UI.cpp.o: ../UI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raulpavel/Downloads/Audible-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Audible.dir/UI.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Audible.dir/UI.cpp.o -c /home/raulpavel/Downloads/Audible-master/UI.cpp

CMakeFiles/Audible.dir/UI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Audible.dir/UI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raulpavel/Downloads/Audible-master/UI.cpp > CMakeFiles/Audible.dir/UI.cpp.i

CMakeFiles/Audible.dir/UI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Audible.dir/UI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raulpavel/Downloads/Audible-master/UI.cpp -o CMakeFiles/Audible.dir/UI.cpp.s

CMakeFiles/Audible.dir/Database.cpp.o: CMakeFiles/Audible.dir/flags.make
CMakeFiles/Audible.dir/Database.cpp.o: ../Database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raulpavel/Downloads/Audible-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Audible.dir/Database.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Audible.dir/Database.cpp.o -c /home/raulpavel/Downloads/Audible-master/Database.cpp

CMakeFiles/Audible.dir/Database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Audible.dir/Database.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raulpavel/Downloads/Audible-master/Database.cpp > CMakeFiles/Audible.dir/Database.cpp.i

CMakeFiles/Audible.dir/Database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Audible.dir/Database.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raulpavel/Downloads/Audible-master/Database.cpp -o CMakeFiles/Audible.dir/Database.cpp.s

CMakeFiles/Audible.dir/Book.cpp.o: CMakeFiles/Audible.dir/flags.make
CMakeFiles/Audible.dir/Book.cpp.o: ../Book.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raulpavel/Downloads/Audible-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Audible.dir/Book.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Audible.dir/Book.cpp.o -c /home/raulpavel/Downloads/Audible-master/Book.cpp

CMakeFiles/Audible.dir/Book.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Audible.dir/Book.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raulpavel/Downloads/Audible-master/Book.cpp > CMakeFiles/Audible.dir/Book.cpp.i

CMakeFiles/Audible.dir/Book.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Audible.dir/Book.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raulpavel/Downloads/Audible-master/Book.cpp -o CMakeFiles/Audible.dir/Book.cpp.s

CMakeFiles/Audible.dir/Controller.cpp.o: CMakeFiles/Audible.dir/flags.make
CMakeFiles/Audible.dir/Controller.cpp.o: ../Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raulpavel/Downloads/Audible-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Audible.dir/Controller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Audible.dir/Controller.cpp.o -c /home/raulpavel/Downloads/Audible-master/Controller.cpp

CMakeFiles/Audible.dir/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Audible.dir/Controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raulpavel/Downloads/Audible-master/Controller.cpp > CMakeFiles/Audible.dir/Controller.cpp.i

CMakeFiles/Audible.dir/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Audible.dir/Controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raulpavel/Downloads/Audible-master/Controller.cpp -o CMakeFiles/Audible.dir/Controller.cpp.s

CMakeFiles/Audible.dir/PersistenceEngine.cpp.o: CMakeFiles/Audible.dir/flags.make
CMakeFiles/Audible.dir/PersistenceEngine.cpp.o: ../PersistenceEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raulpavel/Downloads/Audible-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Audible.dir/PersistenceEngine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Audible.dir/PersistenceEngine.cpp.o -c /home/raulpavel/Downloads/Audible-master/PersistenceEngine.cpp

CMakeFiles/Audible.dir/PersistenceEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Audible.dir/PersistenceEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raulpavel/Downloads/Audible-master/PersistenceEngine.cpp > CMakeFiles/Audible.dir/PersistenceEngine.cpp.i

CMakeFiles/Audible.dir/PersistenceEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Audible.dir/PersistenceEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raulpavel/Downloads/Audible-master/PersistenceEngine.cpp -o CMakeFiles/Audible.dir/PersistenceEngine.cpp.s

CMakeFiles/Audible.dir/mainwindow.cpp.o: CMakeFiles/Audible.dir/flags.make
CMakeFiles/Audible.dir/mainwindow.cpp.o: ../mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raulpavel/Downloads/Audible-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Audible.dir/mainwindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Audible.dir/mainwindow.cpp.o -c /home/raulpavel/Downloads/Audible-master/mainwindow.cpp

CMakeFiles/Audible.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Audible.dir/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raulpavel/Downloads/Audible-master/mainwindow.cpp > CMakeFiles/Audible.dir/mainwindow.cpp.i

CMakeFiles/Audible.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Audible.dir/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raulpavel/Downloads/Audible-master/mainwindow.cpp -o CMakeFiles/Audible.dir/mainwindow.cpp.s

CMakeFiles/Audible.dir/clientwindow.cpp.o: CMakeFiles/Audible.dir/flags.make
CMakeFiles/Audible.dir/clientwindow.cpp.o: ../clientwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raulpavel/Downloads/Audible-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Audible.dir/clientwindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Audible.dir/clientwindow.cpp.o -c /home/raulpavel/Downloads/Audible-master/clientwindow.cpp

CMakeFiles/Audible.dir/clientwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Audible.dir/clientwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raulpavel/Downloads/Audible-master/clientwindow.cpp > CMakeFiles/Audible.dir/clientwindow.cpp.i

CMakeFiles/Audible.dir/clientwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Audible.dir/clientwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raulpavel/Downloads/Audible-master/clientwindow.cpp -o CMakeFiles/Audible.dir/clientwindow.cpp.s

CMakeFiles/Audible.dir/adminwindow.cpp.o: CMakeFiles/Audible.dir/flags.make
CMakeFiles/Audible.dir/adminwindow.cpp.o: ../adminwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/raulpavel/Downloads/Audible-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Audible.dir/adminwindow.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Audible.dir/adminwindow.cpp.o -c /home/raulpavel/Downloads/Audible-master/adminwindow.cpp

CMakeFiles/Audible.dir/adminwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Audible.dir/adminwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/raulpavel/Downloads/Audible-master/adminwindow.cpp > CMakeFiles/Audible.dir/adminwindow.cpp.i

CMakeFiles/Audible.dir/adminwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Audible.dir/adminwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/raulpavel/Downloads/Audible-master/adminwindow.cpp -o CMakeFiles/Audible.dir/adminwindow.cpp.s

# Object files for target Audible
Audible_OBJECTS = \
"CMakeFiles/Audible.dir/Audible_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/Audible.dir/main.cpp.o" \
"CMakeFiles/Audible.dir/UI.cpp.o" \
"CMakeFiles/Audible.dir/Database.cpp.o" \
"CMakeFiles/Audible.dir/Book.cpp.o" \
"CMakeFiles/Audible.dir/Controller.cpp.o" \
"CMakeFiles/Audible.dir/PersistenceEngine.cpp.o" \
"CMakeFiles/Audible.dir/mainwindow.cpp.o" \
"CMakeFiles/Audible.dir/clientwindow.cpp.o" \
"CMakeFiles/Audible.dir/adminwindow.cpp.o"

# External object files for target Audible
Audible_EXTERNAL_OBJECTS =

Audible: CMakeFiles/Audible.dir/Audible_autogen/mocs_compilation.cpp.o
Audible: CMakeFiles/Audible.dir/main.cpp.o
Audible: CMakeFiles/Audible.dir/UI.cpp.o
Audible: CMakeFiles/Audible.dir/Database.cpp.o
Audible: CMakeFiles/Audible.dir/Book.cpp.o
Audible: CMakeFiles/Audible.dir/Controller.cpp.o
Audible: CMakeFiles/Audible.dir/PersistenceEngine.cpp.o
Audible: CMakeFiles/Audible.dir/mainwindow.cpp.o
Audible: CMakeFiles/Audible.dir/clientwindow.cpp.o
Audible: CMakeFiles/Audible.dir/adminwindow.cpp.o
Audible: CMakeFiles/Audible.dir/build.make
Audible: /home/raulpavel/Qt/5.14.2/gcc_64/lib/libQt5Widgets.so.5.14.2
Audible: /home/raulpavel/Qt/5.14.2/gcc_64/lib/libQt5Gui.so.5.14.2
Audible: /home/raulpavel/Qt/5.14.2/gcc_64/lib/libQt5Core.so.5.14.2
Audible: CMakeFiles/Audible.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/raulpavel/Downloads/Audible-master/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Audible"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Audible.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Audible.dir/build: Audible

.PHONY : CMakeFiles/Audible.dir/build

CMakeFiles/Audible.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Audible.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Audible.dir/clean

CMakeFiles/Audible.dir/depend:
	cd /home/raulpavel/Downloads/Audible-master/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/raulpavel/Downloads/Audible-master /home/raulpavel/Downloads/Audible-master /home/raulpavel/Downloads/Audible-master/cmake-build-debug /home/raulpavel/Downloads/Audible-master/cmake-build-debug /home/raulpavel/Downloads/Audible-master/cmake-build-debug/CMakeFiles/Audible.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Audible.dir/depend

