#include "gtest/gtest.h"
#include "tictactoe.h"

using namespace ::std;

TEST(TestSet, Test) {

    ASSERT_TRUE(1);
}

TEST(TestSet, checkInitial) {
    TicTacToe game;
    const auto expected = '-';
    const auto actual = game.check();
    ASSERT_EQ(actual, expected);
}

TEST(TestSet, customPlayer1Name) {
    const string expected { "Peter" };
    TicTacToe game(expected);
    const auto actual = game.get_player_name1();
    ASSERT_EQ(actual, expected);
}

TEST(TestSet, customPlayer2Name) {
    const string expected { "Ellie" };
    TicTacToe game("Nick", expected);
    const auto actual = game.get_player_name2();
    ASSERT_EQ(actual, expected);
}

class TicTacToeTest : public testing::Test
{
protected:
    TicTacToe game;
    ~TicTacToeTest() override;
};

TicTacToeTest::~TicTacToeTest()
{
}

class CellNumberTest : public TicTacToeTest, public testing::WithParamInterface< tuple<size_t, bool> >
{
public:
    ~CellNumberTest() override;
};

CellNumberTest::~CellNumberTest()
{
}

class CellMoveTest : public TicTacToeTest, public testing::WithParamInterface< tuple<size_t, bool> >
{
public:
    ~CellMoveTest() override;
};

CellMoveTest::~CellMoveTest()
{
}

class GameTest : public TicTacToeTest, public testing::WithParamInterface< tuple<vector<size_t>, bool> >
{
public:
    ~GameTest() override;
};

GameTest::~GameTest()
{
}

TEST_P(CellNumberTest, CellNumberTest) {
    const auto argument = std::get<0>(GetParam());
    const auto expected = std::get<1>(GetParam());
    const auto actual = game.check_cell(argument);
    ASSERT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(TicTacToeCellSuite, CellNumberTest,
                         testing::Values(
                             make_tuple(0, false),
                             make_tuple(-1, false),
                             make_tuple(1, true),
                             make_tuple(5, true),
                             make_tuple(9, true),
                             make_tuple(10, false)
                             ));

TEST_F(TicTacToeTest, TestDefaultPlayer1Name) {
    const string expected {"Player1"};
    const string actual = game.get_player_name1();
    ASSERT_EQ(actual, expected);
}

TEST_F(TicTacToeTest, TestDefaultPlayer2Name) {
    const string expected {"Player2"};
    const string actual = game.get_player_name2();
    ASSERT_EQ(actual, expected);
}

TEST_F(TicTacToeTest, MoveToOccupiedCell) {
    int player_num = 1;
    const size_t cell = 5;
    game.make_move(player_num, cell);
    EXPECT_THROW(game.make_move(player_num, cell), out_of_range);
    player_num = 2;
    EXPECT_THROW(game.make_move(player_num, cell), out_of_range);
}

TEST_P(CellMoveTest, TicTacToeTestMove) {
    const auto cell = std::get<0>(GetParam());
    const auto player1 = std::get<1>(GetParam());
    const int player_num = player1 ? 1 : 2;
    if (!game.check_cell(cell)) {
        EXPECT_THROW(game.make_move(player_num, cell), out_of_range);
    } else {
        game.make_move(player_num, cell);
        const auto expected = player1 ? 'X' : 'O';
        const auto actual = game.get_cells().at(cell-1);
        ASSERT_EQ(expected, actual);
    }
}

INSTANTIATE_TEST_SUITE_P(TicTacToeCellSuite, CellMoveTest,
                         testing::Values(
                             make_tuple(0, false),
                             make_tuple(-1, true),
                             make_tuple(1, true),
                             make_tuple(2, false),
                             make_tuple(3, false),
                             make_tuple(4, false),
                             make_tuple(5, true),
                             make_tuple(6, true),
                             make_tuple(7, true),
                             make_tuple(8, false),
                             make_tuple(9, true),
                             make_tuple(10, false)
                             ));

TEST_P(GameTest, TicTacToeTestGame) {
    int player = 1;
    for (const auto value : std::get<0>(GetParam())) {
        game.make_move(player, value);
        player = 1 - player;
    }
    const auto expected = std::get<1>(GetParam());
    const bool actual = 'X' == game.check();
    ASSERT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(TicTacToeSuite, GameTest,
                         testing::Values(
                             make_tuple(vector<size_t>{5,6,7,8}, false),
                             make_tuple(vector<size_t>{5,1,3,7,4,6,2,8,9}, false),
                             make_tuple(vector<size_t>{1,5,2,4,3}, true),
                             make_tuple(vector<size_t>{1,2,3,4,5,6,7,8,9}, true),
                             make_tuple(vector<size_t>{2,1,3,4,5,7,6,8,9}, false)
                             ));
