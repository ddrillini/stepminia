#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#define ARROW_SIZE 64
#define LEFT 0
#define DOWN 1
#define UP 2
#define RIGHT 3

#define WINDOW_HEIGHT 480
#define WINDOW_WIDTH 640
#define WINDOW_Y_CENTER WINDOW_HEIGHT/2
#define WINDOW_X_CENTER WINDOW_WIDTH/2

int main()
{

	std::cout << "Note that stepminia must currently be run from the\
executable's directory, because it expects the assets folder to be in the\
current working directory." << std::endl;

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

// trying a way of organizing code that i haven't before.
// can you tell i write a lot of c?
#include "receptors.cpp"

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("owo what's this?", font, 50);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("assets/nice_music.ogg"))
        return EXIT_FAILURE;

    // Play the music
    music.play();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
			
			// for now just register stuff?
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();

				if (event.key.code == sf::Keyboard::I)
					arrow_vector[LEFT].move(sf::Vector2f(0, 10));

				if (event.key.code == sf::Keyboard::D)
					arrow_vector[DOWN].move(sf::Vector2f(0, 10));

				if (event.key.code == sf::Keyboard::F)
					arrow_vector[UP].move(sf::Vector2f(0, 10));

				if (event.key.code == sf::Keyboard::H)
					arrow_vector[RIGHT].move(sf::Vector2f(0, 10));
			}
				
        }
        // Clear screen
        window.clear();

        // Draw the sprites 
		int i = 0;
		for ( auto &sprite : arrow_vector )
		{
			window.draw(sprite);
		}

        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }

	return EXIT_SUCCESS;
}
