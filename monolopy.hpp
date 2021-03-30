#ifndef MONOPOLY_HPP
#define MONOPOLY_HPP

#include <list>
#include <tuple>
#include <string>

static constexpr uint8_t MAX_PLAYER = 10U;

static constexpr uint16_t PLAYER_STARTING_MONEY = 6000U;

static constexpr uint16_t AUTO_BUY_PRICE = 500U;
static constexpr uint16_t AUTO_RENTAL_CHARGE = 250U;
static constexpr uint16_t FOOD_BUY_PRICE = 250U;
static constexpr uint16_t FOOD_RENTAL_CHARGE = 0U;
static constexpr uint16_t TRAVEL_BUY_PRICE = 700U;
static constexpr uint16_t TRAVEL_RENTAL_CHARGE = 250U;
static constexpr uint16_t CLOTHER_BUY_PRICE = 100U;
static constexpr uint16_t CLOTHER_RENTAL_CHARGE = 250U;
static constexpr uint16_t PRISON_BUY_PRICE = std::numeric_limits<uint16_t>::max();
static constexpr uint16_t PRISON_RENTAL_CHARGE = 1000U;
static constexpr uint16_t BANK_BUY_PRICE = std::numeric_limits<uint16_t>::max();
static constexpr uint16_t BANK_RENTAL_CHARGE = 700U;

class Player;
class Field;

class Monopoly
{
public:
	using PlayerVector = std::vector<Player>;
	using FieldList = std::list<Field*>;

	Monopoly(std::string names[MAX_PLAYER], int);

	bool Renta(const std::string playerName, const Field* field);
	const PlayerVector* GetPlayers() const;
	bool Buy(const std::string playerName, const std::string fieldName);
private:
	Field* GetFieldByName(std::string fieldName) const;
	Player* GetPlayerByName(std::string playerName) const;

	FieldList _fields;
	PlayerVector _players;
};

class Player
{
public:
	Player(const std::string playerName) :
		_name(playerName),
		_balance(PLAYER_STARTING_MONEY)
	{
	}
	std::string getPlayerName() const { return _name; };
	uint16_t getPlayerBalance() const { return _balance; };
	void changePlayerBalance(uint16_t value) { _balance += value; };
private:
	const std::string _name;
	uint16_t _balance;
};

class Field
{
public:
	Field(const std::string fieldName) :
		_fieldName(fieldName),
		_ownershipName("")
	{};

	virtual std::string getFieldName() const {return _fieldName;};
	virtual std::string getOwnershipName() const { return _ownershipName; };
	virtual void changeOwnership(std::string playerName) { _ownershipName = playerName; };
	virtual uint16_t getBuyingPrice() const = 0;
	virtual uint16_t getRentalCost() const = 0;

private:
	const std::string _fieldName;
	std::string _ownershipName;
};



class Auto : public Field
{
public:
	Auto(const std::string fieldname) : Field(fieldname) {};

	virtual uint16_t getBuyingPrice() const override {
		return AUTO_BUY_PRICE;
	}
	virtual uint16_t getRentalCost() const override {
		return AUTO_RENTAL_CHARGE;
	}
};

class Food : public Field
{
public:
	Food(const std::string fieldname) : Field(fieldname) {};

	virtual uint16_t getBuyingPrice() const override {
		return FOOD_BUY_PRICE;
	}
	virtual uint16_t getRentalCost() const override {
		return FOOD_RENTAL_CHARGE;
	}
};

class Travel : public Field
{
public:
	Travel(const std::string fieldname) : Field(fieldname) {};

	virtual uint16_t getBuyingPrice() const override {
		return TRAVEL_BUY_PRICE;
	}
	virtual uint16_t getRentalCost() const override {
		return TRAVEL_RENTAL_CHARGE;
	}
};

class Clother : public Field
{
public:
	Clother(const std::string fieldname) : Field(fieldname) {};

	virtual uint16_t getBuyingPrice() const override {
		return CLOTHER_BUY_PRICE;
	}
	virtual uint16_t getRentalCost() const override {
		return CLOTHER_RENTAL_CHARGE;
	}
};

class Prison : public Field
{
public:
	Prison(const std::string fieldname) : Field(fieldname) {};

	virtual uint16_t getBuyingPrice() const override {
		return PRISON_BUY_PRICE;
	}
	virtual uint16_t getRentalCost() const override {
		return PRISON_RENTAL_CHARGE;
	}
};

class Bank : public Field
{
public:
	Bank(const std::string fieldname) : Field(fieldname) {};

	virtual uint16_t getBuyingPrice() const override {
		return BANK_BUY_PRICE;
	}
	virtual uint16_t getRentalCost() const override {
		return BANK_RENTAL_CHARGE;
	}
};
#endif