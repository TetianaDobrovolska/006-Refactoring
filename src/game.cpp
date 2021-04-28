#include "game.hpp"
#include "console_input_output.hpp"

Game::Game()
{
    win = EMPTY_FIELD_SYMBOL; 
}

Field Game::getField() const
{
    return field;
}

void Game::createPlayers(const std::string& player1Name, const std::string& player2Name)
{
    player1 = Player(player1Name, FIRST_PLAYER_SYMBOL);
    player2 = Player(player2Name, SECOND_PLAYER_SYMBOL);
}

void Game::startGame()
{
    showField(field);
    startGameLoop();
}

void Game::startGameLoop()
{
    static const int maxMoves = 9;
    static const int halfFromMaxMoves = 5;

    for (int move = 1; move <= maxMoves; ++move)
    {
        if (move % 2)
        {
            TryToMove(player1);
        }
        else {
            TryToMove(player2);
        }

        showField(field);

        if (move >= halfFromMaxMoves)
        {
            win = field.check();
            if (win != EMPTY_FIELD_SYMBOL)
            {
                break;
            }
        }
    }
    result();
}

void Game::TryToMove(const Player& player)
{
    static const int minCellIndex = 1;
    static const int maxCellIndex = 9;

    showPlayerMakeMoveText(player);
    int cell = getPlayerMove();

    while (maxCellIndex < cell ||
        cell < minCellIndex ||
        field.getCellSymbol(cell - 1) == player1.getSymbol() ||
        field.getCellSymbol(cell - 1) == player2.getSymbol())
    {
        showIncorrectMoveText();
        cell = getPlayerMove();
    }

    makeMove(cell, player);
}

void Game::makeMove(const int cell, const Player& player)
{
    field.setCellSymbol(cell - 1, player.getSymbol());
}

void Game::result()
{
    if (win == player1.getSymbol())
    {
        showResult(player1, player2);
    }
    else if (win == player2.getSymbol())
    {
        showResult(player2, player1);
    }
}
