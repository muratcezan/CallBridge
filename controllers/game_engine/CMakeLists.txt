cmake_minimum_required(VERSION 3.4)
project(game_engine VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED game_engine.h game_engine.cpp)

target_link_libraries(${PROJECT_NAME} deck game_screen player_engine pthread)

target_include_directories(${PROJECT_NAME} PUBLIC ../)
target_include_directories(${PROJECT_NAME} PUBLIC ../../models)
target_include_directories(${PROJECT_NAME} PUBLIC ../../view)