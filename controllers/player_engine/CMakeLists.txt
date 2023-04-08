cmake_minimum_required(VERSION 3.4)
project(player_engine VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED player_engine.h player_engine.cpp)

target_link_libraries(${PROJECT_NAME} player)

target_include_directories(${PROJECT_NAME} PUBLIC ../)
target_include_directories(${PROJECT_NAME} PUBLIC ../../contents)
target_include_directories(${PROJECT_NAME} PUBLIC ../../models)