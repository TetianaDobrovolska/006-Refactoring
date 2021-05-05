#ifndef CHESS_FIGURE_HPP
#define CHESS_FIGURE_HPP

#include <string>

class ChessFigure
{
public:
  static constexpr int kFirstLetter = 'A';
  static constexpr int kLastLetter = 'H';
  static constexpr int kFirstDigit = '1';
  static constexpr int kLastDigit = '8';

  ChessFigure(const std::string& coord);
  virtual ~ChessFigure();

  virtual bool Move(const std::string& nextCoord) = 0;

protected:
  bool isCoordValid(const std::string& coord);
  std::string currentCoord;
};

#endif
