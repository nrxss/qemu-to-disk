cmake_minimum_required(VERSION 3.10)
project(qemu-to-disk)

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/dist")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})

add_subdirectory(src/lib)
add_executable(
    qemu-to-disk src/main.cpp
)

target_link_libraries(
    qemu-to-disk # Main executable

    Shell
)
