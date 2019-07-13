#include <dealer.hpp>
#include <stone.hpp>
#include <display.hpp>


Dealer::Dealer()
{
  pos.push_back(Stone{0});
  pos.push_back(Stone{1});
  pos.push_back(Stone{2});
  pos.push_back(Stone{3});
  pos.push_back(Stone{4});
  pos.push_back(Stone{5});
  pos.push_back(Stone{6});
  pos.push_back(Stone{7});
}

void Dealer::distribute(const Display& display)
{
  
}

std::vector<Stone> Dealer::get_pos() const
{
  return pos;
}
