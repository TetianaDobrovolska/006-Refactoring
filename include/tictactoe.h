#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <stdlib.h>

#include <iostream>
using namespace std;

class TicTacToe
{
public:
    TicTacToe();
    ~TicTacToe(){}


    void show_cells() {
        system("cls");

        cout << "Cell numbers: \n";
        cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << endl;
        cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << endl;
        cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << endl;

        cout << "Current situation (--- empty):\n" << endl;
        cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << endl;
        cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << endl;
        cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << "\n" << endl;

    }

    void make_move(int num) {
        if (num == 1) cout << PlayerName1;
        else cout << PlayerName2;
        int cell;
        cout << ",enter cell number, make your move:";
        cin >> cell;

        while (cell > 9 || cell < 1 || cells[cell - 1] == 'O' || cells[cell - 1] == 'X') {
            cout << "Enter the number of the correct (1-9) or empty (---) cells to make a move:";
            cin >> cell;
            cout << "\n";
        }

        if (num == 1) cells[cell - 1] = 'X';
        else cells[cell - 1] = 'O';
    }

    char check()
    {
        for (int i = 0; i < 3; i++)
            if (cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2])
                return cells[i];
            else if (cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6])
                return cells[i];
            else if ((cells[2] == cells[4] && cells[4] == cells[6]) || (cells[0] == cells[4] && cells[4] == cells[8]))
                return cells[i];
        return '-';
    }

    void result() {
        if (win == 'X')
            cout << PlayerName1 << "you won congratulations " << PlayerName2 << " you lose..." << endl;
        else if (win == 'O') cout << PlayerName2 << "you won congratulations  " << PlayerName1 << " you lose..." << endl;

    }

    char win = '-';
    char PlayerName1[80], PlayerName2[80];
private:
    char cells[9] = { '-','-','-','-','-','-','-','-','-' };
};

#endif // TICTACTOE_H
