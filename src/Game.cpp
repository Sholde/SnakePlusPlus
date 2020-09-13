#include <SFML/Window.hpp>

#include "Game.hpp"

Game::Game(): window(sf::VideoMode(800, 600), "SnakePlusPlus"),
              display(),
              player() {

}

Game::~Game() {
  
}

void Game::key_controller() {
  std::vector<int> tmp(2);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::QUIT_KEY))
			this->window.close();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::TOP_KEY)) {
		tmp = std::vector<int>{0, -1};
		this->player.set_look(tmp);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BOTTOM_KEY)) {
		tmp = std::vector<int>{0, 1};
		this->player.set_look(tmp);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LEFT_KEY)) {
		tmp = std::vector<int>{-1, 0};
		this->player.set_look(tmp);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RIGHT_KEY)) {
		tmp = std::vector<int>{1, 0};
		this->player.set_look(tmp);
	}
}

void Game::start() {
  sf::Clock clock;
	sf::Time after = clock.getElapsedTime();

  while (this->window.isOpen()) {
		key_controller();
		
		sf::Time now = clock.getElapsedTime();
		if((int)now.asMilliseconds() - (int)after.asMilliseconds() > 100) {
			this->player.move();
			after = now;
		}

		if (this->player.check_collision())
			this->window.close();

    this->displayGame();
  }
}

void Game::displayGame() {
  // clear the window with black color
  this->window.clear(sf::Color::Black);

  // draw everything here...
  this->display.draw(this->player, this->window);

  // end the current frame
  this->window.display();
}