#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class base_screenstate
{
	public:
		std::vector<sf::Sprite*> sprite_draw_vector; // static objects (ui elements)
		std::vector< std::shared_ptr<sf::Sprite> > dynamic_draw_vector; // dynamic objects (arrows)
		virtual void loop_function() = 0;
		virtual void input_handler(sf::Keyboard::Key key) = 0;
		virtual ~base_screenstate() {}
	private:
		virtual void load_textures() = 0;
		virtual void create_sprites() = 0;
		virtual void create_logic() = 0;
};

// the default constructor for screenstate should load all the stuff needed initially into the vector.
