#ifndef FIGURE_TYPE_HPP
#define FIGURE_TYPE_HPP

#include <string>

class FigureType
{
public:
  FigureType() = default;
  virtual bool Move(const std::string& curCoord, const std::string& nextCoord) = 0;
};

#endif //FIGURE_TYPE_HPP
