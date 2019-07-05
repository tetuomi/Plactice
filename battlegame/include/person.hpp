#ifndef PERSON_HPP
#define PERSON_HPP

typedef struct {
  int hp;
  int mp;
  int atack;
  int damage;
  int recovery;
} status;

class Person {
private:
  status _status;
  int max_hp;
public:
  Person(int _hp,int _atack,int _mp);
  status get_status() const;
  int get_max_hp() const;
  status& set_status();
};

#endif
