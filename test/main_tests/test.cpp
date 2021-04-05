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

TEST(TestChessMove, EmptyMoveString)
{
    ChessFigure *figure = new Pawn("E2");
    ChessFigure::TargetMove targetMove = {"", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, ShortMoveString)
{
    ChessFigure *figure = new Pawn("E2");
    ChessFigure::TargetMove targetMove = {"A", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, PawnIncorrectString)
{
    ChessFigure *figure = new Pawn("E2");
    ChessFigure::TargetMove targetMove = {"X9", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, BishopIncorrectString)
{
    ChessFigure *figure = new Bishop("E2");
    ChessFigure::TargetMove targetMove = {"X9", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, KnightIncorrectString)
{
    ChessFigure *figure = new Knight("E2");
    ChessFigure::TargetMove targetMove = {"X9", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, RookIncorrectString)
{
    ChessFigure *figure = new Rook("E2");
    ChessFigure::TargetMove targetMove = {"X9", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, QueenIncorrectString)
{
    ChessFigure *figure = new Queen("E2");
    ChessFigure::TargetMove targetMove = {"X9", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, KingIncorrectString)
{
    ChessFigure *figure = new King("E2");
    ChessFigure::TargetMove targetMove = {"X9", false, false, false, false, false};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, PawnPinned)
{
    ChessFigure *figure = new Pawn("E2");
    ChessFigure::TargetMove targetMove = {"E3", false, false, false, false, true};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, Pawn1UpBlocked1)
{
    ChessFigure *figure = new Pawn("E2");
    ChessFigure::TargetMove targetMove = {"E3", true, false, false, false, true};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, Pawn1UpBlocked2)
{
    ChessFigure *figure = new Pawn("E2");
    ChessFigure::TargetMove targetMove = {"E3", false, true, false, false, true};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, Pawn2UpBlocked1)
{
    ChessFigure *figure = new Pawn("E2");
    ChessFigure::TargetMove targetMove = {"E4", true, false, false, false, true};
    EXPECT_FALSE(figure->move(targetMove));
}

TEST(TestChessMove, Pawn2UpBlocked2)
{
    ChessFigure *figure = new Pawn("E2");
    ChessFigure::TargetMove targetMove = {"E4", false, true, false, false, true};
    EXPECT_FALSE(figure->move(targetMove));
}
