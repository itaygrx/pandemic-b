#include "Researcher.hpp"

using namespace std;
using namespace pandemic;
const int num = 5;

Player &Researcher::discover_cure(Color color)
{
    if (board.has_cure(color))
    {
        return *this;
    }
    int counter = 0;
    for (const auto &col : cards)
    {
        if (Board::color(col) == color)
        {
            counter++;
        }
        if (counter == num)
        {
            break;
        }
    }
    if (counter == num)
    {
        counter = 0;
        for (auto iter = cards.begin(); iter != cards.end() || counter < num; counter++)
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
    return *this;
}
