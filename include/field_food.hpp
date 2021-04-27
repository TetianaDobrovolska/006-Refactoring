#ifndef FIELD_FOOD_HPP
#define FIELD_FOOD_HPP

#include "field.hpp"

class FieldFood: public Field
{
private:
    const int PRICE_FOOD_ = 250;
public:
    FieldFood(const std::string& name);
};

#endif // FIELD_FOOD_HPP
