# cmake_minimum_required(VERSION 3.4)
# project(Models VERSION 1.0.0)

add_subdirectory(card)
add_subdirectory(deck)
# add_subdirectory(desk)
add_subdirectory(player)
add_subdirectory(score)

target_include_directories(${PROJECT_NAME} PUBLIC ../contents)
