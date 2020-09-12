#include <SFML/Graphics.hpp>
#include <iostream>

#include "Display.hpp"

Display::Display() {

}

Display::~Display() {
  
}

void Display::draw(Player& p, sf::RenderWindow& window) {
  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(10, 10));
  rectangle.setOutlineColor(sf::Color::Green);
  rectangle.setOutlineThickness(5);
  rectangle.setPosition(0, 0);
  
  for(std::vector<int>& elem : p.get_pos()) {
    rectangle.setPosition(elem.front()*10, elem.back()*10);
    window.draw(rectangle);
  }
}