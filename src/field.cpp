#include "field.hpp"
#include <string>
#include <utility>
#include <vector>
#include <iostream>

Field::Field(){
    eraseField();
}
Field::~Field(){}

void Field::showCells() {
    system("cls");

    std::cout << "Cell numbers: \n";
    std::cout << "-1-|-2-|-3-\n";
	std::cout << "-4-|-5-|-6-\n";
	std::cout << "-7-|-8-|-9-\n";
	std::cout << std::endl;

    std::cout << "Current situation (--- empty):\n" << std::endl;
    for (int i = 0; i < m_cellsState.size()-1; i += m_fieldSize) {
        for (int j = 0; j < m_fieldSize; j++) {
            std::cout << "-" << m_cellsState[j+i] << "-" << "|";
        }
        std::cout << std::endl;
    }
}

char Field::checkWin() {
    std::vector<char> winner {m_checkHorizontalRezult(), m_checkVerticalRezult(), m_checkDiagonalRezult()};
    for (const auto &value: winner) {
        if (m_checkResult(value)) {
            return value;
        }
    }
}

char Field::m_checkHorizontalRezult() {
    for (int i = 0; i < m_cellsState.size()-1; i += m_fieldSize) {
        if(m_cellsState[i] == m_cellsState[i+m_fieldSize-1] && 
                m_cellsState[i] == m_cellsState[i+m_fieldSize-2]) {
            return m_cellsState[i];
        }   
    }
}

char Field::m_checkVerticalRezult() {
    for (int i = 3; i < m_cellsState.size()*2-1; i++) {
        if(m_cellsState[i-(m_fieldSize-1)] == m_cellsState[i+(m_fieldSize-1)]) {
            return m_cellsState[i];
        }   
    }
}

char Field::m_checkDiagonalRezult() {
    for (int i = 0; i < m_cellsState.size()-1; i++) {
        if(m_cellsState[i] == m_cellsState[m_fieldSize+1] && 
                ((i == 0 && m_cellsState[i] == m_cellsState[(m_fieldSize+1)*2]) ||
                (m_cellsState[i] == m_cellsState[(m_fieldSize+1)+i]))) {
            return m_cellsState[i];
        }   
    }
}

bool Field::m_checkResult(const char &result) {
    bool win = false;
    if(result != emptyCell) {
        win = true;
    }
    return win;
}

const std::vector<char> Field::getCellsState() {
    return m_cellsState;
}

char Field::setCellState(const char symbol, const int cellNumber) {
    m_cellsState[cellNumber] = symbol;
}

void Field::eraseField() {
    m_cellsState = { '-','-','-','-','-','-','-','-','-' };
}

bool Field::checkTurnVariations() {
    for (const auto &value: m_cellsState) {
        if (value == '-') {
            return false;
        }
    }
    return true;
}