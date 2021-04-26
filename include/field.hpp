#ifndef FIELD_HPP
#define FIELD_HPP

#include <vector>
#include <utility>

class Field
{
public:
	Field();
	~Field();
	
	void showCells();
	const std::vector<char> getCellsState();
	char setCellState(const char symbol, const int cellNumber);
private:
	std::vector<char> m_cellsState = { '-','-','-','-','-','-','-','-','-' };
	const int m_fieldSize = 3;
};

#endif