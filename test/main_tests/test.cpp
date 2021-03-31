#include "ChessFigure.hpp"
#include "gtest/gtest.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(LAB2, RookShouldBeCorrectMove)
{
    ChessFigure *figure = new RookFigure("E2");
    EXPECT_TRUE(figure->Move("C2"));
}

TEST(LAB2, RookShouldBeIncorrectMove)
{
    ChessFigure *figure = new RookFigure("E2");
    EXPECT_FALSE(figure->Move("C5"));
}
TEST(LAB2, KnightShouldBeCorrectMove)
{
    ChessFigure *figure = new KnightFigure("B1");
    EXPECT_TRUE(figure->Move("C3"));
}
TEST(LAB2, KnightShouldBeIncorrectMove)
{
    ChessFigure *figure = new KnightFigure("B1");
    EXPECT_FALSE(figure->Move("C5"));
}

TEST(LAB2, BishopShouldBeCorrectMove)
{
    ChessFigure *figure = new BishopFigure("C1");
	EXPECT_TRUE(figure->Move("E3"));
}

TEST(LAB2, BishopShouldBeIncorrectMove)
{
    ChessFigure *figure = new BishopFigure("C1");
	EXPECT_FALSE(figure->Move("C3"));
}
TEST(LAB2, PawnShouldBeCorrectMove0)
{
    ChessFigure* figure = new PawnFigure("E2");
    EXPECT_TRUE(figure->Move("E3"));
}

TEST(LAB2, PawnShouldBeCorrectMove1)
{
    ChessFigure *figure = new PawnFigure("E2");
    EXPECT_TRUE(figure->Move("E4"));
}

TEST(LAB2, PawnShouldBeCorrectMove2)
{
    ChessFigure *figure = new PawnFigure("E4");
    EXPECT_TRUE(figure->Move("E5"));
}

TEST(LAB2, PawnShouldBeIncorrectMove)
{
    ChessFigure *figure = new PawnFigure("E2");
    EXPECT_FALSE(figure->Move("C5"));
}
TEST(LAB2, KingShouldBeCorrectMove)
{
    ChessFigure* figure = new KingFigure("E1");
    EXPECT_TRUE(figure->Move("E2"));
}
TEST(LAB2, KingShouldBeIncorrectMove)
{
    ChessFigure* figure = new KingFigure("E1");
    EXPECT_FALSE(figure->Move("E8"));
}

TEST(LAB2, QueenShouldBeCorrectMoveVertical)
{
    ChessFigure* figure = new QueenFigure("D1");
    EXPECT_TRUE(figure->Move("D8"));
}

TEST(LAB2, QueenShouldBeCorrectMoveDiagonal)
{
    ChessFigure* figure = new QueenFigure("D1");
    EXPECT_TRUE(figure->Move("H5"));
}

TEST(LAB2, QueenShouldBeIncorrectMove)
{
    ChessFigure* figure = new QueenFigure("D1");
    EXPECT_FALSE(figure->Move("E3"));
}
