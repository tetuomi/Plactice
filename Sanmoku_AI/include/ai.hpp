#ifndef AI_HPP
#define AI_HPP

#include "player.hpp"

class AI : public Player
{
public:
    AI();
    std::size_t get_hand() override;
};


#endif
