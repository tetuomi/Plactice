#include <stone.hpp>


Stone::Stone(int _number)
{
  number = _number;
}

int Stone::get_number() const
{
  return number;
}

void Stone::add()
{
  number++;
}

void Stone::kill()
{
  number = 0;
}
