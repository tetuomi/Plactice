#include "../include/person.hpp"
#include <iostream>
#include <iomanip>
#include <random>

Person::Person(int _hp,int _atack) {
  hp = _hp;
  atack = _atack;
}

const int Person::get_damage() const{
  return damage;
}

const int Person::get_hp() const{
  return hp;
}

std::random_device rnd;
std::mt19937 mt(rnd());
  
void brave_atack(Person& emperor,Person& brave) {
    brave.damage = brave.atack + mt()%brave.atack;
    emperor.hp -= brave.damage;
}

void emperor_atack(Person& emperor,Person& brave) {
    emperor.damage = emperor.atack + mt()%emperor.atack;
    brave.hp -= emperor.damage;
}
