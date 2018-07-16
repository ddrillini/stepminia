project(main_game_loop)

set(SRC_FILES main.cpp)

add_executable(stepminia ${SRC_FILES})
target_link_libraries(stepminia sfml-graphics sfml-audio sfml-window)
