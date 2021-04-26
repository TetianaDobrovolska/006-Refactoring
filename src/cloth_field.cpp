#include "cloth_field.h"
#include "player.h"

ClothField::ClothField(const eBrand brand, const int& index)
  : Field(brand, index)
{
}

bool ClothField::buy(Player& player)
{
    player.calcBalance(-kClotherFieldCost);
    return true;
}
