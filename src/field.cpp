#include "field.hpp"

Field::Field()
{
	m_companyName = "";
	m_type = Field::PRISON;
	m_ownerIndex = 0;
	m_hasOwner = false;
}

Field::Field(std::string companyName, Type companyType, int ownerIndex, bool hasOwner) :
	m_companyName(companyName),
	m_type(companyType),
	m_ownerIndex(ownerIndex),
	m_hasOwner(hasOwner) {}

std::string Field::GetCompanyName() const
{
	return m_companyName;
}

Field::Type Field::GetType() const
{
	return m_type;
}

int Field::GetOwnerIndex() const
{
	return m_ownerIndex;
}

bool Field::HasOwner() const
{
	return m_hasOwner;
}

bool operator== (const Field& a, const Field& b)
{
	return a.m_companyName == b.m_companyName &&
		a.m_type == b.m_type &&
		a.m_ownerIndex == b.m_ownerIndex &&
		a.m_hasOwner == b.m_hasOwner;
}
