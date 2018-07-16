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
				arrow_vector[LEFT].move(sf::Vector2f(0, 10));

			if (event.key.code == sf::Keyboard::D)
				arrow_vector[DOWN].move(sf::Vector2f(0, 10));

			if (event.key.code == sf::Keyboard::F)
				arrow_vector[UP].move(sf::Vector2f(0, 10));

			if (event.key.code == sf::Keyboard::H)
				arrow_vector[RIGHT].move(sf::Vector2f(0, 10));
		}
			
	}
	// Clear screen
	window.clear();

	// Draw the sprites 
	int i = 0;
	for ( auto &sprite : arrow_vector )
		window.draw(sprite);

	// Update the window
	window.display();
}
