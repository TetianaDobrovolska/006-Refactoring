#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <string>

class TicTacToe
{
public:
    TicTacToe(const std::string& player1 = "Player1", const std::string& player2 = "Player2");
    ~TicTacToe();

    bool check_cell(size_t cell) const;
    void make_move(int num, size_t cell);
    char check();

    const std::vector<char>& get_cells() const;
    const std::string& get_player_name1() const;
    const std::string& get_player_name2() const;

private:

    std::string m_player_name1, m_player_name2;
    std::vector<char> m_cells;
};

#endif // TICTACTOE_H
