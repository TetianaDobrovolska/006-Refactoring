#include "tictactoe.h"
#include <stdexcept>

using namespace std;

TicTacToe::TicTacToe(const std::string& player1, const std::string& player2) :
    m_player_name1(player1),
    m_player_name2(player2),
    m_cells(9, '-')
{

}

TicTacToe::~TicTacToe()
{

}

bool TicTacToe::check_cell(size_t cell) const
{
    return !(cell > 9 || cell < 1 || m_cells[cell - 1] == 'O' || m_cells[cell - 1] == 'X');
}

void TicTacToe::make_move(int num, size_t cell) {
    if (!check_cell(cell)) {
        throw out_of_range("wrong cell");
    }
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
            return m_cells[4];
    return '-';
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
