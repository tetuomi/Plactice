#ifndef GAME_MASTER_HPP
#define GAME_MASTER_HPP

class Person;

class Master {
private:
public:
  void show_damage(const Person& emperor,const Person& brave);
  void show_hp(const Person& emperor,const Person& brave);
};

#endif
