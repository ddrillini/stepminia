#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

// apparently you can't have dashes in identifiers?
class base_screenstate
{
	public:
		std::vector<sf::Sprite *> sprite_draw_vector;
		virtual void loop_function() = 0;
	private:
		// virtual means we defers to a child classes' implementation.
		virtual void load_textures() = 0;
		virtual void create_sprites() = 0;
		virtual void create_logic() = 0;
};

// the default constructor for screenstate should load all the stuff needed
// initially into the vector.
