#include "gtest/gtest.h"
#include "rook.hpp"
#include "figureCommon.hpp"

#include <utility>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(LAB2, RookShouldBeCorrectMove)
{
	FigureCommon *figure = new Rook('B', '0', 0);
	EXPECT_TRUE(figure->move('B', '1'));
}