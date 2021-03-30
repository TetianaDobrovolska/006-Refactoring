#pragma once

#include "player.h"

#include <vector>

class TicTacToe
{
public:
    TicTacToe(const std::string& player1 = "Player1", const std::string& player2 = "Player2");
    ~TicTacToe();

    bool check_cell(const size_t cell) const;
    void make_move(const size_t cell);

    const tictactoe::IPlayer& winner() const;

    const std::vector<char>& get_cells() const;
    const std::string& get_player_name1() const;
    const std::string& get_player_name2() const;
    const std::string& get_current_player_name() const;

    static constexpr size_t NUMBER_OF_ROWS = 3;
    static constexpr size_t NUMBER_OF_CELLS = NUMBER_OF_ROWS * NUMBER_OF_ROWS;
    static const std::vector<char> player_sign;

private:
    const std::vector<tictactoe::IPlayer*> m_players;
    const tictactoe::IPlayer* m_current_player;
    std::vector<char> m_cells;

    char check() const;
    void switch_player();
    bool horizontal_match(const size_t row, char& sym) const;
    bool vertical_match(const size_t column, char& sym) const;
    bool diagonal_match(char& sym) const;
};
