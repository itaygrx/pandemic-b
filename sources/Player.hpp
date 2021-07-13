#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic
{

    class Player
    {
    protected:
        std::set<City> cards;
        City curr_city;
        std::string _role;
        Board &board;

    public:
        Player(Board &board, City city, std::string role) : board(board), curr_city(city), _role(role) {}
        virtual Player &drive(City city);
        virtual Player &fly_direct(City city);
        virtual Player &fly_charter(City city);
        virtual Player &fly_shuttle(City city);
        virtual Player &build();
        virtual Player &discover_cure(Color color);
        virtual Player &treat(City city);
        Player &take_card(City city);
        Player &remove_cards();
        std::string role() { return _role; }
        ~Player(){}
    };

}