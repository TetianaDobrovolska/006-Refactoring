#ifndef KNIGHT_FIGURE_TYPE_HPP
#define KNIGHT_FIGURE_TYPE_HPP

#include "FigureType.hpp"

class KnightFigure : public FigureType
{
public:
  KnightFigure() = default;
  bool Move(const std::string& curCoord, const std::string& nextCoord) override;
};

#endif //KNIGHT_FIGURE_TYPE_HPP
