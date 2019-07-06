#ifndef PERSON_HPP
#define PERSON_HPP
#define MP 10
#define RECOVERY 12

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
  void pre_hp_recovery();
  void pre_atack(Person& other);
};

#endif
