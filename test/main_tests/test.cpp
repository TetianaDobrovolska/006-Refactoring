#include "ChessFigure.hpp"
#include "ChessFigureTypes.hpp"

#include "gtest/gtest.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(LAB2, RookShouldBeCorrectMove)
{
    ChessFigure *figure = new Rook("E2");
    EXPECT_TRUE(figure->move("C2"));
}

TEST(LAB2, RookShouldBeIncorrectMove)
{
    ChessFigure *figure = new Rook("E2");
    EXPECT_FALSE(figure->move("C5"));
}
TEST(LAB2, KnightShouldBeCorrectMove)
{
    ChessFigure *figure = new Knight("B1");
    EXPECT_TRUE(figure->move("C3"));
}
TEST(LAB2, KnightShouldBeIncorrectMove)
{
    ChessFigure *figure = new Knight("B1");
    EXPECT_FALSE(figure->move("C5"));
}

TEST(LAB2, BishopShouldBeCorrectMove)
{
    ChessFigure *figure = new Bishop("C1");
    EXPECT_TRUE(figure->move("E3"));
}

TEST(LAB2, BishopShouldBeIncorrectMove)
{
    ChessFigure *figure = new Bishop("C1");
    EXPECT_FALSE(figure->move("C3"));
}
TEST(LAB2, PawnShouldBeCorrectMove0)
{
    ChessFigure* figure = new Pawn("E2");
    EXPECT_TRUE(figure->move("E3"));
}

TEST(LAB2, PawnShouldBeCorrectMove1)
{
    ChessFigure *figure = new Pawn("E2");
    EXPECT_TRUE(figure->move("E4"));
}

TEST(LAB2, PawnShouldBeCorrectMove2)
{
    ChessFigure *figure = new Pawn("E4");
    EXPECT_TRUE(figure->move("E5"));
}

TEST(LAB2, PawnShouldBeIncorrectMove)
{
    ChessFigure *figure = new Pawn("E2");
    EXPECT_FALSE(figure->move("C5"));
}
TEST(LAB2, KingShouldBeCorrectMove)
{
    ChessFigure* figure = new King("E1");
    EXPECT_TRUE(figure->move("E2"));
}
TEST(LAB2, KingShouldBeIncorrectMove)
{
    ChessFigure* figure = new King("E1");
    EXPECT_FALSE(figure->move("E8"));
}

TEST(LAB2, QueenShouldBeCorrectMoveVertical)
{
    ChessFigure* figure = new Queen("D1");
    EXPECT_TRUE(figure->move("D8"));
}

TEST(LAB2, QueenShouldBeCorrectMoveDiagonal)
{
    ChessFigure* figure = new Queen("D1");
    EXPECT_TRUE(figure->move("H5"));
}

TEST(LAB2, QueenShouldBeIncorrectMove)
{
    ChessFigure* figure = new Queen("D1");
    EXPECT_FALSE(figure->move("E3"));
}
