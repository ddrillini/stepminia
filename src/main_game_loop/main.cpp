#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "../includes.h"

int main()
{
	std::cout << "Note that stepminia must currently be run from the \
executable's directory, because it expects the assets folder to be in the \
current working directory." << std::endl;

// trying a way of organizing code that i haven't before.
// can you tell i write a lot of c? haha what's an OOP

#include "window_setup.cpp"

#include "textures.cpp"

#include "receptors.cpp"

#include "main_loop.cpp"

	return EXIT_SUCCESS;
}
