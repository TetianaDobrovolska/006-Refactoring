#ifndef CLOTH_FIELD_H
#define CLOTH_FIELD_H

#include "field.h"

class ClothField : public Field
{
public:
    static constexpr int kClotherFieldCost = 100;
    ClothField(const eBrand brand, const int& index);

    bool buy(Player& player) override;
private:
};

#endif // CLOTH_FIELD_H
