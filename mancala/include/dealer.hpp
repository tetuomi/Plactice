#ifndef DEALER_HPP
#define DEALER_HPP
#include <vector>
#include <stone.hpp>

class Stone;

class Dealer
{
private:
  vector<Stone> pos;
public:
  Dealer();
  void distribute();
  vector<Stone> get_pos() const;
};

#endif
