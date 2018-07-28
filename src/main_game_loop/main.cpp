#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <queue>
#include <ctime>

#include "../all_includes.h"

#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#endif

int main()
{
	std::cout << "Note that stepminia must currently be run from the"
		<< " executable's directory, because it expects the assets folder"
		<< " to be in the current working directory." << std::endl;

	// WINDOW SETUP ------------------------------------------------------

	// OpenGL settings. Aliasing, bit depth, etc.
	// sf::ContextSettings context_settings;
	// context_settings.antialiasingLevel = 8;

	// To draw stuff, you can also use OpenGL directly and totally ignore
	// the sfml-graphics module. sf::Window internally creates an OpenGL
	// context and is ready to accept your OpenGL calls.
	//sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
	//	"stepminia", sf::Style::None, context_settings);

	//window.setKeyRepeatEnabled(false);
	//window.setFramerateLimit(60);

	// sf::Style::Fullscreen on mac prints "The requested video mode is not
	// available, switching to a valid mode" and then goes fullscreen, but
	// doesn't scale up to my resolution.

	// we may want to offload the window drawing to a thread.
	// see: https://www.sfml-dev.org/tutorials/2.5/graphics-draw.php,
	// bottom of page.

	// -------------------------------------------------------------------

	////Game States
	////playfield playfield_inst;
	////menu menu_inst;

	////Pointer for housing state
	////base_screenstate* screenstate(&playfield_inst);

	//// RECEPTOR SETUP -----------------------------------------------------------------------

	///*
	//// receptor blinking
	//sf::Clock receptor_clock;
	//sf::Time receptor_time = receptor_clock.getElapsedTime();

	//std::queue<sf::Texture> receptor_texture_queue {{{ receptor_texture_1, receptor_texture_2 }}};
	//*/

	//// --------------------------------------------------------------------------------------

	//// MAIN LOOP ----------------------------------------------------------------------------

	//while (window.isOpen())
	//{
	//	sf::Time current_time;

	//	// Process events
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::KeyPressed)
	//		{
	//			if (event.key.code == sf::Keyboard::Escape)
	//				window.close();

	//			if (event.key.code == sf::Keyboard::Num1)
	//				screenstate = &menu_inst;

	//			if (event.key.code == sf::Keyboard::Num2)
	//				screenstate = &playfield_inst;

	//			screenstate->input_handler(event.key.code);
	//		}
	//	}

	//	/*
	//	// blinking
	//	receptor_time = receptor_clock.getElapsedTime();
	//	if ( receptor_time >= sf::milliseconds(1000) )
	//	{
	//	receptor_clock.restart();

	//	// rotate the queue
	//	receptor_texture_queue.push(receptor_temp_texture);
	//	receptor_temp_texture = receptor_texture_queue.front();
	//	receptor_texture_queue.pop();

	//	receptor_texture_0.swap(receptor_temp_texture);
	//	}
	//	*/
	//	screenstate->loop_function();

	//	// = Clear screen ===========================================================
	//	window.clear();

	//	// = Draw from screenstate vector ===========================================
	//	for (auto &sprite : screenstate->sprite_draw_vector)
	//		window.draw(*sprite);

	//	// = Update the window ======================================================
	//	window.display();
	//}

	//// --------------------------------------------------------------------------------------

	#ifdef _WIN32
	_CrtDumpMemoryLeaks();
	#endif
}
