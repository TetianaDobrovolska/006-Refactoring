#include "field.hpp"
#include <string>
#include <utility>
#include <vector>
#include <iostream>

Field::Field(){}
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

const std::vector<char> Field::getCellsState() {
    return m_cellsState;
}

char Field::setCellState(const char symbol, const int cellNumber) {
    m_cellsState[cellNumber] = symbol;
}