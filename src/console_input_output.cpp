#include "console_input_output.hpp"

#include <iostream>

void showEnterFirstPlayerText()
{
	std::cout << "Enter the name of the first player: ";
}

void showEnterSecondPlayerText()
{
	std::cout << "Enter the name of the second player: ";
}

std::string getFirstPlayerName()
{
	std::string playerName;
	std::cin >> playerName;
	return playerName;
}

std::string getSecondPlayerName()
{
	std::string playerName;
	std::cin >> playerName;
	return playerName;
}

void showField(const Field& field)
{
#ifdef __linux__
    system("clear");
#else
    system("cls");
#endif

    std::cout << "Cell numbers: \n";
    for (auto i = 1; i < 10; ++i)
    {
        std::cout << "-" << i << "-";
        if (i % 3 != 0)
        {
            std::cout << "|";
        }
        else {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;

    std::cout << "Current situation (--- empty):\n";
    for (auto i = 1; i < 10; ++i)
    {
        std::cout << "-" << field.getCellSymbol(i - 1) << "-";
        if (i % 3 != 0)
        {
            std::cout << "|";
        }
        else {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}

void showPlayerMakeMoveText(const Player& player)
{
    std::cout << player.getName() << ", enter cell number, make your move:" << std::endl;
}

int getPlayerMove()
{
    int move;
    std::cin >> move;
    return move;
}

void showIncorrectMoveText()
{
    std::cout << "Enter the number of the correct (1-9) or empty (---) cells to make a move:" << std::endl;
}

void showResult(const Player& winner, const Player& loser)
{
	std::cout << winner.getName() << " congratulations, you won! " << loser.getName() << " you lose..." << std::endl;
}