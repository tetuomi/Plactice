#ifndef Person_hpp
#define Person_hpp
#include <iostream>

class Person {
private:
  int hp;
  int atack;
  int turn; // 1:brave 0:suneo
public:
  Person(int _hp,int _atack);
  friend void battle(Person &suneo,Person &brave);
  friend void results(Person &suneo,Person &brave);
};
  
#endif
