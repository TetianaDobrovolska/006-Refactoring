#ifndef FIELD_BANK_HPP
#define FIELD_BANK_HPP

#include "field.hpp"

class FieldBank: public Field
{
private:
    const int RENT_BANK_ = 700;
public:
    FieldBank(const std::string& name);
};

#endif // FIELD_BANK_HPP
