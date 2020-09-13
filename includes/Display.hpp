#ifndef display_hpp
#define display_hpp

#include <SFML/Window.hpp>

#include "Player.hpp"

class Display {
  private:
    sf::RectangleShape rectangle;

  public:
    Display();
    ~Display();
    
    void draw(Player& p, sf::RenderWindow& window);
};

#endif // !display_hpp