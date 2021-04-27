#ifndef FIELD_CLOTHER_HPP
#define FIELD_CLOTHER_HPP

#include "field.hpp"

class FieldClother: public Field
{
private:
    const int PRICE_CLOTHER_ = 100;
    const int RENT_CLOTHER_ = 250;
public:
    FieldClother(const std::string& name);
};

#endif // FIELD_CLOTHER_HPP
