#include "Player.hpp"

Player::Player() : Entity(sf::Color::Green) {
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

const std::vector<int>& Player::head() {
  return this->pos.front();
}

void Player::move() {
  this->save_last_pos = this->pos.back();

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

  if (x < 0 || x > 80)
    return 1;
  else if (y < 0 || y > 60)
    return 1;
  
  int i = 0;
  for(auto& elem : this->pos) {
    if(i > 0 && elem == this->head())
      return 1;
    i++;
  }
  
  return 0;
}

int& Player::get_size() {
  return this->size;
}

void Player::eat() {
  this->pos.push_back(this->save_last_pos);
  this->size++;
}

void Player::draw(sf::RenderWindow& window) {
  std::list<std::vector<int>> l = this->pos;
  std::vector<int> tmp;

  this->rectangle.setFillColor(sf::Color(0, 200, 0));
  tmp = l.front();
  l.pop_front();
  this->rectangle.setPosition(tmp[0]*10, tmp[1]*10);
  window.draw(this->rectangle);

  this->rectangle.setFillColor(sf::Color::Green);
  for(int i = 1; i < this->size; i++) {
    tmp = l.front();
    l.pop_front();
    this->rectangle.setPosition(tmp[0]*10, tmp[1]*10);
    window.draw(this->rectangle);
  }
}