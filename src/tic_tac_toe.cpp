#include <iostream> 
#include <cstring> 
#include <clocale>
#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"

using namespace std;

void show_cells(const TicTacToe& game)
{
    system("cls");
    auto cells = game.get_cells();

    cout << "Cell numbers: \n";
    cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << endl;
    cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << endl;
    cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << endl;

    cout << "Current situation (--- empty):\n" << endl;
    cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << endl;
    cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << endl;
    cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << "\n" << endl;
}


void result(const TicTacToe& game, TicTacToe::player_code win) {
    if (win == TicTacToe::PLAYER1)
        cout << game.get_player_name1() << " you won congratulations " << game.get_player_name2() << " you lose..." << endl;
    else if (win == TicTacToe::PLAYER2) cout << game.get_player_name2() << " you won congratulations  " << game.get_player_name1() << " you lose..." << endl;
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char** argv) {
    string PlayerName1, PlayerName2;
    do {
        cout << "Enter the name of the first player: ";
        std::cin >> PlayerName1;

        cout << "Enter the name of the second player: ";
        std::cin >> PlayerName2;
    } while (PlayerName1 == PlayerName2);
    
    TicTacToe game(PlayerName1, PlayerName2);
    show_cells(game);

    TicTacToe::player_code win = TicTacToe::DRAW;

    for (size_t move = 1; move <= TicTacToe::NUMBER_OF_CELLS; move++) {

        cout << game.get_current_player_name();

        size_t cell;
        cout << ",enter cell number, make your move:";
        cin >> cell;

        while (!game.check_cell(cell)) {
            cout << "Enter the number of the correct (1-9) or empty (---) cells to make a move:";
            cin >> cell;
            cout << "\n";
        }
        game.make_move(cell);

        show_cells(game);
        
        if (move >= 5)
        {
            win = game.winner();
            if (win != TicTacToe::DRAW)
                break;
        }
    }

    result(game, win);
   
    return 0;
}
