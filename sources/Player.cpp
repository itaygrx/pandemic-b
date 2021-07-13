#include "Player.hpp"
using namespace std;
const int num = 5;

namespace pandemic
{
    Player &Player::drive(pandemic::City city)
    {
        if (curr_city == city)
        {
            throw std::invalid_argument{"Its the same city"};
        }
        if (Board::is_connected(curr_city, city))
        {
            curr_city = city;
        }
        else
        {
            throw invalid_argument{"Theres no connection between the cities"};
        }
        return *this;
    }

    Player &Player::fly_direct(pandemic::City city)
    {
        if (curr_city == city)
        {
            throw std::invalid_argument("Its the same city\n");
        }
        if ((bool)cards.count(city))
        {
            cards.erase(city);
            curr_city = city;
        }
        else
        {
            throw invalid_argument{"Theres no match card"};
        }
        return *this;
    }

    Player &Player::fly_charter(pandemic::City city)
    {
        if (curr_city == city)
        {
            throw std::invalid_argument{"Its the same city"};
        }
        if ((bool)cards.count(curr_city))
        {
            cards.erase(curr_city);
            curr_city = city;
        }
        else
        {
            throw invalid_argument{"Theres no match card"};
        }
        return *this;
    }

    Player &Player::fly_shuttle(pandemic::City city)
    {
        if (curr_city == city)
        {
            throw std::invalid_argument{"Its the same city"};
        }
        if (!board.is_research_station(curr_city) || !board.is_research_station(city))
        {
            throw invalid_argument{"Theres no research stations in both cities"};
        }
        curr_city = city;
        return *this;
    }

    Player &Player::build()
    {
        if (board.is_research_station(curr_city))
        {
            return *this;
        }
        if ((bool)cards.count(curr_city))
        {
            cards.erase(curr_city);
            board.build(curr_city);
        }

        else
        {
            throw invalid_argument{"Theres no match card"};
        }
        return *this;
    }

    Player &Player::discover_cure(Color color)
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
        }
        else
        {
            throw std::invalid_argument{"Theres no research station in your city"};
        }
        return *this;
    }

    Player &Player::treat(pandemic::City city)
    {
        if (board.dis_stat(city) == 0)
        {
            throw invalid_argument{"Theres no cubes in the city"};
        }
        if (city != curr_city)
        {
            throw invalid_argument{"The player isn't at the same city"};
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

    Player &Player::take_card(pandemic::City city)
    {
        cards.insert(city);
        return *this;
    }
    Player &Player::remove_cards()
    {
        cards.clear();
        return *this;
    }
}
