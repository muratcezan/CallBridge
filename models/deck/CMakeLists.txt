cmake_minimum_required(VERSION 3.4)
project(deck VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED deck.h deck.cpp)

target_link_libraries(${PROJECT_NAME} card)

target_include_directories(${PROJECT_NAME} PUBLIC ../)
target_include_directories(${PROJECT_NAME} PUBLIC ../../contents)