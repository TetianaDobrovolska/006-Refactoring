#pragma once

#include <string>

namespace tictactoe
{

enum player_code {
    DRAW,
    PLAYER1,
    PLAYER2
};

class IPlayer {

public:
    IPlayer() = default;
    virtual ~IPlayer() = default;

    virtual bool isNull() const = 0;
    virtual player_code getId() const = 0;
    virtual char getSymbol() const = 0;
    virtual const std::string& getName() const = 0;
};

class NullPlayer : public IPlayer
{
public:
    NullPlayer() = default;
    virtual ~NullPlayer() override = default;

    virtual bool isNull() const override;
    virtual player_code getId() const override;
    virtual char getSymbol() const override;
    virtual const std::string& getName() const override;

};

class Player : public IPlayer
{
public:
    Player(char sym, player_code code = PLAYER1, const std::string& player_name = "Player");
    ~Player() override;

    char getSymbol() const override;
    player_code getId() const override;
    const std::string& getName() const override;
    bool isNull() const override;


private:
    const char m_symbol;
    const player_code m_id;
    const std::string m_name;
};

}
