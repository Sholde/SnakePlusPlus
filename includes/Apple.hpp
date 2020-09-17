#ifndef apple_hpp
#define apple_hpp

#include <vector>
#include <random>

#include "Entity.hpp"

class Apple : public Entity {
  private:
    std::vector<int> pos;
    std::random_device rd;

  public:
    Apple();
    ~Apple();

    const std::vector<int>& get_pos();
    void find_new_pos();
    void draw(sf::RenderWindow& window);
};

#endif // !apple_hpp