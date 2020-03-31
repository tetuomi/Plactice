#ifndef PERSON_HPP
#define PERSON_HPP

#include "player.hpp"
#include <iostream>

class Person : public Player
{
public:
    Person();
    std::size_t get_hand() override;
};


#endif
