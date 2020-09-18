#ifndef player_hpp
#define player_hpp

#include <deque>
#include <vector>

#include "Entity.hpp"

class Player : public Entity {
  private:
    int size;
    std::deque<std::vector<int>> pos;
    std::vector<int> look;
    std::vector<int> save_last_pos;

  public:
    Player();
    ~Player();
    
    const std::vector<int>& head();
    void move();
    void set_look(std::vector<int>& tmp);
    int check_collision();
    int& get_size();
    void eat();
    void draw(sf::RenderWindow& window);
    void draw_head(sf::RenderWindow& window);
    void draw_body(sf::RenderWindow& window);
    void draw_tail(sf::RenderWindow& window);
};

#endif // !player_hpp