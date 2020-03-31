#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>

class Player
{
protected:
    std::vector<std::size_t> chosen_hands;

public:
    Player();
    void set_chosen_hands(std::size_t hand);
    virtual std::size_t get_hand() = 0;
};


#endif
