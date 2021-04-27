#ifndef FIELD_AUTO_HPP
#define FIELD_AUTO_HPP

#include "field.hpp"
#include <string>

class FieldAuto: public Field
{
private:
    const int PRICE_AUTO_ = 500;
    const int RENT_AUTO_ = 250;
public:
    FieldAuto(const std::string& name);
};

#endif // FIELD_AUTO_HPP
