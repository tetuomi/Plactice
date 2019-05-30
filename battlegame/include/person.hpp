#ifndef Person_hpp
#define Person_hpp
#include <iostream>

class Person {
private:
  int hp;
  int atack;
public:
  Person(int _hp,int _atack);
  friend void battle(Person &suneo,Person &brave);
};
  
#endif
