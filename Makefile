# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/kwon/Desktop/round

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kwon/Desktop/round

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kwon/Desktop/round/CMakeFiles /home/kwon/Desktop/round//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kwon/Desktop/round/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named systemSoft

# Build rule for target.
systemSoft: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 systemSoft
.PHONY : systemSoft

# fast build rule for target.
systemSoft/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/build
.PHONY : systemSoft/fast

Init.o: Init.c.o
.PHONY : Init.o

# target to build an object file
Init.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/Init.c.o
.PHONY : Init.c.o

Init.i: Init.c.i
.PHONY : Init.i

# target to preprocess a source file
Init.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/Init.c.i
.PHONY : Init.c.i

Init.s: Init.c.s
.PHONY : Init.s

# target to generate assembly for a file
Init.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/Init.c.s
.PHONY : Init.c.s

Scheduler.o: Scheduler.c.o
.PHONY : Scheduler.o

# target to build an object file
Scheduler.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/Scheduler.c.o
.PHONY : Scheduler.c.o

Scheduler.i: Scheduler.c.i
.PHONY : Scheduler.i

# target to preprocess a source file
Scheduler.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/Scheduler.c.i
.PHONY : Scheduler.c.i

Scheduler.s: Scheduler.c.s
.PHONY : Scheduler.s

# target to generate assembly for a file
Scheduler.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/Scheduler.c.s
.PHONY : Scheduler.c.s

TestCase1.o: TestCase1.c.o
.PHONY : TestCase1.o

# target to build an object file
TestCase1.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/TestCase1.c.o
.PHONY : TestCase1.c.o

TestCase1.i: TestCase1.c.i
.PHONY : TestCase1.i

# target to preprocess a source file
TestCase1.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/TestCase1.c.i
.PHONY : TestCase1.c.i

TestCase1.s: TestCase1.c.s
.PHONY : TestCase1.s

# target to generate assembly for a file
TestCase1.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/TestCase1.c.s
.PHONY : TestCase1.c.s

TestCase2.o: TestCase2.c.o
.PHONY : TestCase2.o

# target to build an object file
TestCase2.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/TestCase2.c.o
.PHONY : TestCase2.c.o

TestCase2.i: TestCase2.c.i
.PHONY : TestCase2.i

# target to preprocess a source file
TestCase2.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/TestCase2.c.i
.PHONY : TestCase2.c.i

TestCase2.s: TestCase2.c.s
.PHONY : TestCase2.s

# target to generate assembly for a file
TestCase2.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/TestCase2.c.s
.PHONY : TestCase2.c.s

Thread.o: Thread.c.o
.PHONY : Thread.o

# target to build an object file
Thread.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/Thread.c.o
.PHONY : Thread.c.o

Thread.i: Thread.c.i
.PHONY : Thread.i

# target to preprocess a source file
Thread.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/Thread.c.i
.PHONY : Thread.c.i

Thread.s: Thread.c.s
.PHONY : Thread.s

# target to generate assembly for a file
Thread.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/Thread.c.s
.PHONY : Thread.c.s

doubleLink.o: doubleLink.c.o
.PHONY : doubleLink.o

# target to build an object file
doubleLink.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/doubleLink.c.o
.PHONY : doubleLink.c.o

doubleLink.i: doubleLink.c.i
.PHONY : doubleLink.i

# target to preprocess a source file
doubleLink.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/doubleLink.c.i
.PHONY : doubleLink.c.i

doubleLink.s: doubleLink.c.s
.PHONY : doubleLink.s

# target to generate assembly for a file
doubleLink.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/doubleLink.c.s
.PHONY : doubleLink.c.s

main.o: main.c.o
.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i
.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s
.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/main.c.s
.PHONY : main.c.s

threadCon.o: threadCon.c.o
.PHONY : threadCon.o

# target to build an object file
threadCon.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/threadCon.c.o
.PHONY : threadCon.c.o

threadCon.i: threadCon.c.i
.PHONY : threadCon.i

# target to preprocess a source file
threadCon.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/threadCon.c.i
.PHONY : threadCon.c.i

threadCon.s: threadCon.c.s
.PHONY : threadCon.s

# target to generate assembly for a file
threadCon.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/systemSoft.dir/build.make CMakeFiles/systemSoft.dir/threadCon.c.s
.PHONY : threadCon.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... systemSoft"
	@echo "... Init.o"
	@echo "... Init.i"
	@echo "... Init.s"
	@echo "... Scheduler.o"
	@echo "... Scheduler.i"
	@echo "... Scheduler.s"
	@echo "... TestCase1.o"
	@echo "... TestCase1.i"
	@echo "... TestCase1.s"
	@echo "... TestCase2.o"
	@echo "... TestCase2.i"
	@echo "... TestCase2.s"
	@echo "... Thread.o"
	@echo "... Thread.i"
	@echo "... Thread.s"
	@echo "... doubleLink.o"
	@echo "... doubleLink.i"
	@echo "... doubleLink.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... threadCon.o"
	@echo "... threadCon.i"
	@echo "... threadCon.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

