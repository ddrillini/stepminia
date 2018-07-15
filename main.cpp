#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#define ARROW_SIZE 64
#define LEFT_ARROW 0
#define DOWN_ARROW 1
#define UP_ARROW 2
#define RIGHT_ARROW 3

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	// To draw stuff, you can also use OpenGL directly and totally ignore
	// the sfml-graphics module. sf::Window internally creates an OpenGL
	// context and is ready to accept your OpenGL calls.
	sf::RenderWindow window(sf::VideoMode(640, 480), "stepminia",
		sf::Style::None, settings);

	// we may want to offload the window drawing to a thread.
	// see: https://www.sfml-dev.org/tutorials/2.5/graphics-draw.php,
	// bottom of page.

// = Drawing arrows =========================================================

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("arrow.png"))
        return EXIT_FAILURE;

	// we'll probably turn these into receptors eventually
	sf::Sprite left(texture);
    sf::Sprite down(texture);
    sf::Sprite up(texture);
	sf::Sprite right(texture);

	// copied in
	std::vector<sf::Sprite> arrow_vector = {left, down, up, right};

	// from transformable.
	// up.setRotation(150); // rotates around the origin, which is the
	// top-left pixel. there's also rotate, which just
	// adds to the current rotation.
	// for now, gonna skip rotations because i'd rather figure out how to
	// have arrows happen.

// = Drawing arrows End======================================================

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("owo what's this?", font, 50);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("nice_music.ogg"))
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
				if (event.key.code == sf::Keyboard::E)
					down.move(sf::Vector2f(0, 10));
			}
				
        }
        // Clear screen
        window.clear();

        // Draw the sprites 
		int i = 0;
		for ( auto &sprite : arrow_vector )
		{
			sprite.setPosition( ARROW_SIZE*i, 0 );
			window.draw(sprite);
			i++;
		}

        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }

	return EXIT_SUCCESS;
}
