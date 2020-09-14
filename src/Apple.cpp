#include "Apple.hpp"

Apple::Apple() :  pos(2),
                  rd() {
  this->find_new_pos();
}

Apple::~Apple() {

}

std::vector<int>& Apple::get_pos() {
  return this->pos;
}

void Apple::find_new_pos() {
  this->pos.front() = this->rd() % 78 + 1;
  this->pos.back() = this->rd() % 58 + 1;
}