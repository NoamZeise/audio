cmake_minimum_required(VERSION 3.10)

set(ProjectName "Audio")
# set the project name
project(${ProjectName} VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

if(UNIX)
  set(CMAKE_CXX_FLAGS "-O2 -std=c++14")
  set(CMAKE_EXE_LINKER_FLAGS "-v")
elseif(MSVC)
  set(CMAKE_CXX_FLAGS_DEBUG_INIT "/DDEBUG /MTd /Zi /Ob0 /Od /RTC1 /std:c++14")
  set(CMAKE_CXX_FLAGS_RELEASE_INIT "/MT /Zi /O2 /Ob1 /DNDEBUG /std:c++14")
endif()

file(GLOB SOURCES src/*)
add_executable(${ProjectName} ${SOURCES}
                              ${PROJ_INCLUDE})

if(UNIX)
    target_link_libraries(${ProjectName} sndfile)
    target_link_libraries(${ProjectName} portaudio)
elseif(MSVC)
  target_include_directories(${ProjectName} PUBLIC D:/noam4/Libraries/VS/include)
  target_link_libraries(${ProjectName} D:/noam4/Libraries/VS/lib/x64/portaudio_x64.lib
                                     D:/noam4/Libraries/VS/lib/x64/sndfile.lib)
endif()
