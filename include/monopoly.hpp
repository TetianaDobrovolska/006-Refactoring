#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>

namespace monopoly::constannts {
static const int START_BALANCE_ = 6000;
}
class Field;
using Fields = std::list<Field>;
using FieldIterator = std::list<Field>::iterator;

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
    Field(const std::string& name, const Type& type, const int& owner);
    std::string getName() const;
    Type getType() const;
    int getId() const;

private:
    std::string name_;
    Type type_;
    int id_;
};

class Monopoly
{
private:
    static const int COMPANY_NUMBER_ = 10;

    static const int PRICE_AUTO_ = 500;
    static const int PRICE_FOOD_ = 250;
    static const int PRICE_TRAVEL_ = 700;
    static const int PRICE_CLOTHER_ = 100;

    static const int RENT_AUTO_ = 250;
    static const int RENT_TRAVEL_ = 250;
    static const int RENT_CLOTHER_ = 250;
    static const int RENT_PRISON_ = 1000;
    static const int RENT_BANK_ = 700;

public:
    Monopoly(std::string names[COMPANY_NUMBER_],int);
	std::list<std::tuple<std::string,int>> *	GetPlayersList();
    FieldIterator GetFieldsList();
    Fields::iterator FieldsEnd();
    Fields fields_;
	std::list<std::tuple<std::string, int>> Players;
	std::tuple<std::string, int>  GetPlayerInfo(int);	 
    bool Buy(int, Field&);
    FieldIterator GetFieldByName(const std::string&);
    bool Renta(int, const Field&);
	
};

#endif
