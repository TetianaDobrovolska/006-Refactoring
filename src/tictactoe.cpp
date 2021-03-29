#include "tictactoe.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

TicTacToe::TicTacToe(const std::string& player1, const std::string& player2) :
    m_player_name1(player1),
    m_player_name2(player2)
{

}

TicTacToe::~TicTacToe()
{

}

void TicTacToe::show_cells()
{
    system("cls");

    cout << "Cell numbers: \n";
    cout << "-" << 1 << "-" << "|" << "-" << 2 << "-" << "|" << "-" << 3 << "-" << endl;
    cout << "-" << 4 << "-" << "|" << "-" << 5 << "-" << "|" << "-" << 6 << "-" << endl;
    cout << "-" << 7 << "-" << "|" << "-" << 8 << "-" << "|" << "-" << 9 << "-" << endl;

    cout << "Current situation (--- empty):\n" << endl;
    cout << "-" << m_cells[0] << "-" << '|' << "-" << m_cells[1] << "-" << '|' << "-" << m_cells[2] << "-" << endl;
    cout << "-" << m_cells[3] << "-" << '|' << "-" << m_cells[4] << "-" << '|' << "-" << m_cells[5] << "-" << endl;
    cout << "-" << m_cells[6] << "-" << '|' << "-" << m_cells[7] << "-" << '|' << "-" << m_cells[8] << "-" << "\n" << endl;
}

bool TicTacToe::check_cell(size_t cell)
{
    return !(cell > 9 || cell < 1 || m_cells[cell - 1] == 'O' || m_cells[cell - 1] == 'X');
}

void TicTacToe::make_move(int num, size_t cell) {
    if (num == 1) m_cells[cell - 1] = 'X';
    else m_cells[cell - 1] = 'O';
}

char TicTacToe::check()
{
    for (size_t i = 0; i < 3; i++)
        if (m_cells[i * 3] == m_cells[i * 3 + 1] && m_cells[i * 3 + 1] == m_cells[i * 3 + 2])
            return m_cells[i];
        else if (m_cells[i] == m_cells[i + 3] && m_cells[i + 3] == m_cells[i + 6])
            return m_cells[i];
        else if ((m_cells[2] == m_cells[4] && m_cells[4] == m_cells[6]) || (m_cells[0] == m_cells[4] && m_cells[4] == m_cells[8]))
            return m_cells[i];
    return '-';
}

void TicTacToe::result() {
    if (win == 'X')
        cout << m_player_name1 << "you won congratulations " << m_player_name2 << " you lose..." << endl;
    else if (win == 'O') cout << m_player_name2 << "you won congratulations  " << m_player_name1 << " you lose..." << endl;

}

const std::vector<char>& TicTacToe::get_cells() const
{
    return m_cells;
}

const string& TicTacToe::get_player_name1() const
{
    return m_player_name1;
}


const string& TicTacToe::get_player_name2() const
{
    return m_player_name2;
}
