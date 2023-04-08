cmake_minimum_required(VERSION 3.4)
project(card VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED card.h card.cpp)


target_include_directories(${PROJECT_NAME} PUBLIC ../../contents)