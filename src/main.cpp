#include <iostream>
#include <cstring>
#include "tic_tac_toe.h"


int main(int argc, char** argv) {
    char PlayerName1[TicTacToe::kMaxNameSize];
    char PlayerName2[TicTacToe::kMaxNameSize];
    do {
        std::cout << "Enter the name of the first player: ";
        std::cin >> PlayerName1;

        std::cout << "Enter the name of the seecond player: ";
        std::cin >> PlayerName2;
    } while (!strcmp(PlayerName1, PlayerName2));

    TicTacToe game(PlayerName1, PlayerName2);
    game.show_cells();

    char win;
    for (int i = 1; i <= TicTacToe::kMaxCellCount; i++) {
        int cell;
        int move = i%2 ? 1 : 2;
        do {
            std::cout << "Enter the cell number, make your move:";
            std::cin >> cell;
        } while(!game.make_move(move, cell));

        game.show_cells();

        if (i < TicTacToe::kMinStepsToWin)
            continue;
        win = game.check_winner();
        if (win != TicTacToe::kDefaultSymbol)
            break;
    }
    game.result();

    return 0;
}