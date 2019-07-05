#ifndef ACTION_HPP
#define ACTION_HPP
#include <vector>
#include "person.hpp"

class Person;

class Action {
private:
  std::vector<int> Vmax_hp;
  bool brave_turn;
  std::vector<status> Vstatus;
public:
  Action(const Person& brave,const Person& emperor);
  bool get_turn() const;
  const std::vector<status>& get_Vstatus() const ;
  void atack(Person& brave,Person& emperor);
};

#endif
