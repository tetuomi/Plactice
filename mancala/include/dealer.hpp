#ifndef DEALER_HPP
#define DEALER_HPP
#include <vector>
#include <stone.hpp>

class Stone;

class Dealer
{
private:
  std::vector<Stone> pos;
public:
  Dealer();
  void distribute();
  std::vector<Stone> get_pos() const;
};

#endif
