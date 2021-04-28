#include "gtest/gtest.h"

#include "game.hpp"

using namespace ::std;

TEST(TestSet, GetPlayerName) {
    std::string expectedPlayerName = "TestPlayer";

    Player player(expectedPlayerName, Game::FIRST_PLAYER_SYMBOL);
    auto playerName = player.getName();

    ASSERT_STREQ(playerName.c_str(), expectedPlayerName.c_str());
}

TEST(TestSet, GetPlayerSymbol) {
    auto expectedPlayerSymbol = Game::FIRST_PLAYER_SYMBOL;

    Player player("TestName", expectedPlayerSymbol);
    auto playerSymbol = player.getSymbol();

    ASSERT_EQ(playerSymbol, expectedPlayerSymbol);
}

TEST(TestSet, MakeCorrectMove) {
    auto expectedPlayerSymbol = Game::FIRST_PLAYER_SYMBOL;
    auto cellIndex = 2;
    auto fieldIndex = cellIndex - 1;
    Game game;
    Player player("test", expectedPlayerSymbol);

    game.makeMove(cellIndex, player);
    auto playerSymbol = game.getField().getCellSymbol(fieldIndex);

    ASSERT_EQ(playerSymbol, expectedPlayerSymbol);
}

TEST(TestSet, MakeIncorrectMove) {
    auto expectedPlayerSymbol = Game::EMPTY_FIELD_SYMBOL;
    auto cellIndex = 0;
    auto fieldIndex = cellIndex - 1;
    Game game;
    Player player("test", Game::FIRST_PLAYER_SYMBOL);

    game.makeMove(cellIndex, player);
    auto playerSymbol = game.getField().getCellSymbol(fieldIndex);

    ASSERT_EQ(playerSymbol, expectedPlayerSymbol);
}
