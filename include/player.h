#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
    Player();
    Player(const std::string& name, const int& balance);

    const int& getBalance() const;
    const std::string& getName() const;

    void calcBalance(const int& delta);
private:
    std::string Name;
    int Balance;
};

#endif // PLAYER_H
