#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include "game_master.hpp"

class Master;

class Person {
private:
  int hp;
  int atack;
  int damage;
public:
  Person(int _hp,int _atack);
  const int get_damage() const;
  const int get_hp() const;
  const int get_turn() const;
  friend void brave_atack(Person& suneo,Person& brave);
  friend void emperor_atack(Person& suneo,Person& brave);
};
  
#endif
