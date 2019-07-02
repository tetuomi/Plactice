#ifndef GAME_MASTER_HPP
#define GAME_MASTER_HPP
#include "person.hpp"

class Person;

class Master {
private:
   bool brave_turn;
public:
  Master();
  void show_selection();
  const bool get_turn() const;
  void show_damage(const Person& emperor,const Person& brave);
  void show_hp(const Person& emperor,const Person& brave);
};

#endif
