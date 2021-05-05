#ifndef ROOK_FIGURE_TYPE_HPP
#define ROOK_FIGURE_TYPE_HPP

#include "ChessFigure.hpp"

class RookFigure : public ChessFigure
{
public:
  RookFigure(const std::string& coord);
  ~RookFigure() override;
  bool Move(const std::string& nextCoord) override;
};

#endif //ROOK_FIGURE_TYPE_HPP
