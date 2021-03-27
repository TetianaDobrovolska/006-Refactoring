#include <iostream> 
#include <cstring> 
#include <clocale>
#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"

using namespace std;

int main(__attribute__((unused)) int argc, __attribute__((unused)) char** argv) {
    TicTacToe game;
    do {
        cout << "Enter the name of the first player: ";
        std::cin >> game.PlayerName1;

        cout << "Enter the name of the seecond player: ";
        std::cin >> game.PlayerName2;
    } while (!strcmp(game.PlayerName1, game.PlayerName2));
    
    game.show_cells();

    for (int move = 1; move <= 9; move++) {
        if (move % 2) game.make_move(1);
        else game.make_move(2);

        game.show_cells();
        
        if (move >= 5)
        {
            game.win = game.check();
            if (game.win != '-')
                break;
        }
  
    }

    game.result();
   
    return 0;
}
