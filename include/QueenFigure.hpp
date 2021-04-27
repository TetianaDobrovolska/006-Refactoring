#ifndef QUEEN_FIGURE_TYPE_HPP
#define QUEEN_FIGURE_TYPE_HPP

#include "FigureType.hpp"

class QueenFigure : public FigureType
{
public:
  QueenFigure() = default;
  bool Move(const std::string& curCoord, const std::string& nextCoord) override;
};

#endif //QUEEN_FIGURE_TYPE_HPP
