#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include "FigureType.hpp"

class ChessFigure
{
public:
  ChessFigure(FigureType* type, const std::string& coord);
  virtual ~ChessFigure();

  bool Move(const std::string& nextCoord);

private:
  FigureType* type;
  std::string currentCoord;
};

#endif
