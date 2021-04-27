#include <iostream>
#include <cstring>
#include "tic_tac_toe.h"


int main(int argc, char** argv) {
    char PlayerName1[Player::kMaxNameSize];
    char PlayerName2[Player::kMaxNameSize];
    do {
        std::cout << "Enter the name of the first player: ";
        std::cin >> PlayerName1;

        std::cout << "Enter the name of the seecond player: ";
        std::cin >> PlayerName2;
    } while (!strcmp(PlayerName1, PlayerName2));

    TicTacToe game(PlayerName1, PlayerName2);
    game.show_cells();

    char win;
    for (int i = 1; i <= Board::kMaxCellCount; i++) {
        int cell;
        int move = i%2 ? 1 : 2;
        do {
            std::cout << "Enter the cell number, make your move:";
            std::cin >> cell;
        } while(!game.make_move(move, cell));

        game.show_cells();

        if (i < Board::kMinStepsToWin)
            continue;
        win = game.check_winner();
        if (win != Board::kDefaultSymbol)
            break;
    }
    game.result();

    return 0;
}