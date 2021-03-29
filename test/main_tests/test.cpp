#include "gtest/gtest.h"
#include "tictactoe.h"

using namespace ::std;

TEST(TestSet, Test) {

    ASSERT_TRUE(1);
}

TEST(TestSet, checkInitial) {
    TicTacToe game;
    const auto expected = TicTacToe::DRAW;
    const auto actual = game.winner();
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

class CellMoveTest : public TicTacToeTest, public testing::WithParamInterface< tuple<size_t, TicTacToe::player_code> >
{
public:
    ~CellMoveTest() override;
};

CellMoveTest::~CellMoveTest()
{
}

class GameTest : public TicTacToeTest, public testing::WithParamInterface< tuple<vector<size_t>, TicTacToe::player_code> >
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
    const size_t cell = 5;
    game.make_move(cell);
    EXPECT_THROW(game.make_move(cell), out_of_range);
}

TEST_P(CellMoveTest, TicTacToeTestMove) {
    const auto cell = std::get<0>(GetParam());
    const auto player = std::get<1>(GetParam());
    if (!game.check_cell(cell)) {
        EXPECT_THROW(game.make_move(cell), out_of_range);
    } else {
        if (player != TicTacToe::PLAYER1) {
            game.make_move(TicTacToe::NUMBER_OF_CELLS - cell);
        }
        game.make_move(cell);
        const auto expected = TicTacToe::player_sign[player];
        const auto actual = game.get_cells().at(cell-1);
        ASSERT_EQ(expected, actual);
    }
}

INSTANTIATE_TEST_SUITE_P(TicTacToeCellSuite, CellMoveTest,
                         testing::Values(
                             make_tuple(0, TicTacToe::PLAYER2),
                             make_tuple(-1, TicTacToe::PLAYER1),
                             make_tuple(1, TicTacToe::PLAYER1),
                             make_tuple(2, TicTacToe::PLAYER2),
                             make_tuple(3, TicTacToe::PLAYER2),
                             make_tuple(4, TicTacToe::PLAYER2),
                             make_tuple(5, TicTacToe::PLAYER1),
                             make_tuple(6, TicTacToe::PLAYER1),
                             make_tuple(7, TicTacToe::PLAYER1),
                             make_tuple(8, TicTacToe::PLAYER2),
                             make_tuple(9, TicTacToe::PLAYER1),
                             make_tuple(10, TicTacToe::PLAYER2)
                             ));

TEST_P(GameTest, TicTacToeTestGame) {
    for (const auto value : std::get<0>(GetParam())) {
        game.make_move(value);
    }

    const auto winner = std::get<1>(GetParam());
    const auto actual = game.winner();
    ASSERT_EQ(winner, actual);
}

INSTANTIATE_TEST_SUITE_P(TicTacToeSuite, GameTest,
                         testing::Values(
                             make_tuple(vector<size_t>{5,6,7,8}, TicTacToe::DRAW),
                             make_tuple(vector<size_t>{5,1,3,7,4,6,2,8,9}, TicTacToe::DRAW),
                             make_tuple(vector<size_t>{1,5,2,4,3}, TicTacToe::PLAYER1),
                             make_tuple(vector<size_t>{1,2,3,4,5,6,7,8,9}, TicTacToe::PLAYER1),
                             make_tuple(vector<size_t>{2,1,3,4,5,7,6,8,9}, TicTacToe::PLAYER2),
                             make_tuple(vector<size_t>{1,2,3,4,5}, TicTacToe::DRAW)
                             ));
