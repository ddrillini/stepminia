cmake_minimum_required(VERSION 3.1)

project(stepminia)
set(CMAKE_CXX_STANDARD 11)

# static libraries. for linux, this is what we want. mac uses "Frameworks"
# and those aren't allowed to be static.
# set(SFML_STATIC_LIBRARIES TRUE)

# this was in the docs, but i'm not sure if it's needed.
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML") ## In most cases better set in the CMake cache

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/stepminia)

find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)
add_subdirectory(src/main_game_loop)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/stepminia)

