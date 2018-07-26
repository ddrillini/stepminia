// included by main.cpp
while (window.isOpen())
{
	sf::Time current_time;

	// Process events
	sf::Event event;
	while (window.pollEvent(event))
	{
		// Close window: exit
		if (event.type == sf::Event::Closed)
			window.close();

		#include "keypresses.cpp"

	}

#include "receptor_loop_logic.cpp"

	screenstate->loop_function();

#include "draw_screen.cpp"

}
