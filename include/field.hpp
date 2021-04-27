#ifndef FIELD_HPP
#define FIELD_HPP

#include <vector>
#include <utility>

class Field
{
public:
	Field();
	~Field();
	
	const char emptyCell = '-';
	const int firstCell = 1;
	const int lastCell = 9;

	void showCells();
	const std::vector<char> getCellsState();
	char setCellState(const char symbol, const int cellNumber);
	char checkWin();
	void eraseField();
	bool checkTurnVariations();
private:
	std::vector<char> m_cellsState = { '-','-','-','-','-','-','-','-','-' };
	const int m_fieldSize = 3;

	char m_checkHorizontalRezult();
	char m_checkVerticalRezult();
	char m_checkDiagonalRezult();
	bool m_checkResult(const char &result);
	
};

#endif