#ifndef KING_FIGURE_TYPE_HPP
#define KING_FIGURE_TYPE_HPP

#include "FigureType.hpp"

class KingFigure : public FigureType
{
public:
  KingFigure() = default;
  bool Move(const std::string& curCoord, const std::string& nextCoord) override;
};

#endif //KING_FIGURE_TYPE_HPP
