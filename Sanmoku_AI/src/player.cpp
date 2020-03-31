#include "player.hpp"
#include <vector>
#include <iostream>

Player::Player()
    : chosen_hands{}
{}

void Player::set_chosen_hands(std::size_t hand)
{
    chosen_hands.push_back(hand);
}
