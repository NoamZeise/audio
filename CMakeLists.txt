cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(audio)

add_subdirectory(src)

if(BUILD_DEMO)
  add_subdirectory(demo)
endif()
