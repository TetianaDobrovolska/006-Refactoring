#include "game.hpp"
#include "console_input_output.hpp"

int main(int argc, char** argv)
{
    Game game;

    std::string player1Name;
    std::string player2Name;
    do {
        showEnterFirstPlayerText();
        player1Name = getFirstPlayerName();
        showEnterSecondPlayerText();
        player2Name = getSecondPlayerName();
    } while (!player1Name.compare(player2Name));
    game.createPlayers(player1Name, player2Name);

    game.startGame();

    return 0;
}