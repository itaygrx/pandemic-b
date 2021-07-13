#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Medic: public Player{

        public:
            Medic(Board& b, City city): Player(b, city, "Medic") {}
            Player& treat(City city) override;
            Player & drive(pandemic::City city) override;
            Player & fly_direct(pandemic::City city) override;
            Player & fly_charter(pandemic::City city) override;
            Player & fly_shuttle(pandemic::City city) override;
    };
}