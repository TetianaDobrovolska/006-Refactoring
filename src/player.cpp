#include "player.hpp"

Player::Player(const std::string& name, const int& initial_balance)
    : _name(name), _balance(initial_balance) {}

std::string Player::getName() const {
    return _name;
}

int Player::getBalance() const {
    return _balance;
}

bool Player::makePayment(const int& amount) {
    if (amount > _balance)
        return false;
    _balance -= amount;
    return true;
}

void Player::collectPayment(const int& amount) {
    _balance += amount;
}

bool Player::makeTransaction(const int& amount, Player& sender) {
    return sender.makePayment(amount);
}

bool Player::makeTransaction(const int& amount, Player& sender, Player& receiver) {
    bool sent = sender.makePayment(amount);
    receiver.collectPayment(amount);
    return sent;
}

