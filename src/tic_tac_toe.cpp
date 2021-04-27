#include <iostream> 
#include <cstring> 
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
#include "tic_tac_toe.h"
using namespace std;
TicTacToe::TicTacToe(const string& name1, const string& name2, istream& istr, ostream& ostr)
                                                    : m_win(EMPTY_SIGN)
													, m_istr(istr)
													, m_ostr(ostr)
{
	fillPlayersNamesAndSigns(name1, name2);
	for (int i = 0;i < BOARD_FULL_SIZE; ++i)
		m_cells[i] = EMPTY_SIGN;
}
void TicTacToe::show_cell_numbers() {
	system("cls");
	
	m_ostr << "Cell numbers: \n";
	for (int i = 1; i <= BOARD_FULL_SIZE; ++i)
	{
		m_ostr << EMPTY_SIGN << i << EMPTY_SIGN;
		if(i % BOARD_SIZE == 0) {
			m_ostr << endl;
			continue;
		}
		m_ostr << DIVIDER;
	}
}

void TicTacToe::show_current_cells() {
	m_ostr << "Current situation (--- empty):\n" << endl;
	for (int i = 0; i < BOARD_FULL_SIZE; ++i)
	{
		m_ostr << EMPTY_SIGN << m_cells[i] << EMPTY_SIGN;
		if((i + 1) % BOARD_SIZE == 0) {
			m_ostr << endl;
			continue;
		}
		m_ostr << DIVIDER;
	}
}

void TicTacToe::show_cells() {
    show_cell_numbers();
	show_current_cells();
}

bool TicTacToe::is_out_of_board(int cell) {
	return cell > BOARD_FULL_SIZE || cell < 1;
}

bool TicTacToe::is_not_empty(int cell) {
	bool is_cell_busy_by_player1 = m_cells[cell - 1] == m_players[0].getSign();
	bool is_cell_busy_by_player2 = m_cells[cell - 1] == m_players[1].getSign();
	return is_cell_busy_by_player1 || is_cell_busy_by_player2;
}
bool TicTacToe::is_not_valid_cell(int cell) {
	return  is_out_of_board(cell)|| is_not_empty(cell);
}

void TicTacToe::make_move() {
    m_ostr << m_players[m_active_player].getName();
    int cell;
    m_ostr << ",enter cell number, make your move:";
    m_istr >> cell;

    while (is_not_valid_cell(cell)) {
        m_ostr << "Enter the number of the correct (1-9) or empty (---) cells to make a move:";
        m_istr >> cell;
        m_ostr << "\n";
    }
    
    m_cells[cell - 1] = m_players[m_active_player].getSign();
}

bool TicTacToe::is_horizontal(int i) {
	int offset = i * BOARD_SIZE;
    int offset_next = i * BOARD_SIZE + 1;
    int offset_next_next = i * BOARD_SIZE + 2;
    
	bool first_and_second_are_equals = m_cells[offset] == m_cells[offset_next];
	bool second_and_third_are_equals = m_cells[offset_next] == m_cells[offset_next_next];
    
	return first_and_second_are_equals && second_and_third_are_equals;
}

bool TicTacToe::is_vertical(int i) {
    int column_index = i;
    int column_index_next = i + BOARD_SIZE;
    int column_index_next_next = i + 2 * BOARD_SIZE;
    
	bool first_and_second_are_equals = m_cells[column_index] == m_cells[column_index_next];
	bool second_and_third_are_equals = m_cells[column_index_next] == m_cells[column_index_next_next];
	
    return first_and_second_are_equals && second_and_third_are_equals;
}

bool TicTacToe::is_diagonal() {
	bool side_diag = m_cells[SIDE_DIAGONAL_COORD[0]] == m_cells[SIDE_DIAGONAL_COORD[1]] && m_cells[SIDE_DIAGONAL_COORD[1]] == m_cells[SIDE_DIAGONAL_COORD[2]];
	bool diag = m_cells[DIAGONAL_COORD[0]] == m_cells[DIAGONAL_COORD[1]] && m_cells[DIAGONAL_COORD[1]] == m_cells[DIAGONAL_COORD[2]];
	return side_diag || diag;
}

char TicTacToe::check() {
    for (int i = 0; i < BOARD_SIZE; i++)
		if (is_horizontal(i))
			return m_cells[i * BOARD_SIZE];	  
		else if(is_vertical(i))
            return m_cells[i];
		else if(is_diagonal())
			return m_cells[CENTRAL_ELEM_COORD]; 
    return TicTacToe::EMPTY_SIGN; 
}

void TicTacToe::result_message(const string& winer,const string& loser) {
	m_ostr << winer << " you won congratulations " << loser << " you lose...";
}

void TicTacToe::show_result() {
	if (m_win == EMPTY_SIGN) {
		m_ostr << "Draw";
		return;
	}
	string first_player_name = m_players[0].getName();
	char first_player_sign = m_players[0].getSign();
	string second_player_name = m_players[1].getName();
	m_win == first_player_sign ? result_message(first_player_name, second_player_name) :
								result_message(second_player_name, first_player_name);
}

void TicTacToe::fillPlayersNamesAndSigns(const string& name1, const string& name2) {
	m_players[0].setName(name1);
	m_players[0].setSign(PLAYERS_SIGN[0]);
    
	m_players[1].setName(name2);
	m_players[1].setSign(PLAYERS_SIGN[1]);
	
}

void TicTacToe::play_game(){
	show_cells();

    for (int move = 1; move <= BOARD_FULL_SIZE; move++) {
		m_active_player = (move - 1) % 2;
		make_move();

        show_cells();
        
        if (move >= MIN_MOVES_FOR_WIN)
        {
            m_win = check();
            if (m_win != TicTacToe::EMPTY_SIGN)
				break;
        }
    }
	show_result();
}
