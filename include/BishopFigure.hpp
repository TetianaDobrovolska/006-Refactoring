#ifndef BISHOP_FIGURE_TYPE_HPP
#define BISHOP_FIGURE_TYPE_HPP

#include "ChessFigure.hpp"

class BishopFigure : public ChessFigure
{
public:
  BishopFigure(const std::string& coord);
  ~BishopFigure() override;
  bool Move(const std::string& nextCoord) override;
};

#endif //BISHOP_FIGURE_TYPE_HPP
