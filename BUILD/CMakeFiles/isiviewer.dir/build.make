# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD"

# Include any dependencies generated for this target.
include CMakeFiles/isiviewer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/isiviewer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/isiviewer.dir/flags.make

ui_my_gui_form.h: /home/shinji/Documents/MASTER\ TI/ISI/TP\ 3/isiviewer_glut/my_gui_form.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Generating ui_my_gui_form.h"
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic -o "/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/ui_my_gui_form.h" "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_gui_form.ui"

moc_my_main_window.cxx: /home/shinji/Documents/MASTER\ TI/ISI/TP\ 3/isiviewer_glut/my_main_window.h
moc_my_main_window.cxx: moc_my_main_window.cxx_parameters
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Generating moc_my_main_window.cxx"
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc "@/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/moc_my_main_window.cxx_parameters"

moc_my_scene.cxx: /home/shinji/Documents/MASTER\ TI/ISI/TP\ 3/isiviewer_glut/my_scene.h
moc_my_scene.cxx: moc_my_scene.cxx_parameters
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Generating moc_my_scene.cxx"
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc "@/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/moc_my_scene.cxx_parameters"

CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o: CMakeFiles/isiviewer.dir/flags.make
CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o: moc_my_main_window.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o -c "/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/moc_my_main_window.cxx"

CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/moc_my_main_window.cxx" > CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.i

CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/moc_my_main_window.cxx" -o CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.s

CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o.requires:

.PHONY : CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o.requires

CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o.provides: CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o.requires
	$(MAKE) -f CMakeFiles/isiviewer.dir/build.make CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o.provides.build
.PHONY : CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o.provides

CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o.provides.build: CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o


CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o: CMakeFiles/isiviewer.dir/flags.make
CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o: moc_my_scene.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o -c "/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/moc_my_scene.cxx"

CMakeFiles/isiviewer.dir/moc_my_scene.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/isiviewer.dir/moc_my_scene.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/moc_my_scene.cxx" > CMakeFiles/isiviewer.dir/moc_my_scene.cxx.i

CMakeFiles/isiviewer.dir/moc_my_scene.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/isiviewer.dir/moc_my_scene.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/moc_my_scene.cxx" -o CMakeFiles/isiviewer.dir/moc_my_scene.cxx.s

CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o.requires:

.PHONY : CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o.requires

CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o.provides: CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o.requires
	$(MAKE) -f CMakeFiles/isiviewer.dir/build.make CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o.provides.build
.PHONY : CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o.provides

CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o.provides.build: CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o


CMakeFiles/isiviewer.dir/main.cpp.o: CMakeFiles/isiviewer.dir/flags.make
CMakeFiles/isiviewer.dir/main.cpp.o: /home/shinji/Documents/MASTER\ TI/ISI/TP\ 3/isiviewer_glut/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/isiviewer.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/isiviewer.dir/main.cpp.o -c "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/main.cpp"

CMakeFiles/isiviewer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/isiviewer.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/main.cpp" > CMakeFiles/isiviewer.dir/main.cpp.i

CMakeFiles/isiviewer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/isiviewer.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/main.cpp" -o CMakeFiles/isiviewer.dir/main.cpp.s

CMakeFiles/isiviewer.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/isiviewer.dir/main.cpp.o.requires

CMakeFiles/isiviewer.dir/main.cpp.o.provides: CMakeFiles/isiviewer.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/isiviewer.dir/build.make CMakeFiles/isiviewer.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/isiviewer.dir/main.cpp.o.provides

CMakeFiles/isiviewer.dir/main.cpp.o.provides.build: CMakeFiles/isiviewer.dir/main.cpp.o


CMakeFiles/isiviewer.dir/my_main_window.cpp.o: CMakeFiles/isiviewer.dir/flags.make
CMakeFiles/isiviewer.dir/my_main_window.cpp.o: /home/shinji/Documents/MASTER\ TI/ISI/TP\ 3/isiviewer_glut/my_main_window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/isiviewer.dir/my_main_window.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/isiviewer.dir/my_main_window.cpp.o -c "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_main_window.cpp"

CMakeFiles/isiviewer.dir/my_main_window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/isiviewer.dir/my_main_window.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_main_window.cpp" > CMakeFiles/isiviewer.dir/my_main_window.cpp.i

CMakeFiles/isiviewer.dir/my_main_window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/isiviewer.dir/my_main_window.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_main_window.cpp" -o CMakeFiles/isiviewer.dir/my_main_window.cpp.s

CMakeFiles/isiviewer.dir/my_main_window.cpp.o.requires:

.PHONY : CMakeFiles/isiviewer.dir/my_main_window.cpp.o.requires

CMakeFiles/isiviewer.dir/my_main_window.cpp.o.provides: CMakeFiles/isiviewer.dir/my_main_window.cpp.o.requires
	$(MAKE) -f CMakeFiles/isiviewer.dir/build.make CMakeFiles/isiviewer.dir/my_main_window.cpp.o.provides.build
.PHONY : CMakeFiles/isiviewer.dir/my_main_window.cpp.o.provides

CMakeFiles/isiviewer.dir/my_main_window.cpp.o.provides.build: CMakeFiles/isiviewer.dir/my_main_window.cpp.o


CMakeFiles/isiviewer.dir/my_objects.cpp.o: CMakeFiles/isiviewer.dir/flags.make
CMakeFiles/isiviewer.dir/my_objects.cpp.o: /home/shinji/Documents/MASTER\ TI/ISI/TP\ 3/isiviewer_glut/my_objects.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/isiviewer.dir/my_objects.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/isiviewer.dir/my_objects.cpp.o -c "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_objects.cpp"

CMakeFiles/isiviewer.dir/my_objects.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/isiviewer.dir/my_objects.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_objects.cpp" > CMakeFiles/isiviewer.dir/my_objects.cpp.i

CMakeFiles/isiviewer.dir/my_objects.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/isiviewer.dir/my_objects.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_objects.cpp" -o CMakeFiles/isiviewer.dir/my_objects.cpp.s

CMakeFiles/isiviewer.dir/my_objects.cpp.o.requires:

.PHONY : CMakeFiles/isiviewer.dir/my_objects.cpp.o.requires

CMakeFiles/isiviewer.dir/my_objects.cpp.o.provides: CMakeFiles/isiviewer.dir/my_objects.cpp.o.requires
	$(MAKE) -f CMakeFiles/isiviewer.dir/build.make CMakeFiles/isiviewer.dir/my_objects.cpp.o.provides.build
.PHONY : CMakeFiles/isiviewer.dir/my_objects.cpp.o.provides

CMakeFiles/isiviewer.dir/my_objects.cpp.o.provides.build: CMakeFiles/isiviewer.dir/my_objects.cpp.o


CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o: CMakeFiles/isiviewer.dir/flags.make
CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o: /home/shinji/Documents/MASTER\ TI/ISI/TP\ 3/isiviewer_glut/my_qglviewer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o -c "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_qglviewer.cpp"

CMakeFiles/isiviewer.dir/my_qglviewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/isiviewer.dir/my_qglviewer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_qglviewer.cpp" > CMakeFiles/isiviewer.dir/my_qglviewer.cpp.i

CMakeFiles/isiviewer.dir/my_qglviewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/isiviewer.dir/my_qglviewer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_qglviewer.cpp" -o CMakeFiles/isiviewer.dir/my_qglviewer.cpp.s

CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o.requires:

.PHONY : CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o.requires

CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o.provides: CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o.requires
	$(MAKE) -f CMakeFiles/isiviewer.dir/build.make CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o.provides.build
.PHONY : CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o.provides

CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o.provides.build: CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o


CMakeFiles/isiviewer.dir/my_scene.cpp.o: CMakeFiles/isiviewer.dir/flags.make
CMakeFiles/isiviewer.dir/my_scene.cpp.o: /home/shinji/Documents/MASTER\ TI/ISI/TP\ 3/isiviewer_glut/my_scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/isiviewer.dir/my_scene.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/isiviewer.dir/my_scene.cpp.o -c "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_scene.cpp"

CMakeFiles/isiviewer.dir/my_scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/isiviewer.dir/my_scene.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_scene.cpp" > CMakeFiles/isiviewer.dir/my_scene.cpp.i

CMakeFiles/isiviewer.dir/my_scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/isiviewer.dir/my_scene.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/my_scene.cpp" -o CMakeFiles/isiviewer.dir/my_scene.cpp.s

CMakeFiles/isiviewer.dir/my_scene.cpp.o.requires:

.PHONY : CMakeFiles/isiviewer.dir/my_scene.cpp.o.requires

CMakeFiles/isiviewer.dir/my_scene.cpp.o.provides: CMakeFiles/isiviewer.dir/my_scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/isiviewer.dir/build.make CMakeFiles/isiviewer.dir/my_scene.cpp.o.provides.build
.PHONY : CMakeFiles/isiviewer.dir/my_scene.cpp.o.provides

CMakeFiles/isiviewer.dir/my_scene.cpp.o.provides.build: CMakeFiles/isiviewer.dir/my_scene.cpp.o


CMakeFiles/isiviewer.dir/planete.cpp.o: CMakeFiles/isiviewer.dir/flags.make
CMakeFiles/isiviewer.dir/planete.cpp.o: /home/shinji/Documents/MASTER\ TI/ISI/TP\ 3/isiviewer_glut/planete.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/isiviewer.dir/planete.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/isiviewer.dir/planete.cpp.o -c "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/planete.cpp"

CMakeFiles/isiviewer.dir/planete.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/isiviewer.dir/planete.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/planete.cpp" > CMakeFiles/isiviewer.dir/planete.cpp.i

CMakeFiles/isiviewer.dir/planete.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/isiviewer.dir/planete.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/planete.cpp" -o CMakeFiles/isiviewer.dir/planete.cpp.s

CMakeFiles/isiviewer.dir/planete.cpp.o.requires:

.PHONY : CMakeFiles/isiviewer.dir/planete.cpp.o.requires

CMakeFiles/isiviewer.dir/planete.cpp.o.provides: CMakeFiles/isiviewer.dir/planete.cpp.o.requires
	$(MAKE) -f CMakeFiles/isiviewer.dir/build.make CMakeFiles/isiviewer.dir/planete.cpp.o.provides.build
.PHONY : CMakeFiles/isiviewer.dir/planete.cpp.o.provides

CMakeFiles/isiviewer.dir/planete.cpp.o.provides.build: CMakeFiles/isiviewer.dir/planete.cpp.o


CMakeFiles/isiviewer.dir/texture.cpp.o: CMakeFiles/isiviewer.dir/flags.make
CMakeFiles/isiviewer.dir/texture.cpp.o: /home/shinji/Documents/MASTER\ TI/ISI/TP\ 3/isiviewer_glut/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/isiviewer.dir/texture.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/isiviewer.dir/texture.cpp.o -c "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/texture.cpp"

CMakeFiles/isiviewer.dir/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/isiviewer.dir/texture.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/texture.cpp" > CMakeFiles/isiviewer.dir/texture.cpp.i

CMakeFiles/isiviewer.dir/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/isiviewer.dir/texture.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut/texture.cpp" -o CMakeFiles/isiviewer.dir/texture.cpp.s

CMakeFiles/isiviewer.dir/texture.cpp.o.requires:

.PHONY : CMakeFiles/isiviewer.dir/texture.cpp.o.requires

CMakeFiles/isiviewer.dir/texture.cpp.o.provides: CMakeFiles/isiviewer.dir/texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/isiviewer.dir/build.make CMakeFiles/isiviewer.dir/texture.cpp.o.provides.build
.PHONY : CMakeFiles/isiviewer.dir/texture.cpp.o.provides

CMakeFiles/isiviewer.dir/texture.cpp.o.provides.build: CMakeFiles/isiviewer.dir/texture.cpp.o


# Object files for target isiviewer
isiviewer_OBJECTS = \
"CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o" \
"CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o" \
"CMakeFiles/isiviewer.dir/main.cpp.o" \
"CMakeFiles/isiviewer.dir/my_main_window.cpp.o" \
"CMakeFiles/isiviewer.dir/my_objects.cpp.o" \
"CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o" \
"CMakeFiles/isiviewer.dir/my_scene.cpp.o" \
"CMakeFiles/isiviewer.dir/planete.cpp.o" \
"CMakeFiles/isiviewer.dir/texture.cpp.o"

# External object files for target isiviewer
isiviewer_EXTERNAL_OBJECTS =

isiviewer: CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o
isiviewer: CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o
isiviewer: CMakeFiles/isiviewer.dir/main.cpp.o
isiviewer: CMakeFiles/isiviewer.dir/my_main_window.cpp.o
isiviewer: CMakeFiles/isiviewer.dir/my_objects.cpp.o
isiviewer: CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o
isiviewer: CMakeFiles/isiviewer.dir/my_scene.cpp.o
isiviewer: CMakeFiles/isiviewer.dir/planete.cpp.o
isiviewer: CMakeFiles/isiviewer.dir/texture.cpp.o
isiviewer: CMakeFiles/isiviewer.dir/build.make
isiviewer: /usr/lib/x86_64-linux-gnu/libQtOpenGL.so
isiviewer: /usr/lib/x86_64-linux-gnu/libQtGui.so
isiviewer: /usr/lib/x86_64-linux-gnu/libQtXml.so
isiviewer: /usr/lib/x86_64-linux-gnu/libQtCore.so
isiviewer: /usr/lib/x86_64-linux-gnu/libGLU.so
isiviewer: /usr/lib/x86_64-linux-gnu/libGL.so
isiviewer: CMakeFiles/isiviewer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable isiviewer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/isiviewer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/isiviewer.dir/build: isiviewer

.PHONY : CMakeFiles/isiviewer.dir/build

CMakeFiles/isiviewer.dir/requires: CMakeFiles/isiviewer.dir/moc_my_main_window.cxx.o.requires
CMakeFiles/isiviewer.dir/requires: CMakeFiles/isiviewer.dir/moc_my_scene.cxx.o.requires
CMakeFiles/isiviewer.dir/requires: CMakeFiles/isiviewer.dir/main.cpp.o.requires
CMakeFiles/isiviewer.dir/requires: CMakeFiles/isiviewer.dir/my_main_window.cpp.o.requires
CMakeFiles/isiviewer.dir/requires: CMakeFiles/isiviewer.dir/my_objects.cpp.o.requires
CMakeFiles/isiviewer.dir/requires: CMakeFiles/isiviewer.dir/my_qglviewer.cpp.o.requires
CMakeFiles/isiviewer.dir/requires: CMakeFiles/isiviewer.dir/my_scene.cpp.o.requires
CMakeFiles/isiviewer.dir/requires: CMakeFiles/isiviewer.dir/planete.cpp.o.requires
CMakeFiles/isiviewer.dir/requires: CMakeFiles/isiviewer.dir/texture.cpp.o.requires

.PHONY : CMakeFiles/isiviewer.dir/requires

CMakeFiles/isiviewer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/isiviewer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/isiviewer.dir/clean

CMakeFiles/isiviewer.dir/depend: ui_my_gui_form.h
CMakeFiles/isiviewer.dir/depend: moc_my_main_window.cxx
CMakeFiles/isiviewer.dir/depend: moc_my_scene.cxx
	cd "/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut" "/home/shinji/Documents/MASTER TI/ISI/TP 3/isiviewer_glut" "/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD" "/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD" "/home/shinji/Documents/MASTER TI/ISI/TP 3/BUILD/CMakeFiles/isiviewer.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/isiviewer.dir/depend

