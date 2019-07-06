#include "../include/person.hpp"
#include "../include/action.hpp"
#include <vector>

Action::Action(const Person& brave,const Person& emperor) {
  Vstatus.push_back(emperor.get_status());
  Vstatus.push_back(brave.get_status());
}

const std::vector<status>& Action::get_Vstatus() const {
  return Vstatus;
}

void Action::atack(Person& brave,Person& emperor,const Master& master) {
  if(master.get_turn()) {
    brave.pre_atack(emperor);

    Vstatus[1].damage = brave.get_status().damage;
    Vstatus[0].hp -= Vstatus[1].damage;
  }
  else {
    emperor.pre_atack(brave);

    Vstatus[0].damage = emperor.get_status().damage;
    Vstatus[1].hp -= Vstatus[0].damage;
  }
}

void Action::hp_recovery(Person& person,const Master& master) {
  const auto who{master.get_turn()};
  person.pre_hp_recovery();
  
  Vstatus[who].mp = person.get_status().mp;
  Vstatus[who].recovery = person.get_status().recovery;
  Vstatus[who].hp = person.get_status().hp;
}
