#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

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

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("sizeable_image.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

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

/*
	// create arrow
	// create an array of 3 vertices that define a triangle primitive
	sf::VertexArray arrow(sf::arrows, 3);

	// define the position of the arrow's points
	arrow[0].position = sf::Vector2f(10, 10);
	arrow[1].position = sf::Vector2f(100, 10);
	arrow[2].position = sf::Vector2f(100, 100);

	// define the color of the arrow's points
	arrow[0].color = sf::Color::Red;
	arrow[1].color = sf::Color::Blue;
	arrow[2].color = sf::Color::Green;

	// texture coordinates here, we'll see that later
*/

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
					sprite.move(sf::Vector2f(5, 10));
			}
				
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }

	return EXIT_SUCCESS;
}
