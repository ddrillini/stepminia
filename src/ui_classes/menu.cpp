#include "menu.hpp"

menu::menu()
{
	load_textures();
	create_sprites();
	create_logic();
}

menu::~menu()
{

}

void menu::loop_function()
{

}

void menu::load_textures()
{
	if (!stepmania_texture.loadFromFile("assets/stepmania-icon.png"))
		abort();
}

void menu::create_sprites()
{
	stepmania_sprite = sf::Sprite(stepmania_texture);
	stepmania_sprite.setScale(.1, .1);

	// none of this will draw, because the draw vector currently only accepts sprites.
	// we can get around this by writing a proper drawing thing.
	font.loadFromFile("assets/arial.ttf");
	haha = sf::Text("get it it's stepmania but mini", font);
	haha.setFillColor(sf::Color::Red);

	sprite_draw_vector.push_back(&stepmania_sprite);
}

void menu::create_logic()
{

}

void menu::input_handler(sf::Keyboard::Key key)
{

}
