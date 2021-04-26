#ifndef TRAVEL_FIELD_H
#define TRAVEL_FIELD_H

#include "field.h"

class TravelField : public Field
{
public:
    static constexpr int kTravelFieldCost = 700;
    TravelField(const eBrand brand, const int& index);

    virtual bool buy(Player& player);
private:
};

#endif // TRAVEL_FIELD_H
