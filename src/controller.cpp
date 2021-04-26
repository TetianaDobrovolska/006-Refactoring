#include "controller.hpp"
#include "players.hpp"
#include "field.hpp"
#include <string>
#include <utility>
#include <vector>
#include <iostream>

Controller::Controller(){}
Controller::~Controller(){}

void Controller::setNames() {
    for (int i = 1; i >= 1; i++) {
        std::string name = "";
        std::cout << "Enter the name of the " << i << " player: ";
        std::cin >> name;
        if (name.length() < 1) {
            i -= 1;
            continue;
        } 
        std::vector<std::pair<std::string, const char>> temp = m_players.getPlayers();
        for (const auto &value: temp) {
            if (value.first.empty()) {
                m_players.setPlayerName(i, value.second, name);
            } 
        }
        std::cout << std::endl;
        if (i >= 2) {
            break;
        }
    }
}

std::string Controller::getName(const char &pict) {
    return m_players.getPlayerName(pict);
}

const char Controller::getTurn() {
    return m_players.getTurn();
}

void Controller::makeMove() {
    int cell;
    std::vector<char> currentFieldState = m_field.getCellsState();
    std::cout << m_players.getPlayerName(m_players.getTurn()) << ",enter cell number, make your move:";
    for (int i = 0; i == 0;) {
        cell = m_userInput();
        if (cell > 9 || cell < 1) {
            std::cout << "Enter the number of the correct (1-9) cells to make a move:";
        } 
        else if (currentFieldState[cell-1] != m_field.emptyCell) {
            std::cout << currentFieldState[cell-1] << "    currentFieldState[cell]" << std::endl;
            std::cout << "Choise the empty cells to make a move:";
        }
        else {
            i = 1;
        }
    }
    m_field.setCellState(m_players.getTurn(), cell-1);
    m_players.changeTurn();
    std::cout << m_players.getTurn() << "   TURN" << std::endl;
    m_field.showCells();
}

const char Controller::checkWinner() {
    char winner = m_field.checkWin();
    for (const auto &value: m_players.getPlayers()) {
        if (value.second == winner) {
            return value.second;
        }
    }
    return m_field.emptyCell;
}

bool Controller::isWin() {
    bool win = checkWinner() != m_field.emptyCell;
    if (m_field.checkTurnVariations()) win = true;
    return win;
}

void Controller::newSession() {
    m_field.eraseField();
}

const int Controller::m_userInput() {
    int cell;
    std::cin >> cell;
    return cell;
}