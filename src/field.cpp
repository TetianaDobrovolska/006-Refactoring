#include "field.h"
#include "player.h"
#include "monopoly.hpp"

Field::Field(const eBrand brand, const int& index)
    : Brand(brand), ownerIndex(index)
{
}

const Field::eBrand Field::getBrand() const
{
    return Brand;
}

const int &Field::getOwnerIndex() const
{
    return ownerIndex;
}

void Field::setOwnerIndex(const int &index)
{
    ownerIndex = index;
}

bool Field::buy(Player& player)
{
    return false;
}

bool Field::renta(Player& player, Player& owner)
{
    if(!ownerIndex)
        return false;
    player.calcBalance(-kRentCost);
    owner.calcBalance(kRentCost);
    return true;
}