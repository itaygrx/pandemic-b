#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

Player &FieldDoctor::treat(pandemic::City city)
{
    if ((board.dis_stat(city) == 0) || (!Board::is_connected(curr_city, city) && curr_city!=city) )
    {
        throw invalid_argument{"Theres no cubes in the city"};
    }
    if (board.has_cure(Board::color(city)))
    {
        board.all_cubes(city);
    }
    else
    {
        board.one_cube(city);
    }
    return *this;
}