#ifndef FIELD_HPP
#define FIELD_HPP

#include "player.hpp"
#include <string>

class Field
{
public:
	enum Types
	{
		AUTO,
		FOOD,
		TRAVEL,
		CLOTHER,
		PRISON,
		BANK
	};

	Field(std::string, Types, Player *, bool);

	std::string fieldName() const { return m_fieldName; }
	Player *fieldOwner() const { return m_fieldOwner; }
	void setFieldOwner(Player *fieldOwner) { m_fieldOwner = fieldOwner; }
	Types fieldType() const { return m_fieldType; }
	bool noOwner() const { return m_fieldOwner == NULL; };

	bool specialField() const { return m_specialField; }

private:
	const std::string m_fieldName;
	Player *m_fieldOwner;
	Types m_fieldType;
	bool m_specialField;
};

#endif