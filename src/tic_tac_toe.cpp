#include <iostream> 
#include <cstring> 
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
#include "tic_tac_toe.h"
using namespace std;
TicTacToe::TicTacToe(const string& name1, const string& name2, istream& istr, ostream& ostr) : m_win(EMPTY_SIGN)
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

bool TicTacToe::is_not_valid_cell(int cell) {
	return cell > BOARD_FULL_SIZE || cell < 1 || m_cells[cell - 1] == PLAYERS_SIGN[1] || m_cells[cell - 1] == PLAYERS_SIGN[0];
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
    
    m_cells[cell - 1] = PLAYERS_SIGN[m_active_player];
}

bool TicTacToe::is_horizontal(int i) {
	int offset = i * BOARD_SIZE;
	return m_cells[offset] == m_cells[offset + 1] && m_cells[offset + 1] == m_cells[offset + 2];
}

bool TicTacToe::is_vertical(int i) {
	return m_cells[i] == m_cells[i + BOARD_SIZE] && m_cells[i + BOARD_SIZE] == m_cells[i + 2 * BOARD_SIZE];
}

bool TicTacToe::is_diagonal() {
	bool side_diag = m_cells[2] == m_cells[4] && m_cells[4] == m_cells[6];
	bool diag = m_cells[0] == m_cells[4] && m_cells[4] == m_cells[8];
	return side_diag || diag;
}

char TicTacToe::check() {
      for (int i = 0; i < BOARD_SIZE; i++)
		  if (is_horizontal(i))
			  return m_cells[i * BOARD_SIZE];	  
		  else if(is_vertical(i))
              return m_cells[i];
		  else if(is_diagonal())
			  return m_cells[4]; 
    return TicTacToe::EMPTY_SIGN; 
}

void TicTacToe::result_message(const string& winer,const string& loser) {
	m_ostr << winer << " you won congratulations " << loser << " you lose...";
}

void TicTacToe::show_result() {
	if (m_win == EMPTY_SIGN)
		m_ostr << "Draw";
	else
		m_win == PLAYERS_SIGN[0] ? result_message(m_players[0].getName(), m_players[1].getName()) :
								result_message(m_players[1].getName(), m_players[0].getName());
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
        
        if (move >= 5)
        {
            m_win = check();
            if (m_win != TicTacToe::EMPTY_SIGN)
				break;
        }
    }
	show_result();
}
