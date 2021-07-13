#include "Medic.hpp"
#include "Board.hpp"

using namespace std;
using namespace pandemic;

Player &Medic::treat(City city)
{
    if (board.dis_stat(city) == 0)
    {
        throw invalid_argument{"Theres no cubes in the city"};
    }
    if (city != curr_city)
    {
        throw invalid_argument{"The player isn't at the same city"};
    }
    board.all_cubes(city);
    return *this;
}

Player &Medic::drive(pandemic::City city)
{
    if (curr_city == city)
    {
        throw std::invalid_argument{"Its the same city"};
    }
    if (Board::is_connected(curr_city, city))
    {
        curr_city = city;
        if (board.has_cure(Board::color(city)))
        {
            board.all_cubes(city);
        }
    }
    else
    {
        throw invalid_argument{"Theres no connection between the cities"};
    }
    return *this;
}

Player &Medic::fly_direct(pandemic::City city)
{
    if (curr_city == city)
    {
        throw std::invalid_argument{"Its the same city"};
    }
    if ((bool)cards.count(city))
    {
        cards.erase(city);
        curr_city = city;
        if (board.has_cure(Board::color(city)))
        {
            board.all_cubes(city);
        }
    }
    else
    {
        throw invalid_argument{"Theres no match card"};
    }
    return *this;
}

Player &Medic::fly_charter(pandemic::City city)
{
    if (curr_city == city)
    {
        throw std::invalid_argument{"Its the same city"};
    }
    if ((bool)cards.count(curr_city))
    {
        cards.erase(curr_city);
        curr_city = city;
        if (board.has_cure(Board::color(city)))
        {
            board.all_cubes(city);
        }
    }
    else
    {
        throw invalid_argument{"Theres no match card"};
    }
    return *this;
}

Player &Medic::fly_shuttle(pandemic::City city)
{
    if (curr_city == city)
    {
        throw std::invalid_argument{"Its the same city"};
    }
    if (board.is_research_station(city) && board.is_research_station(curr_city))
    {
        curr_city = city;
        if (board.has_cure(Board::color(city)))
        {
            board.all_cubes(city);
        }
    }
    else
    {
        throw invalid_argument{"Theres no research stations in both cities"};
    }
    return *this;
}