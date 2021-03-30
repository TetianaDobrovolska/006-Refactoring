#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

class Player {
public:
    Player(const std::string& name, const int& initial_balance);
    std::string getName() const;
    int getBalance() const;
    bool makePayment(const int& amount);
    void collectPayment(const int& amount);
    static bool makeTransaction(const int& amount, Player& sender);
    static bool makeTransaction(const int& amount, Player& sender, Player& receiver);

private:
    const std::string _name;
    int _balance;
};

#endif // PLAYER_H
