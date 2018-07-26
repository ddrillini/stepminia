#pragma once

class menu : public base_screenstate
{
public:
	menu();
	void loop_function();
	void input_handler(sf::Keyboard::Key key);
private:
	void load_textures();
	void create_sprites();
	void create_logic();

};


menu::menu()
{
}

void menu::loop_function()
{
}

void menu::load_textures()
{
}

void menu::create_sprites()
{
}

void menu::create_logic()
{
}

void menu::input_handler(sf::Keyboard::Key key)
{
}
