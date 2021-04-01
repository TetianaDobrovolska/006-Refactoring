#include "ChessFigure.hpp"
#include "ChessFigureTypes.hpp"

#include "gtest/gtest.h"

TEST(TestChessMove, RookShouldBeCorrectMove)
{
    ChessFigure *figure = new Rook("E2");
    ChessFigure::TargetMove targetMove = {"C2", false, false, false, false, false};
    EXPECT_TRUE(figure->move(targetMove));
}

TEST(TestChessMove, RookShouldBeIncorrectMove)
{
    ChessFigure *figure = new Rook("E2");
    ChessFigure::TargetMove targetMove = {"C5", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}
TEST(TestChessMove, KnightShouldBeCorrectMove)
{
    ChessFigure *figure = new Knight("B1");
    ChessFigure::TargetMove targetMove = {"C3", false, false, false, false, false};
    EXPECT_TRUE(figure->move(targetMove));
}
TEST(TestChessMove, KnightShouldBeIncorrectMove)
{
    ChessFigure *figure = new Knight("B1");
    ChessFigure::TargetMove targetMove = {"C5", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, BishopShouldBeCorrectMove)
{
    ChessFigure *figure = new Bishop("C1");
    ChessFigure::TargetMove targetMove = {"E3", false, false, false, false, false};
    EXPECT_TRUE(figure->move(targetMove));
}

TEST(TestChessMove, BishopShouldBeIncorrectMove)
{
    ChessFigure *figure = new Bishop("C1");
    ChessFigure::TargetMove targetMove = {"C3", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}
TEST(TestChessMove, PawnShouldBeCorrectMove0)
{
    ChessFigure* figure = new Pawn("E2");
    ChessFigure::TargetMove targetMove = {"E3", false, false, false, false, false};
    EXPECT_TRUE(figure->move(targetMove));
}

TEST(TestChessMove, PawnShouldBeCorrectMove1)
{
    ChessFigure *figure = new Pawn("E2");
    ChessFigure::TargetMove targetMove = {"E4", false, false, false, false, false};
    EXPECT_TRUE(figure->move(targetMove));
}

TEST(TestChessMove, PawnShouldBeCorrectMove2)
{
    ChessFigure *figure = new Pawn("E4");
    ChessFigure::TargetMove targetMove = {"E5", false, false, false, false, false};
    EXPECT_TRUE(figure->move(targetMove));
}

TEST(TestChessMove, PawnShouldBeIncorrectMove)
{
    ChessFigure *figure = new Pawn("E2");
    ChessFigure::TargetMove targetMove = {"C5", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}
TEST(TestChessMove, KingShouldBeCorrectMove)
{
    ChessFigure* figure = new King("E1");
    ChessFigure::TargetMove targetMove = {"E2", false, false, false, false, false};
    EXPECT_TRUE(figure->move(targetMove));
}
TEST(TestChessMove, KingShouldBeIncorrectMove)
{
    ChessFigure* figure = new King("E1");
    ChessFigure::TargetMove targetMove = {"E8", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, QueenShouldBeCorrectMoveVertical)
{
    ChessFigure* figure = new Queen("D1");
    ChessFigure::TargetMove targetMove = {"D8", false, false, false, false, false};
    EXPECT_TRUE(figure->move(targetMove));
}

TEST(TestChessMove, QueenShouldBeCorrectMoveDiagonal)
{
    ChessFigure* figure = new Queen("D1");
    ChessFigure::TargetMove targetMove = {"H5", false, false, false, false, false};
    EXPECT_TRUE(figure->move(targetMove));
}

TEST(TestChessMove, QueenShouldBeIncorrectMove)
{
    ChessFigure* figure = new Queen("D1");
    ChessFigure::TargetMove targetMove = {"E3", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}
