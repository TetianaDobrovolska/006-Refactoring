#ifndef FIELD_HPP
#define FIELD_HPP

#include "player.hpp"

class Field
{
public:
	Field();
	char getCellSymbol(const int cellIndex) const;
	void setCellSymbol(const int cellIndex, const char symbol);
	char check();
private:
	std::string cells;
	bool checkRow(const int);
	bool checkColumn(const int);
	bool checkFirstDiagonal();
	bool checkSecondDiagonal();
};

#endif // !FIELD_HPP
