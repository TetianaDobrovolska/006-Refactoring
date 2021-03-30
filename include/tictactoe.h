#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <string>

class TicTacToe
{
public:
    TicTacToe(const std::string& player1 = "Player1", const std::string& player2 = "Player2");
    ~TicTacToe();

    enum player_code {
        DRAW,
        PLAYER1,
        PLAYER2
    };

    bool check_cell(const size_t cell) const;
    void make_move(const size_t cell);

    player_code winner() const;

    const std::vector<char>& get_cells() const;
    const std::string& get_player_name1() const;
    const std::string& get_player_name2() const;
    const std::string& get_current_player_name() const;

    static constexpr size_t NUMBER_OF_ROWS = 3;
    static constexpr size_t NUMBER_OF_CELLS = NUMBER_OF_ROWS * NUMBER_OF_ROWS;
    static const std::vector<char> player_sign;

private:
    std::string m_player_name1, m_player_name2;
    std::vector<char> m_cells;
    player_code current_player = PLAYER1;

    char check() const;
    void switch_player();
    bool horizontal_match(const size_t row, char& sym) const;
    bool vertical_match(const size_t column, char& sym) const;
    bool diagonal_match(char& sym) const;
};

#endif // TICTACTOE_H
