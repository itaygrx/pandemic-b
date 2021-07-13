#pragma once
#include <map>

namespace pandemic
{

    enum Color
    {
        Yellow,
        Red,
        Blue,
        Black
    };

    inline std::string color_to_string(Color color)
    {
        switch (color)
        {
        case Black:
            return "Black";
            break;

        case Blue:
            return "Blue";
            break;

        case Red:
            return "Red";
            break;

        case Yellow:
            return "Yellow";
            break;
        }
    }
}