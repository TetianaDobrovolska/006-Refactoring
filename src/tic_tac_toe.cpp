#include "tic_tac_toe.h"

#include <iostream>
#include <cstring>

namespace {

void printResult(const std::string& winer, const std::string loser) {
    std::cout << winer << "you won congratulations " << loser << " you lose..." << std::endl;
}

}  //namespace

TicTacToe::TicTacToe(const char name[kMaxNameSize], const char name2[kMaxNameSize])
    : winSymbol(kDefaultSymbol)
{
    strcpy(PlayerName1, name);
    strcpy(PlayerName2, name2);
    for (size_t i = 0; i < kMaxCellCount; ++i) {
        cells[i] = kDefaultSymbol;
    }
}

const char * TicTacToe::getFirstPlayer() const
{
    return PlayerName1;
}

const char * TicTacToe::getSecondPlayer() const
{
    return PlayerName2;
}

const char TicTacToe::getCellByIndex(const int& index) const
{
    return cells[index - 1];
}

bool TicTacToe::isCellValid(const int& cell) {
    return cell <= kMaxCellCount && cell >= 1 &&
            cells[cell - 1] != kOSymbol &&
            cells[cell - 1] != kXSymbol;
}

bool TicTacToe::isHorizontalLine(const int& index) {
    return cells[index * kRowSize] != kDefaultSymbol &&
            cells[index * kRowSize] == cells[index * kRowSize + 1] &&
            cells[index * kRowSize + 1] == cells[index * kRowSize + 2];
}

bool TicTacToe::isVerticalLine(const int& index) {
    return cells[index] != kDefaultSymbol &&
            cells[index] == cells[index + kRowSize] &&
            cells[index + kRowSize] == cells[index + 2 * kRowSize];
}

bool TicTacToe::isRightDiagonalLine() {
    return cells[0] != kDefaultSymbol && cells[0] == cells[4] && cells[4] == cells[8];
}

bool TicTacToe::isLeftDiagonalLine() {
    return cells[2] != kDefaultSymbol && cells[2] == cells[4] && cells[4] == cells[6];
}

bool TicTacToe::make_move(const int& num, const int& cell) {
    if (!isCellValid(cell)) {
        std::cout << "Enter the number of the correct (1-9) or empty (---) cells to make a move:";
        return false;
    }
    if (num == 1) cells[cell - 1] = kXSymbol;
    else cells[cell - 1] = kOSymbol;
    return true;
}

char TicTacToe::check_winner() {
    if(isRightDiagonalLine() || isLeftDiagonalLine())
        winSymbol = cells[4];
    for (int i = 0; i < kRowSize; ++i) {
        if (isHorizontalLine(i))
            winSymbol = cells[i * kRowSize];
        if(isVerticalLine(i))
            winSymbol = cells[i];
    }
    return winSymbol;
}

void TicTacToe::result() {
    if (winSymbol == kXSymbol)
        printResult(PlayerName1, PlayerName2);
    else if (winSymbol == kOSymbol)
        printResult(PlayerName2, PlayerName1);
    else
        std::cout << "The game ended in a draw";
}

void TicTacToe::show_cells() {
    system("cls");

    std::cout << "Cell numbers: \n";
    for (int i = 0; i < kRowSize; ++i) {
        std::cout << '-' << i * kRowSize + 1 << '-' << '|'
                << '-' << i * kRowSize + 2 << '-' << '|'
                << '-' << i * kRowSize + 3 << '-' << '\n';
    }
    std::cout << std::endl;
    std::cout << "Current situation (--- empty):\n" << std::endl;
    for (int i = 0; i < kRowSize; ++i) {
        std::cout << '-' << cells[i * kRowSize] << '-' << '|'
                << '-' << cells[i * kRowSize + 1] << '-' << '|'
                << '-' << cells[i * kRowSize + 2] << '-' << '\n';
    }
    std::cout << std::endl;
}
