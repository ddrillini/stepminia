// included from main.cpp

sf::IntRect r0(ARROW_SIZE*0, 0, ARROW_SIZE, ARROW_SIZE); // brightest
sf::IntRect r1(ARROW_SIZE*1, 0, ARROW_SIZE, ARROW_SIZE);
sf::IntRect r2(ARROW_SIZE*2, 0, ARROW_SIZE, ARROW_SIZE);
sf::IntRect r3(ARROW_SIZE*3, 0, ARROW_SIZE, ARROW_SIZE);

sf::Texture receptor_texture_0;
if (!receptor_texture_0.loadFromFile("assets/receptor.png", r0))
	return EXIT_FAILURE;

sf::Texture receptor_texture_1;
if (!receptor_texture_1.loadFromFile("assets/receptor.png", r1))
	return EXIT_FAILURE;

sf::Texture receptor_texture_2;
if (!receptor_texture_2.loadFromFile("assets/receptor.png", r2))
	return EXIT_FAILURE;

sf::Texture receptor_texture_3;
if (!receptor_texture_3.loadFromFile("assets/receptor.png", r3))
	return EXIT_FAILURE;

// load the texture file
// copy it so i have four
// alter what they point at within the entire file

sf::Texture arrow_texture;
if (!arrow_texture.loadFromFile("assets/arrow.png"))
	return EXIT_FAILURE;
