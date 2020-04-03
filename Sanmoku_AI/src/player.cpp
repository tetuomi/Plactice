#include "player.hpp"
#include <vector>
#include <iostream>


Player::Player()
    : chosen_hands{}
    , choosable_hands(9)
{
    for (std::size_t i{0};i < 9; ++i)
    {
        choosable_hands[i] = i + 1;
    }

}

void Player::set_chosen_hands(std::size_t hand)
{
    chosen_hands.push_back(hand);
    choosable_hands[hand - 1]  = 0;
}

void Player::show() const
{
    for (const auto& e: chosen_hands)
    {
        std::cout << e << ' ';
    }
    std::cout << std::endl;
}
