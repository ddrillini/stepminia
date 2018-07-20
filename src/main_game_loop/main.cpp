#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <queue>
#include <ctime>

#include "../includes.h"

// TODO: make a file that includes all of these
#include "../ui_classes/base_screenstate.hpp"
#include "../ui_classes/playfield.hpp"

// Scales a receptor based on the time since a given
// key was last pressed. Range: 0 to .1 seconds
void scale_receptor(sf::Time t, sf::Sprite & receptor)
{
	float scale = t.asSeconds() * 2 + .8;
	receptor.setScale(scale, scale);
}

int main()
{
	std::cout << "Note that stepminia must currently be run from the \
executable's directory, because it expects the assets folder to be in the \
current working directory." << std::endl;

// trying a way of organizing code that i haven't before.
// can you tell i write a lot of c? haha what's an OOP

#include "window_setup.cpp"

#include "textures.cpp"

	playfield playfield1;
	sf::Sprite arrow(arrow_texture);
	playfield1.sprite_vector.push_back(arrow);

#include "receptor_setup.cpp"

#include "main_loop.cpp"

	return EXIT_SUCCESS;
}
