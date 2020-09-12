#include "Player.hpp"

Player::Player() {
  this->size = 3;

  this->pos.push_back(std::vector<int>(2, 0));
  this->pos.push_back(std::vector<int>(1, 0));
  this->pos.push_back(std::vector<int>(0, 0));

  this->look.push_back(0);
  this->look.push_back(1);

  this->save_last_pos = this->pos.back();
}

Player::~Player() {
  
}

std::vector<int> Player::head() {
  return this->pos.front();
}

void Player::move() {
  if (this->look.front() == 1) {
    this->pos.pop_back();
    std::vector<int> tmp = this->pos.front();
    tmp[0]++;
    this->pos.push_front(tmp);
  }
  else if (this->look.front() == -1)
  {
    this->pos.pop_back();
    std::vector<int> tmp = this->pos.front();
    tmp[0]--;
    this->pos.push_front(tmp);
  }
  else if (this->look.back() == 1) {
    this->pos.pop_back();
    std::vector<int> tmp = this->pos.front();
    tmp[1]++;
    this->pos.push_front(tmp);
  }
  else if (this->look.back() == -1)
  {
    this->pos.pop_back();
    std::vector<int> tmp = this->pos.front();
    tmp[1]--;
    this->pos.push_front(tmp);
  }
  this->save_last_pos = this->pos.back();
}

void Player::set_look(std::vector<int>& tmp) {
  this->look = tmp;
}

int Player::check_collision() {
  int x = this->head().front();
  int y = this->head().back();

  //std::cout << x << y << std::endl;

  if (x < 0 || x > 8)
    return 1;
  else if (y < 0 || y > 6)
    return 1;
  
  int i = 0;
  for(auto& elem : this->pos) {
    if(i > 0 && elem == this->head())
      return 1;
    i++;
  }
  
  return 0;
}

std::list<std::vector<int>> Player::get_pos() {
  return this->pos;
}