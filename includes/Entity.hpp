#ifndef entity_hpp
#define entity_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Entity {
  protected:
    sf::RectangleShape rectangle;

  public:
    Entity(sf::Color color);
    ~Entity();
    
    void draw(sf::RenderWindow& window);
};

#endif // !entity_hpp