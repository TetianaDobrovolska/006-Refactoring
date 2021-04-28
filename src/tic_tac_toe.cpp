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

bool TicTacToe::make_move(const int& num, const int& cell) {
    return board.setCell(cell, Players[num - 1].getSymbol());
}

char TicTacToe::check_winner() {
    winSymbol = board.checkWinner();
    return winSymbol;
}

void TicTacToe::show_result() {
    if (Board::kDefaultSymbol == winSymbol) {
        std::cout << "The game is over. Tie!";
    } else {
        std::cout << "Game over. "
                  << (Players[0].getSymbol() == winSymbol ? Players[0].getName() : Players[1].getName())
                  << " wins!";
    }
}

void TicTacToe::play() {
    board.showBoard();
    for (int i = 1; i <= Board::kMaxCellCount; i++) {
        int cell;
        int move = i%2 ? 1 : 2;
        do {
            std::cout << "Enter the cell number, make your move:";
            std::cin >> cell;
        } while(!make_move(move, cell));

        board.showBoard();

        if (i < Board::kMinStepsToWin)
            continue;
        winSymbol = board.checkWinner();
        if (winSymbol != Board::kDefaultSymbol)
            break;
    }
    show_result();
}
