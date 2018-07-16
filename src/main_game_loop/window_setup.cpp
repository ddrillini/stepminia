// included by main.cpp

sf::ContextSettings settings;
settings.antialiasingLevel = 8;

// To draw stuff, you can also use OpenGL directly and totally ignore
// the sfml-graphics module. sf::Window internally creates an OpenGL
// context and is ready to accept your OpenGL calls.
sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
"stepminia", sf::Style::None, settings);

// we may want to offload the window drawing to a thread.
// see: https://www.sfml-dev.org/tutorials/2.5/graphics-draw.php,
// bottom of page.

