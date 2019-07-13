#ifndef STONE_HPP
#define STONE_HPP


class Stone
{
private:
  int number;
public:
  Stone(int _number);
  int get_number() const;
  void add();
  void kill();
};

#endif
