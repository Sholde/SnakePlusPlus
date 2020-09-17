#include <SFML/Window.hpp>
#include <iostream>

#include "Game.hpp"

Game::Game(): window(sf::VideoMode(800, 600), "SnakePlusPlus"),
              player(),
							apple() {

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
			this->update();

			this->render();
			after = now;
		}
  }
}

void Game::end() {
	std::cout << "Score : " << this->player.get_size() - 3 << std::endl;
}

void Game::update() {
	this->player.move();

	if (this->player.head() == this->apple.get_pos()) {
		this->player.eat();
		this->apple.find_new_pos();
	}
	if (this->player.check_collision())
		this->window.close();
}

void Game::render() {
  // clear the window with black color
  this->window.clear(sf::Color::Black);

  // draw everything here...
  this->player.draw(this->window);
	this->apple.draw(this->window);

  // end the current frame
  this->window.display();
}