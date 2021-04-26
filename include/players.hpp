#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include <utility>
#include <string>
#include <vector>

class Players
{
public:
	Players();
	~Players();

    std::vector<std::pair<std::string, const char>> getPlayers();
    void setPlayerName(const int &playerNumber, const char &pict, const std::string &name);
    std::string getPlayerName(const char &pict);
    const char getTurn();
    void changeTurn();
private:
    std::pair<std::string, const char> m_playerOne {"", 'X'};
    std::pair<std::string, const char> m_playerTwo {"", 'O'};
    std::vector<std::pair<std::string, const char>> m_players {m_playerOne, m_playerTwo};
    char m_turn = m_playerOne.second;

    std::pair<std::string, const char> m_getPlayer(const char &pict);
    char m_setTurn(const char &pict);
};

#endif