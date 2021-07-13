#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player &Scientist::discover_cure(Color color)
{
    if (board.has_cure(color))
    {
        return *this;
    }

    if (board.is_research_station(curr_city))
    {
        int counter = 0;
        for (const auto &col : cards)
        {
            if (Board::color(col) == color)
            {
                counter++;
            }
            if (counter == n)
            {
                break;
            }
        }
        if (counter == n)
        {
            counter = 0;
            for (auto iter = cards.begin(); iter != cards.end() || counter < n; counter++)
            {
                if (Board::color(*iter) == color)
                {
                    iter = cards.erase(iter);
                }
                else
                {
                    ++iter;
                }
            }
            board.curing(color);
        }
        else
        {
            throw std::invalid_argument{"theres no enough cards"};
        }
    }
    else
    {

        throw std::invalid_argument{"Theres no research station in your city"};
    }
    return *this;
}