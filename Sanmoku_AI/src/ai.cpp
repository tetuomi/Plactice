#include "ai.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

#define ETA 0.1
#define GAMMA 0.9

AI::AI(std::string fn)
    : Player()
    , q_table(19683, std::vector<float>(9, 0.0)) // 19683 = 3^9
    , epsilon{0.5}
    , filename{fn}
{}

std::size_t AI::find_q_row(std::size_t before_hands) const
{
    // before_hand = 0 or 1
    
    std::size_t row_index = 0, coef = 0;
    for (std::size_t i{0};i < chosen_hands.size() - before_hands;++i)
    {
        if (i % 2 == 0)
        {
            coef = 1;
        }
        else
        {
            coef = 2;
        }
        row_index += pow(3, chosen_hands[i] - 1) * coef;
    }

    return row_index;
}

std::size_t AI::get_hand()
{
    std::size_t hand;
    if (epsilon_dist(mt) < epsilon)
    {
        while (true)
        {
            hand = dist(mt);
        
            auto result = std::find(chosen_hands.begin(), chosen_hands.end(), hand);

            if (result == chosen_hands.end())
            {
                break;
            }
        }
    }
    else
    {
        std::size_t row_index{find_q_row(0)};
        hand = *max_element(choosable_hands.begin(), choosable_hands.end());
        for (std::size_t i{0}; i < 9;++i)
        {
            if (choosable_hands[i] &&
                q_table[row_index][choosable_hands[i] - 1] > q_table[row_index][hand - 1])
            {
                hand = choosable_hands[i];
            }
        }
    }

    return hand;
}




void AI::update_q_table(bool end_flag, float reward)
{
    std::size_t before_row_index{find_q_row(1)};
    std::size_t row_index{find_q_row(0)};
    std::size_t column_index{chosen_hands.back() - 1};

    if (end_flag)
    {
        q_table[before_row_index][column_index] = q_table[before_row_index][column_index]
            + ETA * (reward - q_table[before_row_index][column_index]);
    }
    else
    {
        q_table[before_row_index][column_index] = q_table[before_row_index][column_index]
            + ETA * (reward +
                     GAMMA * (*max_element(q_table[row_index].begin(), q_table[row_index].end()))
                     - q_table[before_row_index][column_index]);
    }
}

void AI::set_epsilon(float ep)
{
    epsilon = ep;
}

void AI::init_param()
{
    for (std::size_t i{0};i < 9; ++i)
    {
        choosable_hands[i] = i + 1;
    }

    chosen_hands = std::vector<std::size_t>();

    epsilon = 0.5;
}

void AI::save_file() const
{
    std::ofstream writing_file;
    writing_file.open(filename);

    for (std::size_t row{0};row < 19683;++row)
    {
        for (std::size_t column{0};column < 9;++column)
        {
            writing_file << q_table[row][column] << ' ';
        }
        writing_file << std::endl;
    }
}

void AI::load_file()
{
    std::ifstream ifs(filename, std::ios::in);

    if (!ifs)
    {
        std::cout << "ファイルの読み込みに失敗しました\n";
    }
    else
    {
        std::cout << "ファイルの読み込みに成功しました\n";
        std::string tmp;
        std::stringstream ss;
        std::size_t row = 0;
        
        while (getline(ifs, tmp))
        {
            ss << tmp;
            ss >> q_table[row][0] >> q_table[row][1] >> q_table[row][2]
               >> q_table[row][3] >> q_table[row][4] >> q_table[row][5]
               >> q_table[row][6] >> q_table[row][7] >> q_table[row][8];
            ++row;
        }
    }
    ifs.close();
}
