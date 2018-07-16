// included by main.cpp
// one shitty thing about organizing code in this way is that you can't
// really put includes inside of these files; they should go outside of the
// main function.

// Load a sprite to display
sf::Texture arrow_texture;
if (!arrow_texture.loadFromFile("assets/arrow.png")) // TODO: change this to receptors
	return EXIT_FAILURE;

// we'll probably turn these into receptors eventually
sf::Sprite left(arrow_texture), down(arrow_texture), up(arrow_texture),
	right(arrow_texture);

std::vector<sf::Sprite> arrow_vector = {left, down, up, right};

int offset = ARROW_SIZE * -1.5;
for ( auto &sprite : arrow_vector )
{
	sprite.setPosition(WINDOW_X_CENTER + offset,
		OFFSET_FROM_TOP_OF_SCREEN+32);
	offset += ARROW_SIZE;
}

for ( auto &sprite : arrow_vector )
	sprite.setOrigin( ARROW_SIZE/2, ARROW_SIZE/2 );

arrow_vector[DOWN].rotate(-90);
arrow_vector[UP].rotate(90);
arrow_vector[RIGHT].rotate(180);

// from transformable.
// up.setRotation(150); // rotates around the origin, which is the
// top-left pixel. there's also rotate, which just
// adds to the current rotation.
// for now, gonna skip rotations because i'd rather figure out how to
// have arrows happen.

