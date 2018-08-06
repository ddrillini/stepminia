#include "playfield.hpp"
#include <memory>

// all of these must be included once per link
playfield::playfield()
{
	// what's the difference between these two? nothing.
	// playfield::load_textures();
	this->load_textures(); // accesses the member. however, the this-> is optional
	create_sprites();
	create_logic();
}

playfield::~playfield()
{

}

void playfield::load_textures()
{
	// where should textures get stored? inside the class, one by one?
	// vector?: no, then we can't get at them by name anymore.
	if (!arrow_texture.loadFromFile("assets/arrow.png"))
		abort();

	// = IntRects to chop up the arrow texture ==================================
	sf::IntRect r0(ARROW_SIZE * 0, 0, ARROW_SIZE, ARROW_SIZE); // brightest
	sf::IntRect r1(ARROW_SIZE * 1, 0, ARROW_SIZE, ARROW_SIZE);
	sf::IntRect r2(ARROW_SIZE * 2, 0, ARROW_SIZE, ARROW_SIZE);
	sf::IntRect r3(ARROW_SIZE * 3, 0, ARROW_SIZE, ARROW_SIZE);

	// = Load them into textures ================================================
	if (!active_receptor_texture.loadFromFile("assets/receptor.png", r0))
		abort();

	receptor_texture_vector = std::vector<sf::Texture>(3, sf::Texture());

	if (!receptor_texture_vector[0].loadFromFile("assets/receptor.png", r1))
		abort();

	if (!receptor_texture_vector[1].loadFromFile("assets/receptor.png", r2))
		abort();

	if (!receptor_texture_vector[2].loadFromFile("assets/receptor.png", r3))
		abort();

	if (!bg_texture.loadFromFile("assets/bg.png"))
		abort();
}

void playfield::create_sprites()
{
	// = Create receptor sprites ================================================
	// create 4 sprites in the receptor vector
	receptor_vector = std::vector<sf::Sprite>(4, sf::Sprite(active_receptor_texture));
	// create an anonymous vector to use that convenient count constructor
	// copy construct it into the class's receptor_vector

	// set position
	int offset = ARROW_SIZE * -1.5;
	for (auto &sprite : receptor_vector)
	{
		sprite.setPosition(WINDOW_X_CENTER + offset,
			OFFSET_FROM_TOP_OF_SCREEN + 32);
		offset += ARROW_SIZE;
	}

	// set origin
	for (auto &sprite : receptor_vector)
		sprite.setOrigin(ARROW_SIZE / 2, ARROW_SIZE / 2);

	// rotate
	receptor_vector[LEFT].rotate(90);
	receptor_vector[UP].rotate(180);
	receptor_vector[RIGHT].rotate(270);

	// push them into the draw_vector
	for (auto &sprite : receptor_vector)
		sprite_draw_vector.push_back(&sprite);

	// bg sprite
	bg = sf::Sprite(bg_texture);
	sprite_draw_vector.insert(sprite_draw_vector.begin(), &bg); // draw it first
}

void playfield::create_logic()
{
	// initialize four clocks for receptor shrinking
	// initialize an anonymous vector and copy it into the class
	receptor_clock_vector = std::vector<sf::Clock>(4, sf::Clock());
}

// Scales a receptor based on the time since a given
// key was last pressed. Range: 0 to .1 seconds
void playfield::scale_receptor(sf::Time t, sf::Sprite & receptor)
{
	float scale = t.asSeconds() * 2 + .8;
	receptor.setScale(scale, scale);
}

void playfield::loop_function()
{
	// = Receptor shrinking on keypress =====================================
	// for each key's clock
	for (int i = 0; i < receptor_clock_vector.size(); i++)
	{
		// getElapsedTime
		sf::Time t = receptor_clock_vector[i].getElapsedTime();

		// if it's been less than .1 seconds, scale
		if (t < sf::seconds(.1))
			scale_receptor(t, receptor_vector[i]);
	}

	// Receptor blinking effect
	sf::Time receptor_time = receptor_clock.getElapsedTime();
	if ( receptor_time >= sf::milliseconds(1000) )
	{
		// this is kinda shitty.
		// TODO: write a circular data type in an animated sprite class and just step through that at
		// each tick.
		receptor_clock.restart();

		// we have four locations. one is active, three are not.
		// swap out the active one for whatever's at the front.
		active_receptor_texture.swap(receptor_texture_vector.front()); // 0 is the drawn one.

		// rotate the vector
		// put the old one at the end of the vector
		sf::Texture temp = receptor_texture_vector.front();
		receptor_texture_vector.erase(receptor_texture_vector.begin()); // remove front, O(n)
		receptor_texture_vector.push_back(temp);

	}

}

// actually just resets the clock.
void playfield::shrink_receptor(int arrow_num)
{
	receptor_clock_vector[arrow_num].restart();
}

void playfield::input_handler(sf::Keyboard::Key key)
{
	// andrew pls make these a textfile config in $HOME or something
	if (key == sf::Keyboard::Q || key == sf::Keyboard::I)
		shrink_receptor(LEFT);
	if (key == sf::Keyboard::W || key == sf::Keyboard::D)
		shrink_receptor(DOWN);
	if (key == sf::Keyboard::O || key == sf::Keyboard::F)
		shrink_receptor(UP);
	if (key == sf::Keyboard::P || key == sf::Keyboard::H)
		shrink_receptor(RIGHT);

	// draw an arrow (dynamically) when key is pressed
	// TODO: offlaod this to a function
	if (key == sf::Keyboard::Space)
	{
		std::shared_ptr<sf::Sprite> blah ( new sf::Sprite(arrow_texture) );
		dynamic_draw_vector.push_back(blah);
	}

	// delete dynamically-drawn arrows
	if (key == sf::Keyboard::Backspace)
	{
		dynamic_draw_vector.pop_back();
	}
}
