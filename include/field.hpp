#ifndef FIELD_HPP
#define FIELD_HPP

#include <list>
#include <string>

class Player;
using PlayerIterator = std::list<Player>::iterator;

class Field {
public:
    enum class Type
    {
        AUTO,
        FOOD,
        TRAVEL,
        CLOTHER,
        PRISON,
        BANK
    };

    Field();
    Field(const std::string& name, const Type& type);
    std::string getName() const;
    Type getType() const;
    PlayerIterator getPlayer() const;
    int getPrice() const;
    int getRent() const;

    virtual bool sellTo(PlayerIterator player);
//    virtual bool rentTo(const int& id);

protected:
    std::string name_;
    Type type_;
    PlayerIterator player_owner_;
    int price_ = 0;
    int rent_ = 0;
};

#endif // FIELD_HPP
