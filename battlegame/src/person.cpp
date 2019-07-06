#include "../include/person.hpp"

Person::Person(int _hp,int _atack,int _mp) {
  max_hp = _hp;
  _status.hp = _hp;
  _status.mp = _mp;
  _status.atack = _atack;
}

status Person::get_status() const {
  return _status;
}

int Person::get_max_hp() const {
  return max_hp;
}

status& Person::set_status() {
  return _status;
}
