#ifndef apple_hpp
#define apple_hpp

#include <vector>
#include <random>

class Apple {
  private:
    std::vector<int> pos;
    std::random_device rd;

  public:
    Apple();
    ~Apple();

    std::vector<int>& get_pos();
    void find_new_pos();
};

#endif // !apple_hpp