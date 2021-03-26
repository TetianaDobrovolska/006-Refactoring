#include <iostream>
#include <cstring>
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char win = '-';
char PlayerName1[80], PlayerName2[80];
char cells[9] = { '-','-','-','-','-','-','-','-','-' };

void show_cells()
{
    //system("cls");

    cout << "Cell numbers: \n";
    cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << endl;
    cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << endl;
    cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << endl;

    cout << "Current situation (--- empty):\n" << endl;
    cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << endl;
    cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << endl;
    cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << "\n" << endl;
}

bool is_out_of_range(int cell)
{
    return cell > 9 || cell < 1;
}

bool is_occupied(int cell)
{
    char status = cells[cell - 1];
    return status == 'O' || status == 'X';
}

bool is_valid(int cell)
{
    if (is_out_of_range(cell) || is_occupied(cell)) {
        cout << "Enter the number of the correct (1-9) or empty (---) cells to make a move:";
        return false;
    }
    return true;
}

void make_move(int num)
{
    cout << ((num == 1) ? PlayerName1 : PlayerName2) << ", enter cell number, make your move:";

    int cell;
    do {
        cin >> cell;
    } while (!is_valid(cell));

    cells[cell - 1] = (num == 1) ? 'X' : 'O';

    cout << "\n";
}

char check_horizontal_markers(int i)
{
    char a = cells[i * 3];
    char b = cells[i * 3 + 1];
    char c = cells[i * 3 + 2];

    return (a == b && b == c) ? a : '-';
}

char check_vertical_markers(int i)
{
    char a = cells[i];
    char b = cells[i + 3];
    char c = cells[i + 6];

    return (a == b && b == c) ? a : '-';
}

char check_diagonal_markers()
{
    if ((cells[2] == cells[4] && cells[4] == cells[6]) ||
        (cells[0] == cells[4] && cells[4] == cells[8])) {
        return cells[2];
    }
    else {
        return '-';
    }
}

char check_aligned_markers(char cells[], int i)
{
    char ret;

    if((ret = check_horizontal_markers(i)) != '-')
        return ret;
    if((ret = check_vertical_markers(i)) != '-')
        return ret;
    if((ret = check_diagonal_markers()) != '-')
        return ret;

    return '-';
}

char check()
{
    char ret = '-';
    for (int i = 0; i < 3; i++) {
        if ((ret = check_aligned_markers(cells, i)) != '-')
            break;
    }
    return ret;
}

void result()
{
    if (win == 'X')
        cout << PlayerName1 << " you won congratulations. " << PlayerName2 << " you lose..." << endl;
    else if (win == 'O')
        cout << PlayerName2 << " you won congratulations.  " << PlayerName1 << " you lose..." << endl;
}
