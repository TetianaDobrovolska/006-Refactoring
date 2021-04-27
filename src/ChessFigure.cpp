#include "ChessFigure.hpp"

#include <cmath>

namespace {

constexpr int kFirstLetter = 'A';
constexpr int kLastLetter = 'H';
constexpr int kFirstDigit = '1';
constexpr int kLastDigit = '8';

bool isCoordValid(const std::string& coord)
{
  return coord[0] >= kFirstLetter &&
      coord[0] <= kLastLetter &&
      coord[1] >= kFirstDigit &&
      coord[1] <= kLastDigit;
}

}  //namespace

ChessFigure::ChessFigure(FigureType* type, const std::string& coord) 
  : type(type), currentCoord(coord)
{
}

ChessFigure::~ChessFigure()
{
}

bool ChessFigure::Move(const std::string& nextCoord)
{
  if (!isCoordValid(nextCoord))
    return false;
  return type->Move(currentCoord, nextCoord) ? true : false;
}
