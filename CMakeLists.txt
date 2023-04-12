cmake_minimum_required(VERSION 3.4)
project(CallBridge)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})

add_subdirectory(models)
add_subdirectory(view)
add_subdirectory(controllers)

target_link_libraries(${PROJECT_NAME} card)
target_link_libraries(${PROJECT_NAME} deck)
target_link_libraries(${PROJECT_NAME} score)
target_link_libraries(${PROJECT_NAME} player)
target_link_libraries(${PROJECT_NAME} player_engine)
target_link_libraries(${PROJECT_NAME} game_engine)
target_link_libraries(${PROJECT_NAME} game_screen)

target_include_directories(${PROJECT_NAME} PUBLIC models)
target_include_directories(${PROJECT_NAME} PUBLIC contents)
target_include_directories(${PROJECT_NAME} PUBLIC controllers)
target_include_directories(${PROJECT_NAME} PUBLIC view)

# target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR})
