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
  this->draw_head(window);

  this->draw_body(window);

  this->draw_tail(window);
}

void Player::draw_head(sf::RenderWindow& window) {
  sf::Texture headTexture;
  if(!headTexture.loadFromFile("assets/head.png")) {
    exit(-1);
  }
  sf::Sprite head(headTexture);

  head.setPosition(this->pos[0][0] * 10, this->pos[0][1] * 10);
  if (this->look.front() == -1) {
    head.setRotation(180);
    head.move(10, 10);
  }
  else if (this->look.back() == 1) {
    head.setRotation(90);
    head.move(10, 0);
  }
  else if (this->look.back() == -1) {
    head.setRotation(-90);
    head.move(0, 10);
  }

  window.draw(head);
}

void Player::draw_body(sf::RenderWindow& window) {
  sf::Texture bodyTexture;
  sf::Texture body_rightTexture;
  sf::Texture body_leftTexture;

  if(!bodyTexture.loadFromFile("assets/body.png")) {
    exit(-1);
  }
  if(!body_rightTexture.loadFromFile("assets/body_right.png")) {
    exit(-1);
  }
  if(!body_leftTexture.loadFromFile("assets/body_left.png")) {
    exit(-1);
  }

  for(int i = 1; i < this->size - 1; i++) {
    sf::Sprite body;
    body.setTexture(bodyTexture);
    body.setPosition(this->pos[i][0] * 10, this->pos[i][1] * 10);

    if (this->pos[i][1] == this->pos[i-1][1] && this->pos[i][1] == this->pos[i+1][1]) {
      if (this->pos[i][0] > this->pos[i-1][0])
      {
        body.setRotation(180);
        body.move(10, 10);
      }
    }
    else if (this->pos[i][0] == this->pos[i-1][0] && this->pos[i][0] == this->pos[i+1][0]) {
      if (this->pos[i][1] < this->pos[i-1][1]) {
        body.setRotation(90);
        body.move(10, 0);
      }
      else
      {
        body.setRotation(-90);
        body.move(0, 10);
      }
    }
    else {
      if (this->pos[i][0] < this->pos[i-1][0]
        && this->pos[i][1] == this->pos[i-1][1])
      {
        if (this->pos[i][1] > this->pos[i+1][1])
        {
          body.setTexture(body_rightTexture);
        }
        else
        {
          body.setTexture(body_leftTexture);
          body.setRotation(180);
          body.move(10, 10);
        }
      }
      else if (this->pos[i][0] == this->pos[i-1][0]
        && this->pos[i][1] < this->pos[i-1][1])
      {
        if (this->pos[i][0] > this->pos[i+1][0])
        {
          body.setTexture(body_rightTexture);
          body.setRotation(90);
          body.move(0, 10);
        }
        else
        {
          body.setTexture(body_leftTexture);
          body.setRotation(90);
          body.move(10, 0);
        }
      }
      else if (this->pos[i][0] > this->pos[i-1][0]
        && this->pos[i][1] == this->pos[i-1][1])
      {
        if (this->pos[i][1] < this->pos[i+1][1])
        {
          body.setTexture(body_rightTexture);
          body.setRotation(180);
          body.move(10, 10);
        }
        else
        {
          body.setTexture(body_leftTexture);
        }
      }
      else if (this->pos[i][0] == this->pos[i-1][0]
        && this->pos[i][1] > this->pos[i-1][1])
      {
        if (this->pos[i][0] < this->pos[i+1][0])
        {
          body.setTexture(body_rightTexture);
          body.setRotation(-90);
          body.move(10, 0);
        }
        else
        {
          body.setTexture(body_leftTexture);
          body.setRotation(-90);
          body.move(0, 10);
        }
      }
    }

    window.draw(body);
  }
}

void Player::draw_tail(sf::RenderWindow& window) {
  sf::Texture tailTexture;
  if(!tailTexture.loadFromFile("assets/tail.png")) {
    exit(-1);
  }
  sf::Sprite tail(tailTexture);

  tail.setPosition(this->pos[this->size-1][0] * 10, this->pos[this->size-1][1] * 10);
  if (this->pos[this->size-1][1] == this->pos[this->size-2][1]
    && this->pos[this->size-1][0] > this->pos[this->size-2][0]) {
    tail.setRotation(180);
    tail.move(10, 10);
  }
  else if (this->pos[this->size-1][0] == this->pos[this->size-2][0]) {
    if (this->pos[this->size-1][1] < this->pos[this->size-2][1]) {
      tail.setRotation(90);
      tail.move(10, 0);
    }
    else
    {
      tail.setRotation(-90);
      tail.move(0, 10);
    }
  }

  window.draw(tail);
}