#include "../include/person.hpp"
#include <iostream>
#include <iomanip>
#include <random>
#include <ncurses.h>

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
    printw("\nbrave atack> %d damages",realAttack);
    suneo.hp -= realAttack;
  }
  else {
    realAttack = suneo.atack + mt()%suneo.atack;
    printw("\nsuneo atack> %d damages",realAttack);
    brave.hp -= realAttack;
  }
  suneo.turn ^= 1;
}

void results(Person &suneo,Person &brave) {
  printw("\n+----------------------+\n");
  printw("|suneo HP:         %3d|\n",suneo.hp);
  printw("+----------------------+\n\n");
  printw("+----------------------+\n");
  printw("|brave HP:          %3d|\n",brave.hp);
  printw("+----------------------+\n\n");
}
