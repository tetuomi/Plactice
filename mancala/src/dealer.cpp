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
  auto _selected{display.get_selected()
      + display.get_turn() * 2 *(CHOICES - display.get_selected())};
  const auto _pos{pos[_selected]};
  pos[_selected].kill();
  for(auto num{0}, start_indent{_selected + 1};
      num < _pos.get_number();
      num++, start_indent = (start_indent + 1) % POSITION_NUMBER)
  {
    pos[start_indent].add();
  }
}

std::vector<Stone> Dealer::get_pos() const
{
  return pos;
}
