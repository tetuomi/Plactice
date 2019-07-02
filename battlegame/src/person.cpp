#include "../include/person.hpp"
#include <iostream>
#include <iomanip>
#include <random>

Person::Person(int _hp,int _atack) {
  hp = _hp;
  atack = _atack;
  brave_turn = 1;
}

const int Person::get_damage() const{
  return damage;
}

const int Person::get_hp() const{
  return hp;
}

const int Person::get_turn() const{
  return brave_turn;
}

std::random_device rnd;
std::mt19937 mt(rnd());
  
void battle(Person& emperor,Person& brave) {
  if(brave.brave_turn){
    brave.damage = brave.atack + mt()%brave.atack;
    emperor.hp -= brave.damage;
  }
  else {
    emperor.damage = emperor.atack + mt()%emperor.atack;
    brave.hp -= emperor.damage;
  }
  brave.brave_turn ^= 1;
}
