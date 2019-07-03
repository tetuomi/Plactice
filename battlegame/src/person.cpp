#include "../include/person.hpp"
#include <iostream>
#include <iomanip>
#include <random>
#define MP 10
#define RECOVERY 12

Person::Person(int _hp,int _atack,int _mp) {
  max_hp = _hp;
  hp = _hp;
  mp = _mp;
  atack = _atack;
}

const int Person::get_damage() const {
  return damage;
}

const int Person::get_hp() const {
  return hp;
}

const int Person::get_mp() const {
  return mp;
}

const int Person::get_recovery() const {
  return recovery;
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

void Person::hp_recovery(Person& person) {
  person.mp -= MP;
  recovery = RECOVERY + (mt() % RECOVERY);
  person.hp += recovery;

  if(person.hp >= person.max_hp){
    recovery -= (person.hp - person.max_hp);
    person.hp = person.max_hp;
  }
}
