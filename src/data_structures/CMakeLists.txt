project(data_structures)

set(SRC_FILES note_data.cpp)

add_library(data_structures OBJECT ${SRC_FILES})
target_link_libraries(data_structures sfml-graphics sfml-audio sfml-window)
