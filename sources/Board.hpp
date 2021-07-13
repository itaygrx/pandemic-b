#pragma once
#include <map>
#include <set>
#include <iostream>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{

    class Board
    {
        std::map<City, int> city_cubes;
        std::set<City> Research_stations;
        std::set<Color> cures;

    public:
        Board() {}
        bool is_clean();
        static bool is_connected(City &c1, City &c2);
        void build(City city);
        bool is_research_station(City city);
        void curing(Color color);
        bool has_cure(Color color);
        int dis_stat(City city);
        void one_cube(City city);
        void all_cubes(City city);
        static Color color(City city);
        int &operator[](City city);
        friend std::ostream &operator<<(std::ostream &os, const Board &board);
        void remove_cures();
        void remove_stations();
        ~Board(){}
    };

}