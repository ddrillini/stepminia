// included from main_loop.cpp
if (event.type == sf::Event::KeyPressed)
{
	if (event.key.code == sf::Keyboard::Escape)
		window.close();

	if (event.key.code == sf::Keyboard::Enter)
		screenstate = &menu_inst;

	screenstate->input_handler(event.key.code);
}
