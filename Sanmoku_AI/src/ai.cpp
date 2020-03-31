#include "ai.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

std::random_device rnd;
std::mt19937 mt(rnd());
std::uniform_int_distribution<int> dist(1, 9);

AI::AI()
    :Player()
{}

std::size_t AI::get_hand()
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

