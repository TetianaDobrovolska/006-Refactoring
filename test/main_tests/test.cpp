#include "gtest/gtest.h"
#include "tic_tac_toe.h"
#include <iostream> 
#include <sstream>

using namespace ::std;

TEST(TestSet, Test) {

    ASSERT_TRUE(1);
}

TEST(TestSet, getSetPlayerName) {
    Player p;
    p.setName("player1");
    ASSERT_EQ(p.getName(), "player1");
}

TEST(TestSet, getSetPlayerSign) {
    Player p;
    p.setSign('X');
    ASSERT_EQ(p.getSign(), 'X');
}

TEST(TestSet, Player1WinVerticalTest) {
	auto is = stringstream("1 2 4 3 7");
	auto os = stringstream();
    TicTacToe t("pl1", "pl2", is, os);
	t.play_game();
	string result;
	while(os)
		getline (os,result);
	
    ASSERT_EQ(result, "pl1 you won congratulations pl2 you lose...");
}

TEST(TestSet, Player1WinHorizontalTest) {
	auto is = stringstream("1 4 2 5 3");
	auto os = stringstream();
    TicTacToe t("pl1", "pl2", is, os);
	t.play_game();
	string result;
	while(os)
		getline (os,result);
	
    ASSERT_EQ(result, "pl1 you won congratulations pl2 you lose...");
}

TEST(TestSet, Player1WinDiagTest) {
	auto is = stringstream("1 4 5 3 9");
	auto os = stringstream();
    TicTacToe t("pl1", "pl2", is, os);
	t.play_game();
	string result;
	while(os)
		getline (os,result);
	
    ASSERT_EQ(result, "pl1 you won congratulations pl2 you lose...");
}

TEST(TestSet, Player2WinDiag1Test) {
	auto is = stringstream("2 1 3 5 4 9");
	auto os = stringstream();
    TicTacToe t("pl1", "pl2", is, os);
	t.play_game();
	string result;
	while(os)
		getline (os,result);
	
    ASSERT_EQ(result, "pl2 you won congratulations pl1 you lose...");
}
TEST(TestSet, Player2WinDiag2Test) {
	auto is = stringstream("2 3 1 5 4 7");
	auto os = stringstream();
    TicTacToe t("pl1", "pl2", is, os);
	t.play_game();
	string result;
	while(os)
		getline (os,result);
	
    ASSERT_EQ(result, "pl2 you won congratulations pl1 you lose...");
}

TEST(TestSet, Player2WinVertTest) {
	auto is = stringstream("2 1 3 4 5 7");
	auto os = stringstream();
    TicTacToe t("pl1", "pl2", is, os);
	t.play_game();
	string result;
	while(os)
		getline (os,result);
	
    ASSERT_EQ(result, "pl2 you won congratulations pl1 you lose...");
}

TEST(TestSet, Player2WinHorizTest) {
	auto is = stringstream("4 1 7 2 5 3");
	auto os = stringstream();
    TicTacToe t("pl1", "pl2", is, os);
	t.play_game();
	string result;
	while(os)
		getline (os,result);
	
    ASSERT_EQ(result, "pl2 you won congratulations pl1 you lose...");
}

TEST(TestSet, DrawTest) {
	auto is = stringstream("1 3 2 4 6 5 7 8 9");
	auto os = stringstream();
    TicTacToe t("pl1", "pl2", is, os);
	t.play_game();
	string result;
	while(os)
		getline (os,result);
	
    ASSERT_EQ(result, "Draw");
}

TEST(TestSet, Player1WinVerticalTestNew) {
	TicTacToe t("pl1", "pl2");
    char board[9]{'X','O','O','X','-','-','X','-','-'};
	t.setCells(board);
	char result = t.check();
    ASSERT_EQ(result, 'X');
}

TEST(TestSet, Player1WinHorizontalTestNew) {
    TicTacToe t("pl1", "pl2");
    char board[9]{'X','X','X','O','O','-','-','-','-'};
	t.setCells(board);
	char result = t.check();
    ASSERT_EQ(result, 'X');
}

TEST(TestSet, Player1WinDiagTestNew) {
    TicTacToe t("pl1", "pl2");
    char board[9]{'X','-','O','O','X','-','-','-','X'};
	t.setCells(board);
	char result = t.check();
    ASSERT_EQ(result, 'X');
}

TEST(TestSet, Player2WinDiag1TestNew) {
    TicTacToe t("pl1", "pl2");
    char board[9]{'O','X','X','X','O','-','-','-','O'};
	t.setCells(board);
	char result = t.check();
    ASSERT_EQ(result, 'O');
}

TEST(TestSet, Player2WinDiag2TestNew) {
    TicTacToe t("pl1", "pl2");
    char board[9]{'X','X','O','X','O','-','O','-','-'};
	t.setCells(board);
	char result = t.check();
    ASSERT_EQ(result, 'O');
}

TEST(TestSet, Player2WinVertTestNew) {
    TicTacToe t("pl1", "pl2");
    char board[9]{'O','X','X','O','X','-','O','-','-'};
	t.setCells(board);
	char result = t.check();
    ASSERT_EQ(result, 'O');
}

TEST(TestSet, Player2WinHorizTestNew) {
    TicTacToe t("pl1", "pl2");
    char board[9]{'O','O','O','X','X','-','X','-','-'};
	t.setCells(board);
	char result = t.check();
    ASSERT_EQ(result, 'O');
}

TEST(TestSet, DrawTestNew) {
    TicTacToe t("pl1", "pl2");
    char board[9]{'X','X','O','O','O','X','X','O','X'};
	t.setCells(board);
	char result = t.check();
    ASSERT_EQ(result, '-');
}