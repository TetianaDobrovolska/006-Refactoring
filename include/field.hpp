#ifndef FIELD_HPP
#define FIELD_HPP

#include <string>

class Field
{
public:

    enum CompanyType
    {
        AUTO,
        FOOD,
        TRAVEL,
        CLOTHES,
        PRISON,
        BANK
    };


    Field();

    Field (const std::string& name, CompanyType, const int& id);
    const std::string& GetCompanyName() const;
    CompanyType GetBusinessType() const;
    const int& GetOwnerIndex() const;
    void SetOwnerIndex(const int& id);
private:
    std::string companyName;
    CompanyType type;
    int ownerId;
};

#endif // FIELD_HPP
