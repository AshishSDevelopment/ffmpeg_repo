cmake_minimum_required (VERSION 2.8.11)
project(mediaplayer)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fstack-protector-all")

find_package(FFmpeg REQUIRED)
find_package(SDL REQUIRED)

include_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${FFMPEG_INCLUDE_DIR})
include_directories(${SDL_INCLUDE_DIR})

set(MEDIA_SRC
  "${PROJECT_SOURCE_DIR}/player.cpp"
  "${PROJECT_SOURCE_DIR}/main.cpp"
  "${PROJECT_SOURCE_DIR}/streampacket.cpp"
)
add_executable(mediatest  ${MEDIA_SRC})
 set (LIBS
  ${FFMPEG_LIBRARIES}
  ${SDL_LIBRARY}
 )
  
 target_link_libraries(mediatest ${LIBS})

install (TARGETS mediatest DESTINATION usr/bin/)
