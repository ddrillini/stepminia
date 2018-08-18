#pragma once // once per compilation unit

#include "base_screenstate.hpp"
#include "constants.hpp"
#include "../utils/notedata.hpp"

class playfield : public base_screenstate
{
public:
	playfield();
	void loop_function() override;
	void shrink_receptor(int arrow_num);
	void input_handler(sf::Keyboard::Key key) override;

	notedata active_simfile;

private:
	void load_textures() override;
	void create_sprites() override;
	void create_logic() override;

	void scale_receptor(sf::Time t, sf::Sprite & receptor);
	void draw_arrow();
	void draw_measure(note & note_inst);

	// = Textures =======================================================
	sf::Texture arrow_texture;

	// we should make an "animated sprite" class and offload logic into that.
	sf::Texture active_receptor_texture;
	sf::Texture bg_texture;

	// = Sprites ========================================================
	sf::Sprite bg;
	std::vector<sf::Sprite> receptor_vector;
	std::vector<sf::Clock> receptor_clock_vector;

	// = Other ==========================================================
	sf::Clock receptor_clock;
	std::vector<sf::Texture> receptor_texture_vector;

};
