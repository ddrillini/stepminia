#pragma once // once per compilation unit
#include "base_screenstate.hpp"

class playfield : public base_screenstate
{
public:
	playfield();
	void loop_function() override;
	void shrink_receptor(int arrow_num);
	void input_handler(sf::Keyboard::Key key) override;
	// do we need to dealloc the vector in a destructor?
private:
	void load_textures() override;
	void create_sprites() override;
	void create_logic() override;

	void scale_receptor(sf::Time t, sf::Sprite & receptor);

	// = Textures =======================================================
	sf::Texture arrow_texture;

	// we should make an "animated sprite" class and offload logic into that.
	sf::Texture receptor_texture_0, receptor_texture_1, receptor_texture_2, receptor_texture_3;
	sf::Texture receptor_temp_texture;
	sf::Texture bg_texture;

	// = Sprites ========================================================

	sf::Sprite bg;
	std::vector<sf::Sprite> receptor_vector;
	std::vector<sf::Clock> receptor_clock_vector;
};

// all of these must be included once per link
playfield::playfield()
{
	// what's the difference between these two?
	// playfield::load_textures(); // member pointer: obscure feature of cpp
	this->load_textures(); // accesses the member
	// however, the this-> is optional

	create_sprites();
	create_logic();
}

void playfield::load_textures()
{
	// where should textures get stored? inside the class, one by one?
	// vector?: no, then we can't get at them by name anymore.

	if (!arrow_texture.loadFromFile("assets/arrow.png"))
		abort();

// = IntRects to chop up the arrow texture ==================================
	sf::IntRect r0(ARROW_SIZE*0, 0, ARROW_SIZE, ARROW_SIZE); // brightest
	sf::IntRect r1(ARROW_SIZE*1, 0, ARROW_SIZE, ARROW_SIZE);
	sf::IntRect r2(ARROW_SIZE*2, 0, ARROW_SIZE, ARROW_SIZE);
	sf::IntRect r3(ARROW_SIZE*3, 0, ARROW_SIZE, ARROW_SIZE);

// = Load them into textures ================================================

	if (!receptor_texture_0.loadFromFile("assets/receptor.png", r0))
		abort();

	if (!receptor_texture_1.loadFromFile("assets/receptor.png", r1))
		abort();

	if (!receptor_texture_2.loadFromFile("assets/receptor.png", r2))
		abort();

	if (!receptor_texture_3.loadFromFile("assets/receptor.png", r3))
		abort();

	receptor_temp_texture = receptor_texture_3;

	if (!bg_texture.loadFromFile("assets/bg.png"))
		abort();
}

void playfield::create_sprites()
{
// = Create receptor sprites ================================================
	// create 4 sprites in the receptor vector
	receptor_vector = std::vector<sf::Sprite> ( 4, sf::Sprite(receptor_temp_texture) );
	// create an anonymous vector to use that convenient count constructor
	// copy construct it into the class's receptor_vector

	// set position
	int offset = ARROW_SIZE * -1.5;
	for ( auto &sprite : receptor_vector )
	{
		sprite.setPosition(WINDOW_X_CENTER + offset,
			OFFSET_FROM_TOP_OF_SCREEN+32);
		offset += ARROW_SIZE;
	}

	// set origin
	for ( auto &sprite : receptor_vector )
		sprite.setOrigin( ARROW_SIZE/2, ARROW_SIZE/2 );

	// rotate
	receptor_vector[LEFT].rotate(90);
	receptor_vector[UP].rotate(180);
	receptor_vector[RIGHT].rotate(270);

	// push them into the draw_vector
	for ( auto &sprite : receptor_vector )
		this->sprite_draw_vector.push_back(&sprite);

	// bg sprite
	bg = sf::Sprite (bg_texture);
	sprite_draw_vector.insert(sprite_draw_vector.begin(), &bg);
}

void playfield::create_logic()
{
	// initialize four clocks for receptor shrinking
	// initialize an anonymous vector and copy it into the class
	receptor_clock_vector = std::vector<sf::Clock> ( 4, sf::Clock() );
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
	for (int i=0; i < receptor_clock_vector.size(); i++)
	{
		// getElapsedTime
		sf::Time t = receptor_clock_vector[i].getElapsedTime();

		// if it's been less than .1 seconds, scale
		if ( t < sf::seconds(.1) )
			scale_receptor(t, receptor_vector[i]);
	}
}

// actually just resets the clock.
void playfield::shrink_receptor(int arrow_num)
{
	receptor_clock_vector[arrow_num].restart();
}

void playfield::input_handler(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::I)
		shrink_receptor(LEFT);
	if (key == sf::Keyboard::D)
		shrink_receptor(DOWN);

	if (key == sf::Keyboard::F)
		shrink_receptor(UP);

	if (key == sf::Keyboard::H)
		shrink_receptor(RIGHT);

}
