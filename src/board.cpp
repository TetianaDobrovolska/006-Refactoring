#include "board.h"

#include <iostream>

Board::Board()
{
    for (size_t i = 0; i < kMaxCellCount; ++i) {
        cells[i] = kDefaultSymbol;
    }
}

const char Board::getCellByIndex(const int& index) const
{
    return cells[index - 1];
}

bool Board::setCell(const int& index, const char symbol) {
     if (!isCellValid(index)) {
        std::cout << "Enter the number of the correct (1-9) or empty (---) cells to make a move: ";
        return false;
    }
    cells[index - 1] = symbol;
    return true;
}

bool Board::isHorizontalLine(const int& index) {
    return cells[index * kRowSize] != kDefaultSymbol &&
            cells[index * kRowSize] == cells[index * kRowSize + 1] &&
            cells[index * kRowSize + 1] == cells[index * kRowSize + 2];
}

bool Board::isVerticalLine(const int& index) {
    return cells[index] != kDefaultSymbol &&
            cells[index] == cells[index + kRowSize] &&
            cells[index + kRowSize] == cells[index + 2 * kRowSize];
}

bool Board::isRightDiagonalLine() {
    return cells[0] != kDefaultSymbol &&
            cells[0] == cells[4] &&
            cells[4] == cells[8];
}

bool Board::isLeftDiagonalLine() {
    return cells[2] != kDefaultSymbol &&
            cells[2] == cells[4] &&
            cells[4] == cells[6];
}

bool Board::isCellValid(const int& cell) {
    return cell <= kMaxCellCount && cell >= 1 &&
            cells[cell - 1] == kDefaultSymbol;
}

char Board::checkWinner() {
    if(isRightDiagonalLine() || isLeftDiagonalLine())
        return cells[4];
    for (int i = 0; i < kRowSize; ++i) {
        if (isHorizontalLine(i))
            return cells[i * kRowSize];
        if(isVerticalLine(i))
            return cells[i];
    }
    return kDefaultSymbol;
}

void Board::showBoard() {
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
