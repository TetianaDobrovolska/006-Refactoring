#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>

class Person{
public:
    Person(std::string n, int m): m_name(n), m_money(m){}
    std::string getName(){return m_name;}
	int getMoney(){return m_money;}
	
    void setMoney(int m){m_money = m;}
private:
    std::string m_name;
    int m_money;    
};

class BaseField{
public:
	virtual bool Buy(int z) = 0;
    virtual bool Renta(Person* takeMoneyFrom, Person* owner) = 0;
	BaseField(std::string n, int o, bool f):m_name(n),m_owner(o),m_flag(f){}
	std::string getName() const{return m_name;}
	int getOwner() const {return m_owner;}
	bool getFlag() const{return m_flag;}
    
    void setOwner(int o){m_owner = o;}
	void setFlag(bool f){m_flag = f;}
    virtual int getPrice() = 0;
private:
	std::string m_name;
	int m_owner;
	bool m_flag;
};

class AutoField : public BaseField {
public:
	AutoField(std::string n, int o, bool f):BaseField(n,o,f){}
	bool Buy(int z) override{
        setFlag(getOwner());
        setOwner(z);
        return true;
	}
    bool Renta(Person* takeMoneyFrom, Person* owner) override{
        if (!getOwner())
			return false;
		owner->setMoney(owner->getMoney() + RENT);
        takeMoneyFrom->setMoney(takeMoneyFrom->getMoney() - RENT);
        return true;
    }
    int getPrice() override {
        return PRICE;
    }
private:
    static constexpr int PRICE = 500;
    static constexpr int RENT = 250;
};
class FoodField : public BaseField {
public:
	FoodField(std::string n, int o, bool f):BaseField(n,o,f){}
	bool Buy(int z) override{
		setFlag(getOwner());
        setOwner(z);
        return true;
	}
    int getPrice() override {
        return PRICE;
    }
    bool Renta(Person* takeMoneyFrom, Person* owner) override{
        return getOwner();
    }
private:
    static constexpr int RENT = 0;
    static constexpr int PRICE = 250;
};
class TravelField : public BaseField {
public:
	TravelField(std::string n, int o, bool f):BaseField(n,o,f){}
	bool Buy(int z) override{
		setFlag(getOwner());
        setOwner(z);
        return true;
	}
        int getPrice() override {
        return PRICE;
    }
    bool Renta(Person* takeMoneyFrom, Person* owner) override{
        if (!getOwner())
			return false;
		owner->setMoney(owner->getMoney() + RENT);
        takeMoneyFrom->setMoney(takeMoneyFrom->getMoney() - RENT);
        return true;
    }
private:
    static constexpr int RENT = 250;
    static constexpr int PRICE = 700;
};
class ClotherField : public BaseField {
public:
	ClotherField(std::string n, int o, bool f):BaseField(n,o,f){}
	bool Buy(int z) override{
		setFlag(getOwner());
        setOwner(z);
        return true;
	}
    int getPrice() override {
        return PRICE;
    }
    bool Renta(Person* takeMoneyFrom, Person* owner) override{
        if (!getOwner())
			return false;
		owner->setMoney(owner->getMoney() + RENT);
        takeMoneyFrom->setMoney(takeMoneyFrom->getMoney() - RENT);
        return true;
    }
private:
    static constexpr int RENT = 250;
    static constexpr int PRICE = 100;
};
class PrisonField : public BaseField {
public:
	PrisonField(std::string n, int o, bool f):BaseField(n,o,f){}
	bool Buy(int z) override{
		return false;
	}
    int getPrice() override {
        return PRICE;
    }
    bool Renta(Person* takeMoneyFrom, Person* owner) override{
		takeMoneyFrom->setMoney(takeMoneyFrom->getMoney() - RENT);
        return true;
    }
private:
    static constexpr int PRICE = 0;
    static constexpr int RENT = 1000;
};
class BankField : public BaseField {
public:
	BankField(std::string n, int o, bool f):BaseField(n,o,f){}
	bool Buy(int z) override {
		return false;
	}
    int getPrice() override {
        return PRICE;
    }
    bool Renta(Person* takeMoneyFrom, Person* owner) override{
		takeMoneyFrom->setMoney(takeMoneyFrom->getMoney() - RENT);
        return true;
    }
private:
    static constexpr int PRICE = 0;
    static constexpr int RENT = 700;
};
class Monopoly
{
private:
	static constexpr int MAX_PLAYERS = 10;
	static constexpr int INITIAL_CAPITAL = 6000;
	
	std::list<BaseField*> Fields;
	std::list<Person*> Players;
	
public:
	Monopoly(std::string names[MAX_PLAYERS],int);
	std::list<Person*>::const_iterator GetPlayersListBegin();
	std::list<Person*>::const_iterator GetPlayersListEnd();
	std::list<BaseField*>::const_iterator GetFieldsListBegin();
	std::list<BaseField*>::const_iterator GetFieldsListEnd();

	Person*  GetPlayerInfo(int);	 
	bool Buy(int p, BaseField* k);
	BaseField* GetFieldByName(const std::string&);	
	bool Renta(int p, BaseField* c);
};

#endif