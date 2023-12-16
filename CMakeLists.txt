cmake_minimum_required(VERSION 3.22)

project(mario_clone)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file (GLOB SOURCES "src/*.cpp")
add_executable(mario_clone ${SOURCES})
target_link_libraries(mario_clone ${SDL2_LIBRARIES})