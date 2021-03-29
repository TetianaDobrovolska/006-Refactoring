#include "tictactoe.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

const vector<char> TicTacToe::player_sign {
    '-',
    'X',
    'O'
};

static const size_t INDEX_OFFSET = 1;
static const size_t START_CELL_NUMBER = 1;

TicTacToe::TicTacToe(const std::string& player1, const std::string& player2) :
    m_player_name1(player1),
    m_player_name2(player2),
    m_cells(NUMBER_OF_CELLS, player_sign[DRAW])
{

}

TicTacToe::~TicTacToe()
{

}

bool TicTacToe::check_cell(size_t cell) const
{
    const auto cell_value = m_cells[cell - INDEX_OFFSET];
    const bool check_failed = cell > NUMBER_OF_CELLS || cell < START_CELL_NUMBER || cell_value != player_sign[DRAW];
    return !check_failed;
}

void TicTacToe::make_move(size_t cell)
{
    if (!check_cell(cell)) {
        throw out_of_range("wrong cell");
    }
    m_cells[cell - INDEX_OFFSET] = player_sign[current_player];
    switch_player();
}

char TicTacToe::check()
{
    enum {
        LEFT_UP,
        UP,
        RIGHT_UP,
        LEFT_MIDDLE,
        CENTER,
        RIGHT_MIDDLE,
        LEFT_DOWN,
        DOWN,
        RIGHT_DOWN
    };
    if ((m_cells[RIGHT_UP] == m_cells[CENTER] && m_cells[CENTER] == m_cells[LEFT_DOWN]) ||
            (m_cells[LEFT_UP] == m_cells[CENTER] && m_cells[CENTER] == m_cells[RIGHT_DOWN]))
        return m_cells[CENTER];

    for (size_t i = 0; i < NUMBER_OF_ROWS; i++)
        if (m_cells[i * NUMBER_OF_ROWS] == m_cells[i * NUMBER_OF_ROWS + 1] && m_cells[i * NUMBER_OF_ROWS + 1] == m_cells[i * NUMBER_OF_ROWS + 2])
            return m_cells[i * NUMBER_OF_ROWS];
        else if (m_cells[i] == m_cells[i + NUMBER_OF_ROWS] && m_cells[i + NUMBER_OF_ROWS] == m_cells[i + 2*NUMBER_OF_ROWS])
            return m_cells[i];

    return player_sign[DRAW];
}

TicTacToe::player_code TicTacToe::winner()
{
    const auto sign = check();
    const auto it = find(player_sign.cbegin(), player_sign.cend(), sign);
    return static_cast<player_code>(it - player_sign.cbegin());
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

const string &TicTacToe::get_current_player_name() const
{
    return current_player == PLAYER2 ? m_player_name2 : m_player_name1;
}

void TicTacToe::switch_player()
{
    current_player = current_player == PLAYER1 ? PLAYER2 : PLAYER1;
}
