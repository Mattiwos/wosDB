# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests

# Include any dependencies generated for this target.
include CMakeFiles/wosDB-tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/wosDB-tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/wosDB-tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wosDB-tests.dir/flags.make

CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.o: CMakeFiles/wosDB-tests.dir/flags.make
CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.o: /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/client/clientDB.cpp
CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.o: CMakeFiles/wosDB-tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.o -MF CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.o.d -o CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.o -c /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/client/clientDB.cpp

CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/client/clientDB.cpp > CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.i

CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/client/clientDB.cpp -o CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.s

CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.o: CMakeFiles/wosDB-tests.dir/flags.make
CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.o: /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/db/db_interface.cpp
CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.o: CMakeFiles/wosDB-tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.o -MF CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.o.d -o CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.o -c /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/db/db_interface.cpp

CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/db/db_interface.cpp > CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.i

CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/db/db_interface.cpp -o CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.s

CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.o: CMakeFiles/wosDB-tests.dir/flags.make
CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.o: /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/server/handleRequests.cpp
CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.o: CMakeFiles/wosDB-tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.o -MF CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.o.d -o CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.o -c /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/server/handleRequests.cpp

CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/server/handleRequests.cpp > CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.i

CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/server/handleRequests.cpp -o CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.s

CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.o: CMakeFiles/wosDB-tests.dir/flags.make
CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.o: /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/server/serverDB.cpp
CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.o: CMakeFiles/wosDB-tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.o -MF CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.o.d -o CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.o -c /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/server/serverDB.cpp

CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/server/serverDB.cpp > CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.i

CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/src/server/serverDB.cpp -o CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.s

CMakeFiles/wosDB-tests.dir/main.cpp.o: CMakeFiles/wosDB-tests.dir/flags.make
CMakeFiles/wosDB-tests.dir/main.cpp.o: main.cpp
CMakeFiles/wosDB-tests.dir/main.cpp.o: CMakeFiles/wosDB-tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/wosDB-tests.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wosDB-tests.dir/main.cpp.o -MF CMakeFiles/wosDB-tests.dir/main.cpp.o.d -o CMakeFiles/wosDB-tests.dir/main.cpp.o -c /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests/main.cpp

CMakeFiles/wosDB-tests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/wosDB-tests.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests/main.cpp > CMakeFiles/wosDB-tests.dir/main.cpp.i

CMakeFiles/wosDB-tests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/wosDB-tests.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests/main.cpp -o CMakeFiles/wosDB-tests.dir/main.cpp.s

# Object files for target wosDB-tests
wosDB__tests_OBJECTS = \
"CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.o" \
"CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.o" \
"CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.o" \
"CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.o" \
"CMakeFiles/wosDB-tests.dir/main.cpp.o"

# External object files for target wosDB-tests
wosDB__tests_EXTERNAL_OBJECTS =

/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/bin/wosDB-tests: CMakeFiles/wosDB-tests.dir/src/client/clientDB.cpp.o
/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/bin/wosDB-tests: CMakeFiles/wosDB-tests.dir/src/db/db_interface.cpp.o
/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/bin/wosDB-tests: CMakeFiles/wosDB-tests.dir/src/server/handleRequests.cpp.o
/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/bin/wosDB-tests: CMakeFiles/wosDB-tests.dir/src/server/serverDB.cpp.o
/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/bin/wosDB-tests: CMakeFiles/wosDB-tests.dir/main.cpp.o
/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/bin/wosDB-tests: CMakeFiles/wosDB-tests.dir/build.make
/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/bin/wosDB-tests: /opt/homebrew/lib/libgtest_main.a
/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/bin/wosDB-tests: /opt/homebrew/lib/libgtest.a
/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/bin/wosDB-tests: CMakeFiles/wosDB-tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/bin/wosDB-tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wosDB-tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wosDB-tests.dir/build: /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/bin/wosDB-tests
.PHONY : CMakeFiles/wosDB-tests.dir/build

CMakeFiles/wosDB-tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wosDB-tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wosDB-tests.dir/clean

CMakeFiles/wosDB-tests.dir/depend:
	cd /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests /Users/mattiwosbelachew/Repos/github.com/mattiwos/wosDB/wosDB-tests/CMakeFiles/wosDB-tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/wosDB-tests.dir/depend

