#ifndef KNIGHT_FIGURE_TYPE_HPP
#define KNIGHT_FIGURE_TYPE_HPP

#include "ChessFigure.hpp"

class KnightFigure : public ChessFigure
{
public:
  KnightFigure(const std::string& coord);
  ~KnightFigure() override;
  bool Move(const std::string& nextCoord) override;
};

#endif //KNIGHT_FIGURE_TYPE_HPP
