#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Display.hpp"

Display::Display(): rectangle() {
  rectangle.setSize(sf::Vector2f(10, 10));
}

Display::~Display() {
  
}

void Display::draw(Player& p, sf::RenderWindow& window) {
  rectangle.setFillColor(sf::Color::Green);
  std::list<std::vector<int>> l = p.get_pos();
  std::vector<int> tmp;

  for(int i = 0; i < p.get_size(); i++) {
    tmp = l.front();
    l.pop_front();
    this->rectangle.setPosition(tmp[0]*10, tmp[1]*10);
    window.draw(rectangle);
  }
}

void Display::draw(Apple& a, sf::RenderWindow& window) {
  rectangle.setFillColor(sf::Color::Red);
  std::vector<int>& tmp = a.get_pos();
  this->rectangle.setPosition(tmp[0]*10, tmp[1]*10);
  window.draw(rectangle);
}