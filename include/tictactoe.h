#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <string>

class TicTacToe
{
public:
    TicTacToe(const std::string& player1 = "Player1", const std::string& player2 = "Player2");
    ~TicTacToe();

    void show_cells();
    bool check_cell(size_t cell);
    void make_move(int num, size_t cell);
    char check();
    void result();


    const std::vector<char>& get_cells() const;
    const std::string& get_player_name1() const;
    const std::string& get_player_name2() const;

    char win = '-';

private:
    std::string m_player_name1, m_player_name2;
    std::vector<char> m_cells = { '-','-','-','-','-','-','-','-','-' };
};

#endif // TICTACTOE_H
