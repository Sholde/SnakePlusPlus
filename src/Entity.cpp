#include "Entity.hpp"

Entity::Entity(sf::Color color): rectangle() {
  rectangle.setSize(sf::Vector2f(10, 10));
  rectangle.setFillColor(color);
}

Entity::~Entity() {
  
}