#include "../include/person.hpp"
#include "../include/action.hpp"
#include <vector>
#include <random>

std::random_device rnd;
std::mt19937 mt(rnd());


Action::Action(const Person& brave,const Person& emperor) {
  Vstatus.push_back(emperor.get_status());
  Vmax_hp.push_back(emperor.get_max_hp());
  
  Vstatus.push_back(brave.get_status());
  Vmax_hp.push_back(brave.get_max_hp());
}

const std::vector<status>& Action::get_Vstatus() const {
  return Vstatus;
}

void Action::atack(Person& brave,Person& emperor,const Master& master) {
  if(master.get_turn()) {
    brave.set_status().damage = brave.set_status().atack
      + mt()%brave.set_status().atack;
    emperor.set_status().hp -= brave.set_status().damage;

    Vstatus[1].damage = brave.get_status().damage;
    Vstatus[0].hp -= Vstatus[1].damage;
  }
  else {
    emperor.set_status().damage = emperor.set_status().atack
      + mt()%emperor.set_status().atack;
    brave.set_status().hp -= emperor.set_status().damage;

    Vstatus[0].damage = emperor.get_status().damage;
    Vstatus[1].hp -= Vstatus[0].damage;
  }
}

void Action::hp_recovery(Person& person,const Master& master) {
  const auto who{master.get_turn()};
  person.set_status().mp -= MP;
  person.set_status().recovery = RECOVERY + mt()%RECOVERY;
  person.set_status().hp += person.get_status().recovery;
  
  Vstatus[who].mp = person.get_status().mp;
  Vstatus[who].recovery = person.get_status().recovery;
  Vstatus[who].hp = person.get_status().hp;
}
