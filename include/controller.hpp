#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "players.hpp"
#include "field.hpp"
#include <vector>
#include <utility>

class Controller
{
public:
	Controller();
	~Controller();
	
    void setNames();
    std::string getName(const char &pict);
	void makeMove();
    const char getTurn();
    const char checkWinner();
    void newSession();
    bool isWin();
private:
    Players m_players;
    Field m_field;
    const int m_userInput();
};

#endif