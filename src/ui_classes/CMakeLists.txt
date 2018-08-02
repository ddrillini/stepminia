# object libraries are a cmake thing that enable you to compile a bunch of
# object files but not necessarily link them into anything. 
# then, you can add them as sources in a top level project.

set(UI_CLASSES_SOURCES
	"menu.cpp"
	"playfield.cpp"
)

# i'm not sure what the difference is between an object and static library. either works.
add_library(ui_classes OBJECT "${UI_CLASSES_SOURCES}")

# we have sfml-graphics, which is a cmake variable that refers to... what?
# why not use target_include_directories? what's the difference between the two?

# as far as i can tell, targets and variables are on different namespaces.
target_link_libraries(ui_classes sfml-graphics)
