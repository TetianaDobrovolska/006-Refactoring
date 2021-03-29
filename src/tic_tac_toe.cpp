#include <iostream> 
#include <cstring> 
#include <clocale>
#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"

using namespace std;

int main(__attribute__((unused)) int argc, __attribute__((unused)) char** argv) {
    TicTacToe game;
    string PlayerName1, PlayerName2;
    do {
        cout << "Enter the name of the first player: ";
        std::cin >> PlayerName1;

        cout << "Enter the name of the seecond player: ";
        std::cin >> PlayerName2;
    } while (PlayerName1 == PlayerName2);
    
    game.show_cells();

    for (int move = 1; move <= 9; move++) {
        int player = move % 2;
        if (player) {
            cout << game.get_player_name1();
        }
        else {
            cout << game.get_player_name2();
        }

        size_t cell;
        cout << ",enter cell number, make your move:";
        cin >> cell;

        while (!game.check_cell(cell)) {
            cout << "Enter the number of the correct (1-9) or empty (---) cells to make a move:";
            cin >> cell;
            cout << "\n";
        }
        game.make_move(player + 1, cell);

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
