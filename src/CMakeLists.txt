find_package(sndfile REQUIRED)
find_package(portaudio REQUIRED)

add_library(audio audio.cpp)

target_include_directories(audio PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include/")
target_link_libraries(audio PRIVATE SndFile::sndfile portaudio_static)
