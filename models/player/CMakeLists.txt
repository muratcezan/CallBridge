cmake_minimum_required(VERSION 3.4)
project(player VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED player.h player.cpp)

target_link_libraries(${PROJECT_NAME} score)

target_include_directories(${PROJECT_NAME} PUBLIC ../)