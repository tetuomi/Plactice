#include "person.hpp"
#include <algorithm>

Person::Person()
    : Player()
{}

std::size_t Person::get_hand()
{
    std::size_t hand;
    
    while (true)
    {
        std::cout << "1 ~ 9を入力してくだし\nー＞";
        std::cin >> hand;

        auto result = std::find(chosen_hands.begin(), chosen_hands.end(), hand);

        if (result == chosen_hands.end())
        {
            break;
        }
    }
    return hand;
}
