#ifndef PAWN_FIGURE_TYPE_HPP
#define PAWN_FIGURE_TYPE_HPP

#include "ChessFigure.hpp"

class PawnFigure : public ChessFigure
{
public:
  PawnFigure(const std::string& coord);
  ~PawnFigure() override;
  bool Move(const std::string& nextCoord) override;
};

#endif //PAWN_FIGURE_TYPE_HPP
