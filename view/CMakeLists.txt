cmake_minimum_required(VERSION 3.4)
project(game_screen VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED game_screen.h game_screen.cpp)

target_link_libraries(${PROJECT_NAME} player_engine)

target_include_directories(${PROJECT_NAME} PUBLIC ../models)
target_include_directories(${PROJECT_NAME} PUBLIC ../controllers)