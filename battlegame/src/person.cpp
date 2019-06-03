#include "../include/person.hpp"
#include <iostream>
#include <iomanip>
#include <random>
Person::Person(int _hp,int _atack) {
  hp = _hp;
  atack = _atack;
  turn = 1;
}

std::random_device rnd;
std::mt19937 mt(rnd());
  
void battle(Person &suneo,Person &brave) {
  static int realAttack; 
  if(suneo.turn){
    realAttack = brave.atack + mt()%brave.atack;
    std::cout << "勇者の攻撃> " << realAttack << " のダメージ\n";             
    suneo.hp -= realAttack;
  }
  else {
    realAttack = suneo.atack + mt()%suneo.atack;
    std::cout << "スネ夫の攻撃> " << realAttack << " のダメージ\n";
    brave.hp -= realAttack;
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
