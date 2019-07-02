#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>

class Person {
private:
  int hp;
  int atack;
  int damage;
  int brave_turn; // 1:brave, 0: emperor
public:
  Person(int _hp,int _atack);
  const int get_damage() const;
  const int get_hp() const;
  const int get_turn() const;
  friend void battle(Person &suneo,Person &brave);
};
  
#endif
