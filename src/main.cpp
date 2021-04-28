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
    game.play();

    return 0;
}