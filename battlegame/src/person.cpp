#include "../include/person.hpp"
#include <random>

std::random_device rnd;
std::mt19937 mt(rnd());

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

void Person::pre_hp_recovery() {
  _status.mp -= MP;
  _status.recovery = RECOVERY + mt()%RECOVERY;
  _status.hp += _status.recovery;

  if(_status.hp >= max_hp) {
    _status.recovery -= (_status.hp - max_hp);
    _status.hp = max_hp;
  }
}

void Person::pre_atack(Person& other) {
  _status.damage = _status.atack + mt()%_status.atack;
  other.set_status().hp -= _status.damage;
}
