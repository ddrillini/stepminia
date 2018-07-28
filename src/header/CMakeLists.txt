# object libraries are a cmake thing that enable you to compile a bunch of
# object files but not necessarily link them into anything. 
# then, you can add them as sources in a top level project.

# i'm not sure what the difference is between an object and static library. either works.
add_library(header OBJECT base_screenstate.h menu.h playfield.h)
target_link_libraries(header sfml-graphics)
