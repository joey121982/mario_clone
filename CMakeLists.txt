cmake_minimum_required(VERSION 3.7)

project(mario_clone)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(mario_clone src/main.cpp src/game.cpp)
target_link_libraries(mario_clone ${SDL2_LIBRARIES})