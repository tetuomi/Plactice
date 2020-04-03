#include "random.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>


Random::Random()
    : Player()
{}

std::size_t Random::get_hand()
{    
    std::size_t hand;
    while (true)
    {
        hand = dist(mt);
        
        auto result = std::find(chosen_hands.begin(), chosen_hands.end(), hand);

        if (result == chosen_hands.end())
        {
            break;
        }
    }
    return hand;
}

void Random::init_param()
{
    chosen_hands = std::vector<std::size_t>();
}
