#include <dealer.hpp>
#include <stone.hpp>


Dealer::Dealer()
{
  pos.push_back(Stone{3});
  pos.push_back(Stone{3});
  pos.push_back(Stone{3});
  pos.push_back(Stone{0});
  pos.push_back(Stone{3});
  pos.push_back(Stone{3});
  pos.push_back(Stone{3});
  pos.push_back(Stone{0});
}

void Dealer::distribute()
{
  
}

vector<Stone> Dealer::get_pos() const
{
  return pos;
}
