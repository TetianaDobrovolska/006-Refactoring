#ifndef QUEEN_FIGURE_TYPE_HPP
#define QUEEN_FIGURE_TYPE_HPP

#include "ChessFigure.hpp"

class QueenFigure : public ChessFigure
{
public:
  QueenFigure(const std::string& coord);
  ~QueenFigure() override;
  bool Move(const std::string& nextCoord) override;
};

#endif //QUEEN_FIGURE_TYPE_HPP
