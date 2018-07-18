// included from main_loop.cpp
if (event.type == sf::Event::KeyPressed)
{
	if (event.key.code == sf::Keyboard::Escape)
		window.close();

	// TODO: this can probably be some kind of map to be less code.
	// we should probably use enums instead of #define's anyway.
	if (event.key.code == sf::Keyboard::I)
		key_clock_vector[LEFT].restart();

	if (event.key.code == sf::Keyboard::D)
		key_clock_vector[DOWN].restart();

	if (event.key.code == sf::Keyboard::F)
		key_clock_vector[UP].restart();

	if (event.key.code == sf::Keyboard::H)
		key_clock_vector[RIGHT].restart();
}
