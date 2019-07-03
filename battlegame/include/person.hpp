#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include "game_master.hpp"

class Master;

class Person {
private:
  int max_hp;
  int hp;
  int mp;
  int atack;
  int damage;
  int recovery;
public:
  Person(int _hp,int _atack,int _mp);
  const int get_damage() const;
  const int get_hp() const;
  const int get_mp() const;
  const int get_recovery() const;
  friend void brave_atack(Person& person,Person& brave);
  friend void emperor_atack(Person& person,Person& brave);
  void hp_recovery(Person& person);
};
  
#endif
