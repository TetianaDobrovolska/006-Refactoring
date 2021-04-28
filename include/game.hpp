#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "field.hpp"

class Game
{
public:
	const static char FIRST_PLAYER_SYMBOL = 'X';
	const static char SECOND_PLAYER_SYMBOL = 'O';
	const static char EMPTY_FIELD_SYMBOL = '-';
	Game();
	void startGame();
	Field getField() const;
	void startGameLoop();
	void createPlayers(const std::string&, const std::string&);
	void TryToMove(const Player&);
	void makeMove(const int, const Player&);
	void result();
private:
	Player player1;
	Player player2;
	Field field;
	char win;
};

#endif // !GAME_HPP
