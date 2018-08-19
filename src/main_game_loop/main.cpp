#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <queue>
#include <ctime>

#include "../all_includes.hpp"

int main()
{
	std::cout << "Note that stepminia must currently be run from the"
		<< " executable's directory, because it expects the assets folder"
		<< " to be in the current working directory." << std::endl;

	// = Window Setup =====================================================
	// OpenGL settings. Aliasing, bit depth, etc.
	sf::ContextSettings context_settings;
	context_settings.antialiasingLevel = 8;

	// To draw stuff, you can also use OpenGL directly and totally ignore
	// the sfml-graphics module. sf::Window internally creates an OpenGL
	// context and is ready to accept your OpenGL calls.
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),	
		"stepminia", sf::Style::None, context_settings);

	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);

	// sf::Style::Fullscreen on mac prints "The requested video mode is not
	// available, switching to a valid mode" and then goes fullscreen, but
	// doesn't scale up to my resolution.

	// we may want to offload the window drawing to a thread.
	// see: https://www.sfml-dev.org/tutorials/2.5/graphics-draw.php,
	// bottom of page.

	// = End Window Setup =================================================

	// = UI Setup =========================================================
	playfield playfield_inst;
	menu menu_inst;

	// Pointer for housing state
	base_screenstate* screenstate(&playfield_inst);

	// = Simfile Reading ==================================================

	// notedata simfile_inst("songs/first/\"\"\"simfile\"\"\".sm");
	notedata simfile_inst("songs/Checkpoint/Checkpoint.sm");
	playfield_inst.active_simfile = simfile_inst;

	// = Main Loop ========================================================

	while (window.isOpen())
	{
		sf::Time current_time;
		sf::Event event;

		while (window.pollEvent(event))
		{
			// Global keypresses (ie, not per-screen)
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();

				if (event.key.code == sf::Keyboard::Num1) 
				{
					screenstate = &menu_inst;
				}
					
				if (event.key.code == sf::Keyboard::Num2) 
				{
					screenstate = &playfield_inst;
				}	

				// otherwise defer to the active screen class's input
				// handler
				screenstate->input_handler(event.key.code);
			}
		}

		// Every state has a function that's called every loop, for things
		// that depend on the frame. Since that's 60fps, arrow/timing
		// calculations should probably happen... in another thread?
		// I'm not sure how fast this game loop runs. It's either tied to
		// the framerate and therefore capped at 60fps, or it's as fast as
		// possible. But, I doubt that's the case, else it'd tear up my CPU
		// fan.
		screenstate->loop_function();

		// = Drawing functions ============================================
		window.clear(); // clear screen

		// Draw from static vector
		for (auto &sprite : screenstate->sprite_draw_vector) 
			window.draw(*sprite);

		// Draw from dynamic vector
		for (auto &sprite : screenstate->dynamic_draw_vector) 
			window.draw(*sprite);

		// empty dynamic vector
		while ( ! screenstate->dynamic_draw_vector.empty() )
			screenstate->dynamic_draw_vector.pop_back();

		// Update the window
		window.display();
	}
	// = End Main Loop ====================================================
}
