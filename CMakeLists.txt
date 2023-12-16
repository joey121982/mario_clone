cmake_minimum_required(VERSION 3.22)

project(mario_clone)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file (GLOB SOURCES "src/*.cpp")

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(output_name "game.exe")
else()
    set(output_name "game")
endif()

add_executable(${output_name} ${SOURCES})
target_link_libraries(${output_name} ${SDL2_LIBRARIES})