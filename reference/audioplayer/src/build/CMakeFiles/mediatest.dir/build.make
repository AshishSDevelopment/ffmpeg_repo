# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/build

# Include any dependencies generated for this target.
include CMakeFiles/mediatest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mediatest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mediatest.dir/flags.make

CMakeFiles/mediatest.dir/audiochunk.cpp.o: CMakeFiles/mediatest.dir/flags.make
CMakeFiles/mediatest.dir/audiochunk.cpp.o: ../audiochunk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mediatest.dir/audiochunk.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mediatest.dir/audiochunk.cpp.o -c /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/audiochunk.cpp

CMakeFiles/mediatest.dir/audiochunk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mediatest.dir/audiochunk.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/audiochunk.cpp > CMakeFiles/mediatest.dir/audiochunk.cpp.i

CMakeFiles/mediatest.dir/audiochunk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mediatest.dir/audiochunk.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/audiochunk.cpp -o CMakeFiles/mediatest.dir/audiochunk.cpp.s

CMakeFiles/mediatest.dir/audioplayer.cpp.o: CMakeFiles/mediatest.dir/flags.make
CMakeFiles/mediatest.dir/audioplayer.cpp.o: ../audioplayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mediatest.dir/audioplayer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mediatest.dir/audioplayer.cpp.o -c /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/audioplayer.cpp

CMakeFiles/mediatest.dir/audioplayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mediatest.dir/audioplayer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/audioplayer.cpp > CMakeFiles/mediatest.dir/audioplayer.cpp.i

CMakeFiles/mediatest.dir/audioplayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mediatest.dir/audioplayer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/audioplayer.cpp -o CMakeFiles/mediatest.dir/audioplayer.cpp.s

CMakeFiles/mediatest.dir/lyricsdownloader.cpp.o: CMakeFiles/mediatest.dir/flags.make
CMakeFiles/mediatest.dir/lyricsdownloader.cpp.o: ../lyricsdownloader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mediatest.dir/lyricsdownloader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mediatest.dir/lyricsdownloader.cpp.o -c /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/lyricsdownloader.cpp

CMakeFiles/mediatest.dir/lyricsdownloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mediatest.dir/lyricsdownloader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/lyricsdownloader.cpp > CMakeFiles/mediatest.dir/lyricsdownloader.cpp.i

CMakeFiles/mediatest.dir/lyricsdownloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mediatest.dir/lyricsdownloader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/lyricsdownloader.cpp -o CMakeFiles/mediatest.dir/lyricsdownloader.cpp.s

CMakeFiles/mediatest.dir/main.cpp.o: CMakeFiles/mediatest.dir/flags.make
CMakeFiles/mediatest.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mediatest.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mediatest.dir/main.cpp.o -c /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/main.cpp

CMakeFiles/mediatest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mediatest.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/main.cpp > CMakeFiles/mediatest.dir/main.cpp.i

CMakeFiles/mediatest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mediatest.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/main.cpp -o CMakeFiles/mediatest.dir/main.cpp.s

# Object files for target mediatest
mediatest_OBJECTS = \
"CMakeFiles/mediatest.dir/audiochunk.cpp.o" \
"CMakeFiles/mediatest.dir/audioplayer.cpp.o" \
"CMakeFiles/mediatest.dir/lyricsdownloader.cpp.o" \
"CMakeFiles/mediatest.dir/main.cpp.o"

# External object files for target mediatest
mediatest_EXTERNAL_OBJECTS =

mediatest: CMakeFiles/mediatest.dir/audiochunk.cpp.o
mediatest: CMakeFiles/mediatest.dir/audioplayer.cpp.o
mediatest: CMakeFiles/mediatest.dir/lyricsdownloader.cpp.o
mediatest: CMakeFiles/mediatest.dir/main.cpp.o
mediatest: CMakeFiles/mediatest.dir/build.make
mediatest: /usr/lib/x86_64-linux-gnu/libavdevice.so
mediatest: /usr/lib/x86_64-linux-gnu/libavformat.so
mediatest: /usr/lib/x86_64-linux-gnu/libavfilter.so
mediatest: /usr/lib/x86_64-linux-gnu/libavcodec.so
mediatest: /usr/lib/x86_64-linux-gnu/libavutil.so
mediatest: /usr/lib/x86_64-linux-gnu/libswscale.so
mediatest: /usr/lib/x86_64-linux-gnu/libswresample.so
mediatest: /usr/lib/x86_64-linux-gnu/libSDLmain.a
mediatest: /usr/lib/x86_64-linux-gnu/libSDL.so
mediatest: /usr/lib/x86_64-linux-gnu/libcurl.so
mediatest: CMakeFiles/mediatest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable mediatest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mediatest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mediatest.dir/build: mediatest

.PHONY : CMakeFiles/mediatest.dir/build

CMakeFiles/mediatest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mediatest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mediatest.dir/clean

CMakeFiles/mediatest.dir/depend:
	cd /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/build /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/build /home/ashish/FFMPEG_GIT/ffmpeg_repo/reference/audioplayer/src/build/CMakeFiles/mediatest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mediatest.dir/depend

