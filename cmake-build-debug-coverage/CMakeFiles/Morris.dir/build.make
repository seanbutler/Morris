# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sean/Work/Projects/Morris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sean/Work/Projects/Morris/cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/Morris.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Morris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Morris.dir/flags.make

CMakeFiles/Morris.dir/main.cpp.o: CMakeFiles/Morris.dir/flags.make
CMakeFiles/Morris.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Morris.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Morris.dir/main.cpp.o -c /home/sean/Work/Projects/Morris/main.cpp

CMakeFiles/Morris.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Morris.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Work/Projects/Morris/main.cpp > CMakeFiles/Morris.dir/main.cpp.i

CMakeFiles/Morris.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Morris.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Work/Projects/Morris/main.cpp -o CMakeFiles/Morris.dir/main.cpp.s

CMakeFiles/Morris.dir/src/compiler/Tokenizer.cpp.o: CMakeFiles/Morris.dir/flags.make
CMakeFiles/Morris.dir/src/compiler/Tokenizer.cpp.o: ../src/compiler/Tokenizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Morris.dir/src/compiler/Tokenizer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Morris.dir/src/compiler/Tokenizer.cpp.o -c /home/sean/Work/Projects/Morris/src/compiler/Tokenizer.cpp

CMakeFiles/Morris.dir/src/compiler/Tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Morris.dir/src/compiler/Tokenizer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Work/Projects/Morris/src/compiler/Tokenizer.cpp > CMakeFiles/Morris.dir/src/compiler/Tokenizer.cpp.i

CMakeFiles/Morris.dir/src/compiler/Tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Morris.dir/src/compiler/Tokenizer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Work/Projects/Morris/src/compiler/Tokenizer.cpp -o CMakeFiles/Morris.dir/src/compiler/Tokenizer.cpp.s

CMakeFiles/Morris.dir/src/compiler/Tokens.cpp.o: CMakeFiles/Morris.dir/flags.make
CMakeFiles/Morris.dir/src/compiler/Tokens.cpp.o: ../src/compiler/Tokens.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Morris.dir/src/compiler/Tokens.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Morris.dir/src/compiler/Tokens.cpp.o -c /home/sean/Work/Projects/Morris/src/compiler/Tokens.cpp

CMakeFiles/Morris.dir/src/compiler/Tokens.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Morris.dir/src/compiler/Tokens.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Work/Projects/Morris/src/compiler/Tokens.cpp > CMakeFiles/Morris.dir/src/compiler/Tokens.cpp.i

CMakeFiles/Morris.dir/src/compiler/Tokens.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Morris.dir/src/compiler/Tokens.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Work/Projects/Morris/src/compiler/Tokens.cpp -o CMakeFiles/Morris.dir/src/compiler/Tokens.cpp.s

CMakeFiles/Morris.dir/src/compiler/Parser.cpp.o: CMakeFiles/Morris.dir/flags.make
CMakeFiles/Morris.dir/src/compiler/Parser.cpp.o: ../src/compiler/Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Morris.dir/src/compiler/Parser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Morris.dir/src/compiler/Parser.cpp.o -c /home/sean/Work/Projects/Morris/src/compiler/Parser.cpp

CMakeFiles/Morris.dir/src/compiler/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Morris.dir/src/compiler/Parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Work/Projects/Morris/src/compiler/Parser.cpp > CMakeFiles/Morris.dir/src/compiler/Parser.cpp.i

CMakeFiles/Morris.dir/src/compiler/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Morris.dir/src/compiler/Parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Work/Projects/Morris/src/compiler/Parser.cpp -o CMakeFiles/Morris.dir/src/compiler/Parser.cpp.s

CMakeFiles/Morris.dir/src/compiler/InstructionASTVisitor.cpp.o: CMakeFiles/Morris.dir/flags.make
CMakeFiles/Morris.dir/src/compiler/InstructionASTVisitor.cpp.o: ../src/compiler/InstructionASTVisitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Morris.dir/src/compiler/InstructionASTVisitor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Morris.dir/src/compiler/InstructionASTVisitor.cpp.o -c /home/sean/Work/Projects/Morris/src/compiler/InstructionASTVisitor.cpp

CMakeFiles/Morris.dir/src/compiler/InstructionASTVisitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Morris.dir/src/compiler/InstructionASTVisitor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Work/Projects/Morris/src/compiler/InstructionASTVisitor.cpp > CMakeFiles/Morris.dir/src/compiler/InstructionASTVisitor.cpp.i

CMakeFiles/Morris.dir/src/compiler/InstructionASTVisitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Morris.dir/src/compiler/InstructionASTVisitor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Work/Projects/Morris/src/compiler/InstructionASTVisitor.cpp -o CMakeFiles/Morris.dir/src/compiler/InstructionASTVisitor.cpp.s

CMakeFiles/Morris.dir/src/compiler/SymbolTable.cpp.o: CMakeFiles/Morris.dir/flags.make
CMakeFiles/Morris.dir/src/compiler/SymbolTable.cpp.o: ../src/compiler/SymbolTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Morris.dir/src/compiler/SymbolTable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Morris.dir/src/compiler/SymbolTable.cpp.o -c /home/sean/Work/Projects/Morris/src/compiler/SymbolTable.cpp

CMakeFiles/Morris.dir/src/compiler/SymbolTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Morris.dir/src/compiler/SymbolTable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Work/Projects/Morris/src/compiler/SymbolTable.cpp > CMakeFiles/Morris.dir/src/compiler/SymbolTable.cpp.i

CMakeFiles/Morris.dir/src/compiler/SymbolTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Morris.dir/src/compiler/SymbolTable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Work/Projects/Morris/src/compiler/SymbolTable.cpp -o CMakeFiles/Morris.dir/src/compiler/SymbolTable.cpp.s

CMakeFiles/Morris.dir/src/runtime/VirtualMachine.cpp.o: CMakeFiles/Morris.dir/flags.make
CMakeFiles/Morris.dir/src/runtime/VirtualMachine.cpp.o: ../src/runtime/VirtualMachine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Morris.dir/src/runtime/VirtualMachine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Morris.dir/src/runtime/VirtualMachine.cpp.o -c /home/sean/Work/Projects/Morris/src/runtime/VirtualMachine.cpp

CMakeFiles/Morris.dir/src/runtime/VirtualMachine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Morris.dir/src/runtime/VirtualMachine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Work/Projects/Morris/src/runtime/VirtualMachine.cpp > CMakeFiles/Morris.dir/src/runtime/VirtualMachine.cpp.i

CMakeFiles/Morris.dir/src/runtime/VirtualMachine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Morris.dir/src/runtime/VirtualMachine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Work/Projects/Morris/src/runtime/VirtualMachine.cpp -o CMakeFiles/Morris.dir/src/runtime/VirtualMachine.cpp.s

CMakeFiles/Morris.dir/src/compiler/Instructions.cpp.o: CMakeFiles/Morris.dir/flags.make
CMakeFiles/Morris.dir/src/compiler/Instructions.cpp.o: ../src/compiler/Instructions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Morris.dir/src/compiler/Instructions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Morris.dir/src/compiler/Instructions.cpp.o -c /home/sean/Work/Projects/Morris/src/compiler/Instructions.cpp

CMakeFiles/Morris.dir/src/compiler/Instructions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Morris.dir/src/compiler/Instructions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Work/Projects/Morris/src/compiler/Instructions.cpp > CMakeFiles/Morris.dir/src/compiler/Instructions.cpp.i

CMakeFiles/Morris.dir/src/compiler/Instructions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Morris.dir/src/compiler/Instructions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Work/Projects/Morris/src/compiler/Instructions.cpp -o CMakeFiles/Morris.dir/src/compiler/Instructions.cpp.s

CMakeFiles/Morris.dir/src/compiler/compiler.cpp.o: CMakeFiles/Morris.dir/flags.make
CMakeFiles/Morris.dir/src/compiler/compiler.cpp.o: ../src/compiler/compiler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Morris.dir/src/compiler/compiler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Morris.dir/src/compiler/compiler.cpp.o -c /home/sean/Work/Projects/Morris/src/compiler/compiler.cpp

CMakeFiles/Morris.dir/src/compiler/compiler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Morris.dir/src/compiler/compiler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Work/Projects/Morris/src/compiler/compiler.cpp > CMakeFiles/Morris.dir/src/compiler/compiler.cpp.i

CMakeFiles/Morris.dir/src/compiler/compiler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Morris.dir/src/compiler/compiler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Work/Projects/Morris/src/compiler/compiler.cpp -o CMakeFiles/Morris.dir/src/compiler/compiler.cpp.s

CMakeFiles/Morris.dir/src/engine/MainLoop.cpp.o: CMakeFiles/Morris.dir/flags.make
CMakeFiles/Morris.dir/src/engine/MainLoop.cpp.o: ../src/engine/MainLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Morris.dir/src/engine/MainLoop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Morris.dir/src/engine/MainLoop.cpp.o -c /home/sean/Work/Projects/Morris/src/engine/MainLoop.cpp

CMakeFiles/Morris.dir/src/engine/MainLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Morris.dir/src/engine/MainLoop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Work/Projects/Morris/src/engine/MainLoop.cpp > CMakeFiles/Morris.dir/src/engine/MainLoop.cpp.i

CMakeFiles/Morris.dir/src/engine/MainLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Morris.dir/src/engine/MainLoop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Work/Projects/Morris/src/engine/MainLoop.cpp -o CMakeFiles/Morris.dir/src/engine/MainLoop.cpp.s

CMakeFiles/Morris.dir/src/Simulation/Agent.cpp.o: CMakeFiles/Morris.dir/flags.make
CMakeFiles/Morris.dir/src/Simulation/Agent.cpp.o: ../src/Simulation/Agent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Morris.dir/src/Simulation/Agent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Morris.dir/src/Simulation/Agent.cpp.o -c /home/sean/Work/Projects/Morris/src/Simulation/Agent.cpp

CMakeFiles/Morris.dir/src/Simulation/Agent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Morris.dir/src/Simulation/Agent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Work/Projects/Morris/src/Simulation/Agent.cpp > CMakeFiles/Morris.dir/src/Simulation/Agent.cpp.i

CMakeFiles/Morris.dir/src/Simulation/Agent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Morris.dir/src/Simulation/Agent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Work/Projects/Morris/src/Simulation/Agent.cpp -o CMakeFiles/Morris.dir/src/Simulation/Agent.cpp.s

CMakeFiles/Morris.dir/src/Simulation/XForm.cpp.o: CMakeFiles/Morris.dir/flags.make
CMakeFiles/Morris.dir/src/Simulation/XForm.cpp.o: ../src/Simulation/XForm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Morris.dir/src/Simulation/XForm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Morris.dir/src/Simulation/XForm.cpp.o -c /home/sean/Work/Projects/Morris/src/Simulation/XForm.cpp

CMakeFiles/Morris.dir/src/Simulation/XForm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Morris.dir/src/Simulation/XForm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Work/Projects/Morris/src/Simulation/XForm.cpp > CMakeFiles/Morris.dir/src/Simulation/XForm.cpp.i

CMakeFiles/Morris.dir/src/Simulation/XForm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Morris.dir/src/Simulation/XForm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Work/Projects/Morris/src/Simulation/XForm.cpp -o CMakeFiles/Morris.dir/src/Simulation/XForm.cpp.s

# Object files for target Morris
Morris_OBJECTS = \
"CMakeFiles/Morris.dir/main.cpp.o" \
"CMakeFiles/Morris.dir/src/compiler/Tokenizer.cpp.o" \
"CMakeFiles/Morris.dir/src/compiler/Tokens.cpp.o" \
"CMakeFiles/Morris.dir/src/compiler/Parser.cpp.o" \
"CMakeFiles/Morris.dir/src/compiler/InstructionASTVisitor.cpp.o" \
"CMakeFiles/Morris.dir/src/compiler/SymbolTable.cpp.o" \
"CMakeFiles/Morris.dir/src/runtime/VirtualMachine.cpp.o" \
"CMakeFiles/Morris.dir/src/compiler/Instructions.cpp.o" \
"CMakeFiles/Morris.dir/src/compiler/compiler.cpp.o" \
"CMakeFiles/Morris.dir/src/engine/MainLoop.cpp.o" \
"CMakeFiles/Morris.dir/src/Simulation/Agent.cpp.o" \
"CMakeFiles/Morris.dir/src/Simulation/XForm.cpp.o"

# External object files for target Morris
Morris_EXTERNAL_OBJECTS =

Morris: CMakeFiles/Morris.dir/main.cpp.o
Morris: CMakeFiles/Morris.dir/src/compiler/Tokenizer.cpp.o
Morris: CMakeFiles/Morris.dir/src/compiler/Tokens.cpp.o
Morris: CMakeFiles/Morris.dir/src/compiler/Parser.cpp.o
Morris: CMakeFiles/Morris.dir/src/compiler/InstructionASTVisitor.cpp.o
Morris: CMakeFiles/Morris.dir/src/compiler/SymbolTable.cpp.o
Morris: CMakeFiles/Morris.dir/src/runtime/VirtualMachine.cpp.o
Morris: CMakeFiles/Morris.dir/src/compiler/Instructions.cpp.o
Morris: CMakeFiles/Morris.dir/src/compiler/compiler.cpp.o
Morris: CMakeFiles/Morris.dir/src/engine/MainLoop.cpp.o
Morris: CMakeFiles/Morris.dir/src/Simulation/Agent.cpp.o
Morris: CMakeFiles/Morris.dir/src/Simulation/XForm.cpp.o
Morris: CMakeFiles/Morris.dir/build.make
Morris: CMakeFiles/Morris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable Morris"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Morris.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Morris.dir/build: Morris

.PHONY : CMakeFiles/Morris.dir/build

CMakeFiles/Morris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Morris.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Morris.dir/clean

CMakeFiles/Morris.dir/depend:
	cd /home/sean/Work/Projects/Morris/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sean/Work/Projects/Morris /home/sean/Work/Projects/Morris /home/sean/Work/Projects/Morris/cmake-build-debug-coverage /home/sean/Work/Projects/Morris/cmake-build-debug-coverage /home/sean/Work/Projects/Morris/cmake-build-debug-coverage/CMakeFiles/Morris.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Morris.dir/depend

