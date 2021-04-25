#pragma once

#include <iostream> 
#include <cstring> 
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Player{
	public:
	void setName(const string& name){m_name = name;}
	string getName(){return m_name;}
	
	void setSign(const char sign){m_sign = sign;}
	char getSign(){return m_sign;}
	
	private:
	string m_name;
	char m_sign;
};

class TicTacToe{
	private:
	static const int PLAYERS_COUNT = 2;
	static const int BOARD_SIZE = 3;
	static const int BOARD_FULL_SIZE = BOARD_SIZE * BOARD_SIZE;
	static const char DIVIDER = '|';
	static const char EMPTY_SIGN = '-';
	
	char PLAYERS_SIGN[PLAYERS_COUNT] {'X','O'};
	
	void show_cell_numbers();
	void show_current_cells();
	void show_cells();
	void make_move();
	char check();
	void show_result();
	void result_message(const string& winer,const string& loser);
	bool is_horizontal(int i);
	bool is_vertical(int i);
	bool is_diagonal();
	bool is_not_valid_cell(int cell);
	void fillPlayersNamesAndSigns(const string& name1, const string& name2);
	
	char m_win;
	int m_active_player;
	Player m_players[PLAYERS_COUNT];
	istream& m_istr;
	ostream& m_ostr;
	char m_cells[BOARD_FULL_SIZE];
	
	public:
	TicTacToe(const string& name1, const string& name2, istream& istr, ostream& ostr);
	
	
	void play_game();

};