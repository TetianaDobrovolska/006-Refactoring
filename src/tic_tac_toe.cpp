#include "tic_tac_toe.h"

#include <algorithm>
#include <iostream>

TicTacToe::TicTacToe(const char name[kMaxNameSize], const char name2[kMaxNameSize])
    : winSymbol(kDefaultSymbol)
{
    Players.emplace_back(Player(name, kXSymbol));
    Players.emplace_back(Player(name2, kOSymbol));
    for (size_t i = 0; i < kMaxCellCount; ++i) {
        cells[i] = kDefaultSymbol;
    }
}

const char * TicTacToe::getFirstPlayer() const
{
    return Players[0].getName();
}

const char * TicTacToe::getSecondPlayer() const
{
    return Players[1].getName();
}

const char TicTacToe::getCellByIndex(const int& index) const
{
    return cells[index - 1];
}

bool TicTacToe::isCellValid(const int& cell) {
    return cell <= kMaxCellCount && cell >= 1 &&
            cells[cell - 1] != Players[1].getSymbol() &&
            cells[cell - 1] != Players[0].getSymbol();
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
    cells[cell - 1] = Players[num - 1].getSymbol();
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
    const char win = winSymbol;
    auto printWinner = [win](Player p) {
        if(p.getSymbol() != win)
            return false;
        std::cout << "Game over. " << p.getName() << " wins!";
        return true;
    };
    auto it = std::find_if(Players.cbegin(), Players.cend(), printWinner);
    if (Players.cend() == it)
        std::cout << "The game is over. Tie!";
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
