#pragma once
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <string>

using namespace std;

#define PLAYERS_COUNT 2
#define CELLS_COUNT 9
#define FIRST_CELL_INDEX 0
#define MOVER_CORRECTION 1
#define CELL_CORRECTION 1
#define STEP 1
#define BOARD_CENTER_CELL 4
#define HALF_MOVES 4


class TicTacToe 
{
private:
	char win;
	string Players[PLAYERS_COUNT];
	char cells[CELLS_COUNT];
	int moverIndex;

public:	
	TicTacToe()	{
		win = initsymbol;
		for (int i = 0; i < CELLS_COUNT; i++) {
			cells[i] = initsymbol;
		}
	}
	const char initsymbol = '*';
	char getWin();
	void setWin(char _win);
	string getPlayerName(int index);
	void setPlayerName(string name, int index);
	char getCellValue(int index);
	void setCellValue(char symbol, int index);
	int getMoverIndex();
	void setMoverIndex(int move);

	void startGame();
	void enterPlayers();
	void showCellsNumber();
	void showCellsValue();
	void showMover();
	void makeMove(int num);
	bool isCellValid(int cellnum);
	int enterCell();
	bool check(int move);
	bool isHorizontalWinner(int index);
	bool isVerticalWinner(int index);
	bool isDiagWinner();
	void result();


};



#endif