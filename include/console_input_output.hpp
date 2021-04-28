#ifndef CONSOLE_INPUT_OUTPUT_HPP
#define CONSOLE_INPUT_OUTPUT_HPP

#include <string>
#include "player.hpp"
#include "field.hpp"

void showEnterFirstPlayerText();

void showEnterSecondPlayerText();

std::string getFirstPlayerName();

std::string getSecondPlayerName();

void showField(const Field&);

void showPlayerMakeMoveText(const Player&);

int getPlayerMove();

void showIncorrectMoveText();

void showResult(const Player&, const Player&);

#endif // !CONSOLE_INPUT_OUTPUT_HPP
