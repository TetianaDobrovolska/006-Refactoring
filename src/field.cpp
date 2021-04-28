#include "field.hpp"

Field::Field()
{

}

Field::Field(const std::string& name, CompanyType companyType, const int& id):

    companyName(name),
    type(companyType),
    ownerId(id)
{

}

const std::string& Field::GetCompanyName() const
{
    return companyName;
}

Field::CompanyType Field::GetBusinessType() const
{
    return type;
}

const int& Field::GetOwnerIndex() const
{
    return ownerId;
}

