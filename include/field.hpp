#ifndef FIELD_HPP
#define FIELD_HPP

#include <string>

class Field {
public:
	enum Type
	{
		AUTO,
		FOOD,
		TRAVEL,
		CLOTHER,
		PRISON,
		BANK
	};
	Field();
	Field(std::string, Type, int, bool);
	std::string GetCompanyName() const;
	Type GetType() const;
	int GetOwnerIndex() const;
	bool HasOwner() const;
	friend bool operator== (const Field&, const Field&);
private:
	std::string m_companyName;
	Type m_type;
	int m_ownerIndex;
	bool m_hasOwner;
};

#endif
