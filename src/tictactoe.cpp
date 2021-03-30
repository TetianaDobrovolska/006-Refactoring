#include "tictactoe.h"
#include <stdexcept>
#include <algorithm>
#include <cassert>

using namespace std;
using namespace tictactoe;

const vector<char> TicTacToe::player_sign {
    '-',
    'X',
    'O'
};

static const size_t INDEX_OFFSET = 1;
static const size_t START_CELL_NUMBER = 1;


TicTacToe::TicTacToe(const std::string& player1, const std::string& player2) :
    m_players{new NullPlayer(), new Player(player_sign[PLAYER1], PLAYER1, player1), new Player(player_sign[PLAYER2], PLAYER2, player2)},
    m_current_player(m_players[PLAYER1]),
    m_cells(NUMBER_OF_CELLS, player_sign[DRAW])
{

}

TicTacToe::~TicTacToe()
{
    for(auto player : m_players) {
        delete player;
    }
}

bool TicTacToe::check_cell(const size_t cell) const
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
    m_cells[cell - INDEX_OFFSET] = m_current_player->getSymbol();
    switch_player();
}

char TicTacToe::check() const
{
    char winner_sign = player_sign[DRAW];

    if (diagonal_match(winner_sign)) {
        return winner_sign;
    }
    for (size_t i = 0; i < NUMBER_OF_ROWS; i++) {
        const bool matched = horizontal_match(i, winner_sign) || vertical_match(i, winner_sign);
        if (matched && winner_sign != player_sign[DRAW]) {
            break;
        }
    }

    return winner_sign;
}

const IPlayer& TicTacToe::winner() const
{
    const auto sign = check();
    if (sign == player_sign[DRAW]) {
        return *m_players[DRAW];
    }
    auto predicate = [=](IPlayer* player) { return !player->isNull() && player->getSymbol() == sign; };
    const auto it = find_if(m_players.cbegin(), m_players.cend(), predicate);
    assert(it != m_players.cend());
    return **it;
}

const std::vector<char>& TicTacToe::get_cells() const
{
    return m_cells;
}

const string& TicTacToe::get_player_name1() const
{
    return m_players[PLAYER1]->getName();
}


const string& TicTacToe::get_player_name2() const
{
    return m_players[PLAYER2]->getName();
}

const string& TicTacToe::get_current_player_name() const
{
    return m_current_player->getName();
}

void TicTacToe::switch_player()
{
    m_current_player = m_current_player->getId() == PLAYER1 ? m_players[PLAYER2] : m_players[PLAYER1];
}

bool TicTacToe::horizontal_match(size_t row, char& sym) const
{
    const bool first_two_equal = m_cells[row * NUMBER_OF_ROWS] == m_cells[row * NUMBER_OF_ROWS + 1];
    const bool last_two_equal = m_cells[row * NUMBER_OF_ROWS + 1] == m_cells[row * NUMBER_OF_ROWS + 2];
    const bool matched = first_two_equal && last_two_equal;

    if (matched) {
        sym = m_cells[row * NUMBER_OF_ROWS];
    }
    return matched;
}

bool TicTacToe::vertical_match(size_t column, char& sym) const
{
    const bool first_two_equal = m_cells[column] == m_cells[column + NUMBER_OF_ROWS];
    const bool last_two_equal = m_cells[column + NUMBER_OF_ROWS] == m_cells[column + 2 * NUMBER_OF_ROWS];
    const bool matched = first_two_equal && last_two_equal;

    if (matched) {
        sym = m_cells[column];
    }
    return matched;
}

bool TicTacToe::diagonal_match(char& sym) const
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
    const bool rightup_equal_center = m_cells[RIGHT_UP] == m_cells[CENTER];
    const bool leftdown_equal_center = m_cells[CENTER] == m_cells[LEFT_DOWN];
    const bool leftup_equal_center = m_cells[LEFT_UP] == m_cells[CENTER];
    const bool rightdown_equal_center = m_cells[CENTER] == m_cells[RIGHT_DOWN];
    const bool matched = (rightup_equal_center && leftdown_equal_center) || (leftup_equal_center && rightdown_equal_center);
    if (matched) {
        sym = m_cells[CENTER];
    }
    return matched;
}
