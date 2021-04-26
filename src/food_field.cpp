#include "food_field.h"
#include "player.h"

FoodField::FoodField(const eBrand brand, const int& index)
  : Field(brand, index)
{
}

bool FoodField::buy(Player& player)
{
    player.calcBalance(-kFoodFieldCost);
    return true;
}

bool FoodField::renta(Player& player, Player& owner)
{
    return getOwnerIndex() ? true : false;
}
