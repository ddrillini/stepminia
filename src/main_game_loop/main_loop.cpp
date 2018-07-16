// included by main.cpp
// Start the game loop
while (window.isOpen())
{
	// Process events
	sf::Event event;
	while (window.pollEvent(event))
	{
		// Close window: exit
		if (event.type == sf::Event::Closed)
			window.close();
		
		// for now just register stuff?
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				window.close();

			if (event.key.code == sf::Keyboard::I)
				receptor_vector[LEFT].move(sf::Vector2f(0, 10));

			if (event.key.code == sf::Keyboard::D)
				receptor_vector[DOWN].move(sf::Vector2f(0, 10));

			if (event.key.code == sf::Keyboard::F)
				receptor_vector[UP].move(sf::Vector2f(0, 10));

			if (event.key.code == sf::Keyboard::H)
				receptor_vector[RIGHT].move(sf::Vector2f(0, 10));
		}
			
	}

#include "receptor_blinking.cpp"

// = Redrawing ==============================================================

	// Clear screen
	window.clear();

	// Draw the sprites 
	int i = 0;
	for ( auto &sprite : receptor_vector )
		window.draw(sprite);

	// Update the window
	window.display();
}
