#include "gtest/gtest.h"
#include "players.hpp"
#include "field.hpp"
#include "controller.hpp"

#include <string>
#include <iostream>

Field f;
Controller c;

TEST(TestSet, Test) {
    ASSERT_TRUE(1);
}

TEST(TestSet, SetPlayerName) {
    c.setNames();
    std::string actual = c.getName('X');
    EXPECT_EQ(actual, "name");
}

TEST(TestSet, FirstPlayerName) {
    std::string actual = c.getName('X');
    EXPECT_EQ(actual, "name");
}

TEST(TestSet, SecondPlayerName) {
    std::string actual = c.getName('O');
    EXPECT_EQ(actual, "name2");
}

TEST(TestSet, TurnChecking) {
    char actual = c.getTurn();
    EXPECT_EQ(actual, 'X');
}

TEST(TestSet, SetCellState) {
    f.setCellState('O', 2);
    std::vector<char> actual = f.getCellsState();
    EXPECT_EQ(actual[2], 'O');
}

TEST(TestSet, fieldShowing) {
    f.showCells();
    int actual = 1;
    EXPECT_EQ(actual, 1);
}

TEST(TestSet, MakeMove) {
    c.makeMove();
    int actual = 1;
    EXPECT_EQ(actual, 1);
}

TEST(TestSet, CheckWinner) {
    char actual = c.checkWinner();
    EXPECT_EQ(actual, '-');
}

TEST(TestSet, CheckWinnerPlayerX) {
    for (int i = 0; i < 5; i++) c.makeMove();
    char actual = c.checkWinner();
    EXPECT_EQ(actual, 'X');
}

TEST(TestSet, CheckWinnerPlayerO) {
    c.newSession();
    for (int i = 0; i < 5; i++) c.makeMove();
    char actual = c.checkWinner();
    EXPECT_EQ(actual, 'O');
}

TEST(TestSet, CheckWin) {
    c.newSession();
    for (int i = 0; i < 5; i++) c.makeMove(); c.isWin();
    bool actual = c.isWin();
    EXPECT_EQ(actual, true);
}