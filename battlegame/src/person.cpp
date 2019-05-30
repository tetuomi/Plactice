#include "../include/person.hpp"
#include <iostream>
#include <iomanip>

Person::Person(int _hp,int _atack) {
  hp = _hp;
  atack = _atack;
  turn = 1;
}

void battle(Person &suneo,Person &brave) {
  if(suneo.turn){
    std::cout << "勇者の攻撃> " << brave.atack << " のダメージ\n";             
    suneo.hp -= brave.atack;
  }
  else {
    std::cout << "スネ夫の攻撃> " << suneo.atack << " のダメージ\n";
    brave.hp -= suneo.atack ;
  }
  suneo.turn ^= 1;
}

void results(Person &suneo,Person &brave) {
  std::cout << "+----------------------+\n"
            << "|スネ夫のHP:        "
            << std::setw(3)
            << suneo.hp << "|\n"
            << "+----------------------+\n\n";
  std::cout << "+----------------------+\n"
            << "|勇者のHP:          "
            << std::setw(3)
            << brave.hp << "|\n"
            << "+----------------------+\n";
}
