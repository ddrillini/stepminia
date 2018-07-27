#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <queue>
#include <ctime>

#include "../all_includes.h"

int main()
{
	std::cout << "Note that stepminia must currently be run from the \
executable's directory, because it expects the assets folder to be in the \
current working directory." << std::endl;

// trying a way of organizing code that i haven't before.
// can you tell i write a lot of c? haha what's an OOP

#include "window_setup.cpp"

	// base_screenstate screenstate;
	// because this is an abstract base class, we can't instantiate it.
	// however, i want to use it so that i can have any child be the name
	// "screenstate" and use that to eg draw things
	// i think i can just use children in places that expect the parent type
	base_screenstate * screenstate;
	playfield playfield_inst;
	menu menu_inst;

	screenstate = &playfield_inst;

#include "receptor_setup.cpp"

#include "main_loop.cpp"

	return EXIT_SUCCESS;
}
