project(main_game_loop)

set(SRC_FILES main.cpp)

add_library(main_game_loop OBJECT ${SRC_FILES})
target_link_libraries(main_game_loop sfml-graphics sfml-audio sfml-window)
