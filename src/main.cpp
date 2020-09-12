#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define RESTART_KEY R

int main(int argc, char* argv[]) {

  sf::RenderWindow  window(sf::VideoMode(800, 600), "SnakePlusPlus");

  while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::RESTART_KEY))
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);

		// end the current frame
		window.display();
  }
	return 0;
}