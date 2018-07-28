#pragma once

#include "base_screenstate.h"

class menu : public base_screenstate
{
public:
	menu();
	void loop_function() override;
	void input_handler(sf::Keyboard::Key key) override;
	~menu() override;
private:
	void load_textures() override;
	void create_sprites() override;
	void create_logic() override;

	sf::Texture stepmania_texture;
	sf::Sprite stepmania_sprite;

	sf::Font font;
	sf::Text haha;
};