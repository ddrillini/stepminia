// included from main_loop.cpp
if (event.type == sf::Event::KeyPressed)
{
	if (event.key.code == sf::Keyboard::Escape)
		window.close();

	// TODO: this can probably be some kind of map to be less code.
	// we should probably use enums instead of #define's anyway.
	if (event.key.code == sf::Keyboard::I)
		screenstate.shrink_receptor(LEFT);

	if (event.key.code == sf::Keyboard::D)
		screenstate.shrink_receptor(DOWN);

	if (event.key.code == sf::Keyboard::F)
		screenstate.shrink_receptor(UP);

	if (event.key.code == sf::Keyboard::H)
		screenstate.shrink_receptor(RIGHT);
}
