#ifndef player_hpp
#define player_hpp

#include <list>
#include <vector>

class Player {
  private:
    int size;
    std::list<std::vector<int>> pos;
    std::vector<int> look;
    std::vector<int> save_last_pos;

  public:
    Player();
    ~Player();
    std::vector<int> head();
    void move();
    void set_look(std::vector<int>& tmp);
    int check_collision();
    std::list<std::vector<int>> get_pos();
    int& get_size();
};

#endif // !player_hpp