// included by main.cpp

// OpenGL settings. Aliasing, bit depth, etc.
sf::ContextSettings context_settings;
context_settings.antialiasingLevel = 8;

// To draw stuff, you can also use OpenGL directly and totally ignore
// the sfml-graphics module. sf::Window internally creates an OpenGL
// context and is ready to accept your OpenGL calls.
sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
"stepminia", sf::Style::None, context_settings);

window.setKeyRepeatEnabled(false);
window.setFramerateLimit(60);

// sf::Style::Fullscreen on mac prints "The requested video mode is not
// available, switching to a valid mode" and then goes fullscreen, but
// doesn't scale up to my resolution.

// we may want to offload the window drawing to a thread.
// see: https://www.sfml-dev.org/tutorials/2.5/graphics-draw.php,
// bottom of page.

