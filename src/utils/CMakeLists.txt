project(utils)

set(SRC_FILES notedata.cpp)

add_library(utils OBJECT ${SRC_FILES})
target_link_libraries(utils sfml-graphics sfml-audio sfml-window)
