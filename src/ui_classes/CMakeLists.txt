# object libraries are a cmake thing that enable you to compile a bunch of
# object files but not necessarily link them into anything. 
# then, you can add them as sources in a top level project.

# i'm not sure what the difference is between an object and static library. either works.
add_library(ui_classes OBJECT base_ui_class.cpp menu.cpp playfield.cpp)
target_link_libraries(ui_classes sfml-graphics)
