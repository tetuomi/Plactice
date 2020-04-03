#ifndef RANDOM_HPP
#define RANDOM_HPP

#include "player.hpp"

class Random : public Player
{
public:
    Random();
    std::size_t get_hand() override;
    void init_param();
};

#endif
