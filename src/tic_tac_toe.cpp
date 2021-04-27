#include "tic_tac_toe.h"

#include <algorithm>
#include <iostream>

TicTacToe::TicTacToe(const char name[Player::kMaxNameSize], const char name2[Player::kMaxNameSize])
    : winSymbol(Board::kDefaultSymbol)
    , board()
{
    Players.emplace_back(Player(name, Board::kXSymbol));
    Players.emplace_back(Player(name2, Board::kOSymbol));
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
    return board.getCellByIndex(index);
}

bool TicTacToe::isCellValid(const int& cell) {
    return cell <= Board::kMaxCellCount && cell >= 1 &&
            board.getCellByIndex(cell) != Players[1].getSymbol() &&
            board.getCellByIndex(cell) != Players[0].getSymbol();
}

bool TicTacToe::make_move(const int& num, const int& cell) {
    if (!isCellValid(cell)) {
        std::cout << "Enter the number of the correct (1-9) or empty (---) cells to make a move:";
        return false;
    }
    board.setCell(cell, Players[num - 1].getSymbol());
    return true;
}

char TicTacToe::check_winner() {
    
    winSymbol = board.checkWinner();
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
    board.showBoard();
}
