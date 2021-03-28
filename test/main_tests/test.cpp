#include "gtest/gtest.h"
#include "tictactoe.h"

using namespace ::std;

TEST(TestSet, Test) {

    ASSERT_TRUE(1);
}

TEST(TestSet, checkInitial) {
    TicTacToe game;
    auto expected = '-';
    auto actual = game.check();
    ASSERT_EQ(actual, expected);
}
