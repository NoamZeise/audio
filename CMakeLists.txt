cmake_minimum_required(VERSION 3.10)

set(ProjectName "Audio")
# set the project name
project(${ProjectName} VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "/DDEBUG /MTd /Zi /Ob0 /Od /RTC1 /std:c++14")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "/MT /Zi /O2 /Ob1 /DNDEBUG /std:c++14")


file(GLOB SOURCES src/*)
add_executable(${ProjectName} ${SOURCES} 
                              ${PROJ_INCLUDE})

target_include_directories(${ProjectName} PUBLIC D:/noam4/Libraries/VS/include)
target_link_libraries(${ProjectName} D:/noam4/Libraries/VS/lib/x64/portaudio_x64.lib 
                                     D:/noam4/Libraries/VS/lib/x64/sndfile.lib)