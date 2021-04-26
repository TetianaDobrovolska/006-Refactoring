#include "auto_field.h"
#include "player.h"

AutoField::AutoField(const eBrand brand, const int& index)
  : Field(brand, index)
{
}

bool AutoField::buy(Player& player)
{
    player.calcBalance(-kAutoFieldCost);
    return true;
}
