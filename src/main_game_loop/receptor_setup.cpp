// included by main.cpp

// initialize four clocks for receptor shrinking
std::vector<sf::Clock> key_clock_vector( 4, sf::Clock() );

sf::Texture receptor_temp_texture = receptor_texture_3;

// four sprites initialized with receptor_temp_texture
std::vector<sf::Sprite> receptor_vector( 4, sf::Sprite(receptor_temp_texture) );

int offset = ARROW_SIZE * -1.5;
for ( auto &sprite : receptor_vector )
{
	sprite.setPosition(WINDOW_X_CENTER + offset,
		OFFSET_FROM_TOP_OF_SCREEN+32);
	offset += ARROW_SIZE;
}

for ( auto &sprite : receptor_vector )
	sprite.setOrigin( ARROW_SIZE/2, ARROW_SIZE/2 );

receptor_vector[LEFT].rotate(90);
receptor_vector[UP].rotate(180);
receptor_vector[RIGHT].rotate(270);

// receptor blinking
sf::Clock receptor_clock;
sf::Time receptor_time = receptor_clock.getElapsedTime();

std::queue<sf::Texture> receptor_texture_queue {{{ receptor_texture_1, receptor_texture_2 }}};
