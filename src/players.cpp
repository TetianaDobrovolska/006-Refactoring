#include "players.hpp"
#include <string>
#include <utility>
#include <vector>
#include <iostream>

Players::Players() {}
Players::~Players(){}

std::vector<std::pair<std::string, const char>> Players::getPlayers() {
    return m_players;
}

void Players::setPlayerName(const int &playerNumber, const char &pict, const std::string &name) {
    std::pair<std::string, const char> player = m_getPlayer(pict);
    if (playerNumber == 1) { m_players[0].first = name; m_playerOne.first = name;} 
    else { m_players[1].first = name; m_playerTwo.first = name;}
}

std::string Players::getPlayerName(const char &pict) {
    return m_getPlayer(pict).first;
}

const char Players::getTurn() {
    return m_turn;
}

char Players::m_setTurn(const char &pict) {
    m_turn = m_getPlayer(pict).second;
}

void Players::changeTurn() {
    for (const auto &value: m_players) {
        if (value.second != getTurn()) {
            m_setTurn(value.second);
        }
    }
}

std::pair<std::string, const char> Players::m_getPlayer(const char &pict) {
    for (const auto &value: m_players) {
        if (value.second == pict) {
            return value;
        }
    }
}