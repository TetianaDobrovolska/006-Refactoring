#include "prison_field.h"
#include "player.h"

PrisonField::PrisonField(const eBrand brand, const int& index)
    : Field(brand, index)
{
}

bool PrisonField::renta(Player& player, Player& owner)
{
    player.calcBalance(-kPrisonRansomCost);
    return true;
}
