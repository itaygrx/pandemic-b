#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;
const int num = 5;

Player &GeneSplicer::discover_cure(Color color)
{
    if (!board.is_research_station(curr_city))
    {
        throw std::invalid_argument{"Theres no research station in your city"};
    }
    if (cards.size() >= num)
    {
        int counter = 0;
        for (auto iter = cards.begin(); iter != cards.end() || counter < num; counter++)
        {
            iter = cards.erase(iter);
        }
        board.curing(color);
    }
    else
    {
        throw std::invalid_argument{"theres no enough cards"};
    }
    return *this;
}