#ifndef DEALER_HPP
#define DEALER_HPP
#include <vector>
#include <stone.hpp>
#include <display.hpp>

class Stone;
class Display;

class Dealer
{
private:
  std::vector<Stone> pos;
public:
  Dealer();
  void distribute(const Display& display);
  bool check(int turn) const;
  std::vector<Stone> get_pos() const;
};

#endif
