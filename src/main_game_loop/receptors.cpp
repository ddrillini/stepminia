// included by main.cpp
// one shitty thing about organizing code in this way is that you can't
// really put includes inside of these files; they should go outside of the
// main function.

// Load a sprite to display
sf::Texture receptor_texture;
if (!receptor_texture.loadFromFile("assets/receptor.png"))
	return EXIT_FAILURE;

// we'll probably turn these into receptors eventually
sf::Sprite left(receptor_texture), down(receptor_texture), up(receptor_texture),
	right(receptor_texture);

std::vector<sf::Sprite> receptor_vector = {left, down, up, right};

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

// from transformable.
// up.setRotation(150); // rotates around the origin, which is the
// top-left pixel. there's also rotate, which just
// adds to the current rotation.
// for now, gonna skip rotations because i'd rather figure out how to
// have arrows happen.

