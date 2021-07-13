#include <map>
#include <set>
#include <iostream>
#include <string>
using namespace std;
#include "Board.hpp"
#include "OperationsExpert.hpp"
#include "Player.hpp"
using namespace pandemic;

static map<City, set<City>> connections{
    {Algiers, {Madrid, Paris, Istanbul, Cairo}},
    {Atlanta, {Chicago, Miami, Washington}},
    {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
    {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
    {Beijing, {Shanghai, Seoul}},
    {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
    {BuenosAires, {Bogota, SaoPaulo}},
    {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
    {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
    {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
    {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
    {Essen, {London, Paris, Milan, StPetersburg}},
    {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
    {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
    {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
    {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
    {Johannesburg, {Kinshasa, Khartoum}},
    {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
    {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
    {Kinshasa, {Lagos, Khartoum, Johannesburg}},
    {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
    {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
    {Lima, {MexicoCity, Bogota, Santiago}},
    {London, {NewYork, Madrid, Essen, Paris}},
    {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
    {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
    {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
    {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
    {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
    {Milan, {Essen, Paris, Istanbul}},
    {Montreal, {Chicago, Washington, NewYork}},
    {Moscow, {StPetersburg, Istanbul, Tehran}},
    {Mumbai, {Karachi, Delhi, Chennai}},
    {NewYork, {Montreal, Washington, London, Madrid}},
    {Osaka, {Taipei, Tokyo}},
    {Paris, {Algiers, Essen, Madrid, Milan, London}},
    {Riyadh, {Baghdad, Cairo, Karachi}},
    {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
    {Santiago, {Lima}},
    {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
    {Seoul, {Beijing, Shanghai, Tokyo}},
    {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
    {StPetersburg, {Essen, Istanbul, Moscow}},
    {Sydney, {Jakarta, Manila, LosAngeles}},
    {Taipei, {Shanghai, HongKong, Osaka, Manila}},
    {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
    {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
    {Washington, {Atlanta, NewYork, Montreal, Miami}}};

bool Board::is_clean()
{
    for (auto &n : city_cubes)
    {
        if (n.second > 0)
        {
            return false;
        }
    }
    return true;
}

bool Board::is_connected(City &c1, City &c2)
{
    return (bool)connections.at(c1).count(c2);
}

void Board::build(City city)
{
    Research_stations.insert(city);
}

bool Board::is_research_station(City city)
{
    return (bool)Research_stations.count(city);
}

void Board::curing(Color color)
{
    cures.insert(color);
}

bool Board::has_cure(Color color)
{
    return (bool)cures.count(color);
}

int Board::dis_stat(City city)
{
    if ((bool)city_cubes.count(city))
    {
        return city_cubes.at(city);
    }
    return 0;
}

void Board::one_cube(City city)
{
    if ((bool)city_cubes.count(city))
    {
        city_cubes.at(city) -= 1;
    }
}

void Board::all_cubes(City city)
{
    if ((bool)city_cubes.count(city))
    {
        city_cubes.at(city) = 0;
    }
}

Color Board::color(City city)
{
    return cities_colors.at(city);
}

int &Board::operator[](City city)
{
    return city_cubes[city];
}

std::ostream &pandemic::operator<<(std::ostream &os, const Board &board)
{
    os << "-------------------------- BOARD --------------------------" << endl;

    os << "the level of disease in the cities:" << std::endl;
    for (const auto &city : cities_colors)
    {
        if ((bool)board.city_cubes.count(city.first))
        {
            os << "\t" << city_to_string(city.first) << ":\t" << board.city_cubes.at(city.first) << std::endl;
        }
        else
        {
            os << "\t" << city_to_string(city.first) << ":\t0" << std::endl;
        }
    }
    os << "Research stations:" << std::endl;
    for (const auto &res : board.Research_stations)
    {
        os << "\t" << city_to_string(res) << std::endl;
    }
    os << "Cure discovered for the colors:" << std::endl;
    for (const auto &cure : board.cures)
    {
        os << "\t" << color_to_string(cure) << std::endl;
    }
    return os;
}

void Board::remove_cures()
{
    cures.clear();
}

void Board::remove_stations()
{
    Research_stations.clear();
}

/**
int main()
{

    clang++-9 Board.cpp Player.cpp OperationsExpert.cpp -o main
    

    std::cout << "-----------------PANDEMIC GAME------------------" << std::endl;
    std::cout << std::endl;

    //initialize a board//
    pandemic::Board board;

    std::cout << "-----------------Clean Board------------------" << std::endl;
    std::cout << std::endl;
    std::cout << board << std::endl;

    //put cubes in some cities//

    board[City::Kinshasa] = 3;
    board[City::Kinshasa] = 2;
    board[City::Essen] = 3;
    board[City::HoChiMinhCity] = 1;
    board[City::Chicago] = 1;

    std::cout << "-----------------After puting some disease cube------------------" << std::endl;
    std::cout << std::endl;

    std::cout << board << std::endl;

    //creating a player//
    pandemic::OperationsExpert player{board, City::Atlanta}; 
    player.take_card(City::Johannesburg)
        .take_card(City::Khartoum)
        .take_card(City::SaoPaulo)
        .take_card(City::BuenosAires)
        .take_card(City::HoChiMinhCity);

    // build action //

    player.build();
    player.drive(City::Washington); 
    player.build();
    player.drive(City::Montreal);
    player.build();

    std::cout << "-----------------After bulding a research station------------------" << std::endl;
    std::cout << std::endl;

    std::cout << board << std::endl;

    //dicover cure//

    player.take_card(City::Montreal);
    player.take_card(City::Milan);
    player.take_card(City::Madrid);
    player.take_card(City::Chicago);
    player.take_card(City::London);
    player.discover_cure(Blue);

    std::cout << "-----------------After finding a cure------------------" << std::endl;
    std::cout << std::endl;

    std::cout << board << std::endl;

    player.take_card(City::Montreal);
    player.fly_charter(Essen);
    player.treat(Essen);

    std::cout << "-----------------After treating------------------" << std::endl;
    std::cout << std::endl;

    std::cout << board << std::endl;
}*/