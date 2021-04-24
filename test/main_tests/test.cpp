#include "gtest/gtest.h"
#include "tic_tac_toe.hpp"

using namespace ::std;

TEST(TestSet, Test) {

    ASSERT_TRUE(1);
}


TEST(TestSet, getSetWin) {
    TicTacToe t;
    t.setWin('X');
    ASSERT_EQ(t.getWin(), 'X');
}
TEST(TestSet, getSetPlayerName) {
    TicTacToe t;
    t.setPlayerName("Vasya",1);
    ASSERT_EQ(t.getPlayerName(1), "Vasya");
}
TEST(TestSet, getSetCellValue) {
    TicTacToe t;
    t.setCellValue('X',5);
    ASSERT_EQ(t.getCellValue(5), 'X');
}
/*

TEST(TestSet, getMoverIndex) {
    TicTacToe t;
    int value = t.getMoverIndex(5);
    ASSERT_EQ(value, 1);
}

TEST(TestSet, getMoverIndex) {
    TicTacToe t;
    int value = t.getMoverIndex(4);
    ASSERT_EQ(value, 2);
}
*/
