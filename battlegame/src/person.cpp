#include <person.hpp>
#include <random>


std::random_device rnd;
std::mt19937 mt(rnd());

Person::Person(int _hp,int _atack,int _mp) {
  max_hp = _hp;
  _status.hp = _hp;
  _status.mp = _mp;
  _status.atack = _atack;
  _status.mp_lack = false;
}

status Person::get_status() const {
  return _status;
}

status& Person::set_status() {
  return _status;
}

void Person::pre_hp_recovery() {
  if(_status.mp - MP >= 0) {
    _status.mp -= MP;
    _status.recovery = RECOVERY + mt()%RECOVERY;
    _status.hp += _status.recovery;

    if(_status.hp >= max_hp) {
      _status.recovery -= (_status.hp - max_hp);
      _status.hp = max_hp;
    }
  }
  else
    _status.mp_lack = true;
}

void Person::pre_atack(Person& other) {
  _status.damage = _status.atack + mt()%_status.atack;
  other.set_status().hp -= _status.damage;
}
