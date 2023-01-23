find_package(sndfile QUIET)

if(NOT sndfile_FOUND)
  message(WARNING "unable to find sndfile, it might still be found during building")
endif()
find_package(portaudio QUIET)
if(NOT portaudio_FOUND)
  message(WARNING "unable to find portaudio, it might still be found during building")
endif()

add_library(audio audio.cpp)

target_include_directories(audio PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include/")

target_link_libraries(audio PRIVATE sndfile portaudio)
