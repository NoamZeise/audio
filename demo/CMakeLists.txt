add_executable(audioDemo demo.cpp)

target_link_libraries(audioDemo audio)

add_custom_command(TARGET audioDemo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/../resources"
        $<TARGET_FILE_DIR:audioDemo>)
		