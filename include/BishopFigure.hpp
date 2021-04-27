#ifndef BISHOP_FIGURE_TYPE_HPP
#define BISHOP_FIGURE_TYPE_HPP

#include "FigureType.hpp"

class BishopFigure : public FigureType
{
public:
  BishopFigure() = default;
  bool Move(const std::string& curCoord, const std::string& nextCoord) override;
};

#endif //BISHOP_FIGURE_TYPE_HPP
