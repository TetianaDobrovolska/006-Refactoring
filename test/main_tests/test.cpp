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

class CellNumberTest : public testing::TestWithParam < std::tuple<size_t, bool> >
{
public:
    ~CellNumberTest() override;
};

CellNumberTest::~CellNumberTest()
{
}

TEST_P(CellNumberTest, CellNumberTest) {
    auto argument = std::get<0>(GetParam());
    auto expected = std::get<1>(GetParam());
    TicTacToe game;
    auto actual = game.check_cell(argument);
    ASSERT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(TicTacToeCellSuite, CellNumberTest,
                         testing::Values(
                             std::make_tuple(0, false),
                             std::make_tuple(-1, false),
                             std::make_tuple(1, true),
                             std::make_tuple(5, true),
                             std::make_tuple(9, true),
                             std::make_tuple(10, false)
                             ));
