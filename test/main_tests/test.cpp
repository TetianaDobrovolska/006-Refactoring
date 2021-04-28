#include "ChessFigure.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "pawn.hpp"
#include "queen.hpp"
#include "king.hpp"

#include "gtest/gtest.h"
#include <memory>

TEST(LAB2, RookShouldBeCorrectMove)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Rook>(new Rook("E2"));
    EXPECT_TRUE(figure->Move("C2"));
}

TEST(LAB2, RookShouldBeIncorrectMove)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Rook>(new Rook("E2"));
    EXPECT_FALSE(figure->Move("C5"));
}
TEST(LAB2, KnightShouldBeCorrectMove)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Knight>(new Knight("B1"));
	EXPECT_TRUE(figure->Move("C3"));
}
TEST(LAB2, KnightShouldBeIncorrectMove)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Knight>(new Knight("B1"));
	EXPECT_FALSE(figure->Move("C5"));
}

TEST(LAB2, BishopShouldBeCorrectMove)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Bishop>(new Bishop("C1"));
	EXPECT_TRUE(figure->Move("E3"));
}

TEST(LAB2, BishopShouldBeIncorrectMove)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Bishop>(new Bishop("C1"));
	EXPECT_FALSE(figure->Move("C3"));
}
TEST(LAB2, PawnShouldBeCorrectMove0)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Pawn>(new Pawn("E2"));
	EXPECT_TRUE(figure->Move("E3"));
}

TEST(LAB2, PawnShouldBeCorrectMove1)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Pawn>(new Pawn("E2"));
    EXPECT_TRUE(figure->Move("E3"));
}

TEST(LAB2, PawnShouldBeCorrectMove2)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Pawn>(new Pawn("E4"));
	EXPECT_TRUE(figure->Move("E5"));
}

TEST(LAB2, PawnShouldBeIncorrectMove)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Pawn>(new Pawn("E2"));
	EXPECT_FALSE(figure->Move("C5"));
}
TEST(LAB2, KingShouldBeCorrectMove)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<King>(new King("E1"));
	EXPECT_TRUE(figure->Move("E2"));
}
TEST(LAB2, KingShouldBeIncorrectMove)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<King>(new King("E1"));
	EXPECT_FALSE(figure->Move("E8"));
}

TEST(LAB2, QueenShouldBeCorrectMoveVertical)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Queen>(new Queen("D1"));
	EXPECT_TRUE(figure->Move("D8"));
}

TEST(LAB2, QueenShouldBeCorrectMoveDiagonal)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Queen>(new Queen("D1"));
    EXPECT_TRUE(figure->Move("H5"));
}

TEST(LAB2, QueenShouldBeIncorrectMove)
{
    std::unique_ptr<ChessFigure> figure = std::unique_ptr<Queen>(new Queen("D1"));
	EXPECT_FALSE(figure->Move("E3"));
}
