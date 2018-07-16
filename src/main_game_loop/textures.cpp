// included from main.cpp

sf::Texture receptor_bright_texture;
if (!receptor_bright_texture.loadFromFile("assets/receptor_bright.png"))
	return EXIT_FAILURE;

sf::Texture receptor_dark_texture;
if (!receptor_dark_texture.loadFromFile("assets/receptor_dark.png"))
	return EXIT_FAILURE;

sf::Texture arrow_texture;
if (!arrow_texture.loadFromFile("assets/arrow.png"))
	return EXIT_FAILURE;
