#ifndef KING_FIGURE_TYPE_HPP
#define KING_FIGURE_TYPE_HPP

#include "ChessFigure.hpp"

class KingFigure : public ChessFigure
{
public:
  KingFigure(const std::string& coord);
  ~KingFigure() override;
  bool Move(const std::string& nextCoord) override;
};

#endif //KING_FIGURE_TYPE_HPP
