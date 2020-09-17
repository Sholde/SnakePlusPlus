#include "Apple.hpp"

Apple::Apple() :  Entity(sf::Color::Red),
                  pos(2),
                  rd() {
  this->find_new_pos();
}

Apple::~Apple() {

}

const std::vector<int>& Apple::get_pos() {
  return this->pos;
}

void Apple::find_new_pos() {
  this->pos.front() = this->rd() % 78 + 1;
  this->pos.back() = this->rd() % 58 + 1;
}

void Apple::draw(sf::RenderWindow& window) {
  this->rectangle.setPosition(this->pos[0] * 10, this->pos[1] * 10);
  window.draw(this->rectangle);
}