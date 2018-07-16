// included by main.cpp
// one shitty thing about organizing code in this way is that you can't
// really put includes inside of these files; they should go outside of the
// main function.

// Load a sprite to display
sf::Texture texture;
if (!texture.loadFromFile("assets/arrow.png"))
	return EXIT_FAILURE;

// we'll probably turn these into receptors eventually
sf::Sprite left(texture), down(texture), up(texture), right(texture);

// copied in
std::vector<sf::Sprite> arrow_vector = {left, down, up, right};

// set arrow positions
int offset = -ARROW_SIZE * 2;
for ( auto &sprite : arrow_vector )
{
	sprite.setPosition(WINDOW_X_CENTER + offset, 32);
	offset += ARROW_SIZE;
}

// from transformable.
// up.setRotation(150); // rotates around the origin, which is the
// top-left pixel. there's also rotate, which just
// adds to the current rotation.
// for now, gonna skip rotations because i'd rather figure out how to
// have arrows happen.

