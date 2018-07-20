#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

// apparently you can't have dashes in identifiers?
class base_screenstate
{
	public:
		std::vector<sf::Sprite> sprite_vector;
	private:
};

