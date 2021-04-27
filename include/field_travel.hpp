#ifndef FIELD_TRAVEL_HPP
#define FIELD_TRAVEL_HPP

#include "field.hpp"

class FieldTravel: public Field
{
private:
    const int PRICE_TRAVEL_ = 700;
    const int RENT_TRAVEL_ = 250;
public:
    FieldTravel(const std::string& name);
};

#endif // FIELD_TRAVEL_HPP
