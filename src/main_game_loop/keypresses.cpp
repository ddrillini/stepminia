// included from main_loop.cpp
if (event.type == sf::Event::KeyPressed)
{
	if (event.key.code == sf::Keyboard::Escape)
		window.close();

	if (event.key.code == sf::Keyboard::Num1)
		screenstate = &menu_inst;

	if (event.key.code == sf::Keyboard::Num2)
		screenstate = &playfield_inst;

	screenstate->input_handler(event.key.code);
}
