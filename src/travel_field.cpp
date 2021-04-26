#include "travel_field.h"
#include "player.h"

TravelField::TravelField(const eBrand brand, const int& index)
  : Field(brand, index)
{
}

bool TravelField::buy(Player& player)
{
    player.calcBalance(-kTravelFieldCost);
    return true;
}
