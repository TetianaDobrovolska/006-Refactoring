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
		printf("| - %c -|", cells[i]);
		if ((i + 1) % static_cast<int>(sqrt(CELLS_COUNT)) == 0) {
			printf("\n");
		}
	}
}

int TicTacToe::getMoverIndex(int move)
{
	if (move % 2) {
		printf("Player Name = %s your move", getPlayerName(0).c_str());
		return 1;
	}
	else {
		printf("Player Name = %s your move", getPlayerName(1).c_str());
		return 2;
	}
}
void TicTacToe::makeMove(int move) {
	int mover = getMoverIndex(move);
	int cell = enterCell();
	if (mover == 1) {
		setCellValue('X', cell);
	}
	else {
		setCellValue('O', cell);
	}
}

bool TicTacToe::isCellValid(int cellnum)
{
	if (cellnum > 9 || cellnum < 1 || getCellValue(cellnum - 1) == 'O' || getCellValue(cellnum - 1) == 'X') {
		return false;
	}
	else {
		return true;
	}
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
	else {
		return false;
	}
}

bool TicTacToe::isCheckWinnerValid(int move)
{
	if (move > 4)
	{
		return true;
	}
	return false;
}

void TicTacToe::check()
{
	for (int i = 0; i < 3; i++) {
		if ((getCellValue(i * 3) == getCellValue(i * 3 + 1) && getCellValue(i * 3 + 1) == getCellValue(i * 3 + 2)) ||
			(getCellValue(i) == getCellValue(i + 3) && getCellValue(i + 3) == getCellValue(i + 6))) {
			setWin(getCellValue(i));
		}
	}
	if ((getCellValue(2) == getCellValue(4) && getCellValue(4) == getCellValue(6)) ||
		(getCellValue(0) == getCellValue(4) && getCellValue(4) == getCellValue(8))) {
		setWin(getCellValue(4));
	}
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
