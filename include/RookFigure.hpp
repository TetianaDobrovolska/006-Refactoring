#ifndef ROOK_FIGURE_TYPE_HPP
#define ROOK_FIGURE_TYPE_HPP

#include "FigureType.hpp"

class RookFigure : public FigureType
{
public:
  RookFigure() = default;
  bool Move(const std::string& curCoord, const std::string& nextCoord) override;
};

#endif //ROOK_FIGURE_TYPE_HPP
