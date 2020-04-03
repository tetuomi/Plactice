#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <random>


static std::random_device rnd;
static std::mt19937 mt(rnd());
static std::uniform_int_distribution<int> dist(1, 9);
static std::uniform_real_distribution<float> epsilon_dist(0, 1.0);

class Player
{
protected:
    std::vector<std::size_t> chosen_hands;
    std::vector<std::size_t> choosable_hands;

public:
    Player();
    void set_chosen_hands(std::size_t hand);
    virtual std::size_t get_hand() = 0;
    void show() const;
};


#endif
