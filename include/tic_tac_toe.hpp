#pragma once
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <string>

using namespace std;

#define PLAYERS_COUNT 2
#define CELLS_COUNT 9

class TicTacToe
{
private:
	char win;
	string Players[PLAYERS_COUNT];
	char cells[CELLS_COUNT];

public:	
	TicTacToe()	{
		win = '-';
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

	void startGame();
	void enterPlayers();
	void showCellsNumber();
	void showCellsValue();
	int getMoverIndex(int move);
	void makeMove(int num);
	bool isCellValid(int cellnum);
	int enterCell();
	bool isWinner();
	bool isCheckWinnerValid(int move);
	void check();
	void result();


};



#endif