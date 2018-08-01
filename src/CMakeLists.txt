cmake_minimum_required(VERSION 3.12)

project(stepminia)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

# static libraries. for linux, this is what we want. mac uses "Frameworks"
# and those aren't allowed to be static.
# set(SFML_STATIC_LIBRARIES TRUE)

# this was in the docs, but i'm not sure if it's needed.
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML") ## In most cases better set in the CMake cache

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/stepminia)

find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)

add_subdirectory(main_game_loop)
add_subdirectory(ui_classes)

# can't be just "ui_classes"; you need to use the object library generator syntax.
# unsure as to why.
add_executable(stepminia $<TARGET_OBJECTS:main_game_loop> $<TARGET_OBJECTS:ui_classes>)
target_link_libraries(stepminia sfml-graphics sfml-audio sfml-window)

file(COPY ../assets DESTINATION ${CMAKE_BINARY_DIR}/stepminia)

