add_subdirectory(game_engine)
add_subdirectory(player_engine)

target_include_directories(${PROJECT_NAME} PUBLIC ../contents)
