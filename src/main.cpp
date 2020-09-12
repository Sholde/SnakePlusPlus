#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

#include "Display.hpp"
#include "Player.hpp"

#define RESTART_KEY R
#define QUIT_KEY A
#define TOP_KEY Z
#define BOTTOM_KEY S
#define LEFT_KEY Q
#define RIGHT_KEY D

void key_controller(Player& p) {
	std::vector<int> tmp(2);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::TOP_KEY)) {
		tmp = std::vector<int>(0, -1);
		p.set_look(tmp);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BOTTOM_KEY)) {
		tmp = std::vector<int>(0, 1);
		p.set_look(tmp);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LEFT_KEY)) {
		tmp = std::vector<int>(-1, 0);
		p.set_look(tmp);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RIGHT_KEY)) {
		tmp = std::vector<int>(1, 0);
		p.set_look(tmp);
	}
}

int main(int argc, char* argv[]) {

  sf::RenderWindow window(sf::VideoMode(800, 600), "SnakePlusPlus");

	Player p;
	Display d;

	sf::Clock clock;
	sf::Time after = clock.getElapsedTime();

  while (window.isOpen()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::QUIT_KEY))
			window.close();
		
		key_controller(p);
		
		sf::Time now = clock.getElapsedTime();
		if((int)now.asMilliseconds() - (int)after.asMilliseconds() > 500) {
			p.move();
			after = now;
		}

		if (p.check_collision())
			window.close();

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		d.draw(p, window);

		// end the current frame
		window.display();
  }
	return 0;
}