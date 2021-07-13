#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player &Virologist::treat(City city)
{
    if (board.dis_stat(city) == 0)
    {
        throw invalid_argument{"Theres no cubes in the city"};
    }
    if (! (bool) cards.count(city) && curr_city!=city)
    {
        throw invalid_argument{"Theres no match card"};
    }
    if (board.has_cure(Board::color(city)))
    {
        board.all_cubes(city);
        cards.erase(city);
    }
    else
    {
        board.one_cube(city);
        cards.erase(city);
    }
    return *this;
}