#include "gtest/gtest.h"
#include "tic_tac_toe.h"

TEST(TestSet, Test) {

    ASSERT_TRUE(1);
}

TEST(TestSet, CheckName) {
    TicTacToe game("Alexa", "Ben");

    ASSERT_STREQ("Alexa", game.getFirstPlayer());
    ASSERT_STREQ("Ben", game.getSecondPlayer());
}

TEST(Test, CheckCorrectMovement1)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_TRUE(game.make_move(1, 5));
    ASSERT_EQ('X', game.getCellByIndex(5));
}

TEST(Test, CheckCorrectMovement2)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_TRUE(game.make_move(2, 5));
    ASSERT_EQ('O', game.getCellByIndex(5));
}

TEST(Test, MoveOutOfRange)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_FALSE(game.make_move(1, 10));
}

TEST(Test, MoveOutOfRange2)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_FALSE(game.make_move(1, 0));
}

TEST(Test, DuplicateMovement)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_TRUE(game.make_move(1, 1));
    ASSERT_EQ('X', game.getCellByIndex(1));

    ASSERT_FALSE(game.make_move(2, 1));
}

TEST(Test, DuplicateMovement2)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_TRUE(game.make_move(2, 2));
    ASSERT_EQ('O', game.getCellByIndex(2));

    ASSERT_FALSE(game.make_move(1, 2));
}

TEST(Test, FirstLineWinner)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_TRUE(game.make_move(1, 1));
    ASSERT_EQ('X', game.getCellByIndex(1));

    ASSERT_TRUE(game.make_move(1, 2));
    ASSERT_EQ('X', game.getCellByIndex(2));

    ASSERT_TRUE(game.make_move(1, 3));
    ASSERT_EQ('X', game.getCellByIndex(3));

    ASSERT_EQ('X', game.check_winner());
}

TEST(Test, SecondLineWinner)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_TRUE(game.make_move(1, 4));
    ASSERT_EQ('X', game.getCellByIndex(4));

    ASSERT_TRUE(game.make_move(1, 5));
    ASSERT_EQ('X', game.getCellByIndex(5));

    ASSERT_TRUE(game.make_move(1, 6));
    ASSERT_EQ('X', game.getCellByIndex(6));

    ASSERT_EQ('X', game.check_winner());
}

TEST(Test, ThirdLineWinner)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_TRUE(game.make_move(1, 7));
    ASSERT_EQ('X', game.getCellByIndex(7));

    ASSERT_TRUE(game.make_move(1, 8));
    ASSERT_EQ('X', game.getCellByIndex(8));

    ASSERT_TRUE(game.make_move(1, 9));
    ASSERT_EQ('X', game.getCellByIndex(9));

    ASSERT_EQ('X', game.check_winner());
}

TEST(Test, FirstRowWinner)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_TRUE(game.make_move(2, 1));
    ASSERT_EQ('O', game.getCellByIndex(1));

    ASSERT_TRUE(game.make_move(2, 4));
    ASSERT_EQ('O', game.getCellByIndex(4));

    ASSERT_TRUE(game.make_move(2, 7));
    ASSERT_EQ('O', game.getCellByIndex(7));

    ASSERT_EQ('O', game.check_winner());
}

TEST(Test, SecondRowWinner)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_TRUE(game.make_move(2, 2));
    ASSERT_EQ('O', game.getCellByIndex(2));

    ASSERT_TRUE(game.make_move(2, 5));
    ASSERT_EQ('O', game.getCellByIndex(5));

    ASSERT_TRUE(game.make_move(2, 8));
    ASSERT_EQ('O', game.getCellByIndex(8));

    ASSERT_EQ('O', game.check_winner());
}

TEST(Test, ThirdRowWinner)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_TRUE(game.make_move(2, 3));
    ASSERT_EQ('O', game.getCellByIndex(3));

    ASSERT_TRUE(game.make_move(2, 6));
    ASSERT_EQ('O', game.getCellByIndex(6));

    ASSERT_TRUE(game.make_move(2, 9));
    ASSERT_EQ('O', game.getCellByIndex(9));

    ASSERT_EQ('O', game.check_winner());
}

TEST(Test, RightDiagWinner)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_TRUE(game.make_move(2, 1));
    ASSERT_EQ('O', game.getCellByIndex(1));

    ASSERT_TRUE(game.make_move(2, 5));
    ASSERT_EQ('O', game.getCellByIndex(5));

    ASSERT_TRUE(game.make_move(2, 9));
    ASSERT_EQ('O', game.getCellByIndex(9));

    ASSERT_EQ('O', game.check_winner());
}

TEST(Test, LeftDiagWinner)
{
    TicTacToe game("Alexa", "Ben");

    ASSERT_TRUE(game.make_move(1, 3));
    ASSERT_EQ('X', game.getCellByIndex(3));

    ASSERT_TRUE(game.make_move(1, 5));
    ASSERT_EQ('X', game.getCellByIndex(5));

    ASSERT_TRUE(game.make_move(1, 7));
    ASSERT_EQ('X', game.getCellByIndex(7));

    ASSERT_EQ('X', game.check_winner());
}
