#include "tic_tac_toe.hpp"
#include <iostream> 
#include <cstring> 
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
#include <istream>
#include <math.h>
using namespace std;

char TicTacToe::getWin() {
	return win;
}

void TicTacToe::setWin(char _win) {
	win = _win;
}

string TicTacToe::getPlayerName(int index)
{
	return Players[index];
}

void TicTacToe::setPlayerName(string name, int index)
{
	Players[index] = name;
}

char TicTacToe::getCellValue(int index)
{
	return cells[index];
}

void TicTacToe::setCellValue(char symbol, int index)
{
	cells[index] = symbol;
}

int TicTacToe::getMoverIndex()
{
	return moverIndex;
}
void TicTacToe::setMoverIndex(int move)
{
	moverIndex = move % PLAYERS_COUNT;
}

void TicTacToe::startGame()
{
	for (int move = 1; move <= CELLS_COUNT; move++) {
		makeMove(move);
		showCellsNumber();
		showCellsValue();
		if (isCheckWinnerValid(move))
		{
			check();
			if (isWinner()) {
				result();
				break;
			}
		}
	}
}

void TicTacToe::enterPlayers()
{
	string name = "";

	for (int i = 0; i < PLAYERS_COUNT; i++) {
		printf("Enter the name for %d player:", i + 1);
		getline(cin, name);
		setPlayerName(name, i);
	}
}

void TicTacToe::showCellsNumber() {
	system("cls");
	printf("Cell numbers: \n");
	for (int i = 0; i < CELLS_COUNT; i++) {
		printf("| - %d -|", i + 1);
		if ((i + 1) % static_cast<int>(sqrt(CELLS_COUNT)) == 0) {
			printf("\n");
		}
	}
}
void TicTacToe::showCellsValue() {
	printf("Current situation (-%c- empty):\n", initsymbol);
	for (int i = 0; i < CELLS_COUNT; i++) {
		printf("| - %c -|", getCellValue(i));
		if ((i + 1) % static_cast<int>(sqrt(CELLS_COUNT)) == 0) {
			printf("\n");
		}
	}
}

void TicTacToe::showMover()
{
	string movername = getPlayerName(getMoverIndex());
	printf("Player Name = %s your move", movername.c_str());
}

void TicTacToe::makeMove(int move) {
	setMoverIndex(move - MOVER_CORRECTION);
	int mover = getMoverIndex();
	showMover();
	int cell = enterCell();
	if (mover == PLAYERS_COUNT - MOVER_CORRECTION) {
		setCellValue('O', cell);
	}
	else {
		setCellValue('X', cell);
	}
}

bool TicTacToe::isCellValid(int cellnum)
{
	bool cellnumValid = cellnum < CELLS_COUNT + CELL_CORRECTION && cellnum > FIRST_CELL_INDEX;
	bool cellValid = getCellValue(cellnum - CELL_CORRECTION) != 'O' && getCellValue(cellnum - CELL_CORRECTION) != 'X';
	return cellnumValid && cellValid;
}

int TicTacToe::enterCell()
{
	int cell;
	do {
		printf("\nEnter the number (1-9) or empty (---) cells to make a move:");
		cin >> cell;
	} while (!isCellValid(cell));
	return cell - 1;
}

bool TicTacToe::isWinner()
{
	if (getWin() != initsymbol) {
		return true;
	}
	return false;
}

bool TicTacToe::isCheckWinnerValid(int move)
{
	if (move > HALF_MOVES)
	{
		return true;
	}
	return false;
}

void TicTacToe::check()
{
	for (int i = 0; i < sqrt(CELLS_COUNT); i++) {
		if ( isHorizontalWinner(i)) {
			setWin(getCellValue(i * sqrt(CELLS_COUNT)));
			break;
		}
		if (isVerticalWinner(i)) {
			setWin(getCellValue(i));
			break;
		}
	}
	if (isDiagWinner()) {
		setWin(getCellValue(BOARD_CENTER_CELL));
	}
}

bool TicTacToe::isHorizontalWinner(int index)
{
	for (int i = 0; i < sqrt(CELLS_COUNT) - STEP; i++) {
		if (getCellValue(index * sqrt(CELLS_COUNT) + i) != getCellValue(index * sqrt(CELLS_COUNT) + i + STEP)) {
			return false;
			break;
		}
	}
	return true;
}

bool TicTacToe::isVerticalWinner(int index)
{
	for (int i = 0; i < sqrt(CELLS_COUNT) - STEP; i++) {
		if (getCellValue(index + (i * sqrt(CELLS_COUNT))) != getCellValue(index + ((i + STEP) * sqrt(CELLS_COUNT)))) {
			return false;
			break;
		}
	}
	return true;

}

bool TicTacToe::isDiagWinner()
{
	bool diagrigthleft = getCellValue(sqrt(CELLS_COUNT) - CELL_CORRECTION) == getCellValue(BOARD_CENTER_CELL) && 
							getCellValue(BOARD_CENTER_CELL) == getCellValue(CELLS_COUNT - sqrt(CELLS_COUNT));
	bool diagleftright = getCellValue(FIRST_CELL_INDEX) == getCellValue(BOARD_CENTER_CELL) && 
							getCellValue(BOARD_CENTER_CELL) == getCellValue(CELLS_COUNT - CELL_CORRECTION);

	return diagleftright || diagrigthleft;
}

void TicTacToe::result()
{
	if (getWin() == 'X') {
		printf("%s you won congratulations %s you lose...", getPlayerName(0).c_str(), getPlayerName(1).c_str());
	}
	else if (getWin() == 'O') {
		printf("%s you won congratulations %s you lose...", getPlayerName(1).c_str(), getPlayerName(0).c_str());
	}
}
int main(int argc, char** argv) {
	TicTacToe tictactoe;
	tictactoe.enterPlayers();
	tictactoe.showCellsNumber();
	tictactoe.showCellsValue();
	tictactoe.startGame();
	return 0;
}
