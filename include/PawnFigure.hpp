#ifndef PAWN_FIGURE_TYPE_HPP
#define PAWN_FIGURE_TYPE_HPP

#include "FigureType.hpp"

class PawnFigure : public FigureType
{
public:
  PawnFigure() = default;
  bool Move(const std::string& curCoord, const std::string& nextCoord) override;
};

#endif //PAWN_FIGURE_TYPE_HPP
