#ifndef FOOD_FIELD_H
#define FOOD_FIELD_H

#include "field.h"

class FoodField : public Field
{
public:
    static constexpr int kFoodFieldCost = 250;
    FoodField(const eBrand brand, const int& index);

    bool buy(Player& player) override;
    bool renta(Player& player, Player& owner) override;
private:
};

#endif // FOOD_FIELD_H
