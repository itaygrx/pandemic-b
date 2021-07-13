#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

Player &OperationsExpert::build()
{
    if (!board.is_research_station(curr_city))
    {
        board.build(curr_city);
    }
    return *this;
}