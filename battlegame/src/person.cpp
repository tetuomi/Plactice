#include "../include/person.hpp"
#include <iostream>

Person::Person(int _hp,int _atack){
  hp = _hp;
  atack = _atack;
}

void battle(Person &suneo,Person &brave){
  std::cout << "勇者の攻撃　＞ " << brave.atack << " のダメージ\n";
  std::cout << "スネ夫のHP :" << suneo.hp - brave.atack << "\n";
  suneo.hp -= brave.atack;
}
