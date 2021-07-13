#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player &Dispatcher::fly_direct(City city)
{
    if (curr_city == city)
    {
        throw std::invalid_argument{"Its the same city"};
    }
    if (board.is_research_station(curr_city))
    {
        curr_city = city;
    }
    else if ((bool) cards.count(city))
    {
        cards.erase(city);
        curr_city = city;
    }
    else
    {
        throw invalid_argument{"Theres no match card or research station"};
    }
    return *this;
}