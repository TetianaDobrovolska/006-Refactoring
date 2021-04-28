#include "utils.hpp"

bool Utils::IsFigureInDeskWidth(char coord)
{
    return coord >= BEGIN_DESK_LETTER && coord <= END_DESK_LETTER;
}

bool Utils::IsFigureInDeskHeight(char coord)
{
    return coord >= BEGIN_DESK_DIGIT && coord <= END_DESK_DIGIT;
}

bool Utils::IsFigureInDesk(const std::string& coords)
{
    return IsFigureInDeskWidth(coords[0]) && IsFigureInDeskHeight(coords[1]);
}
