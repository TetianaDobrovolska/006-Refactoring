#ifndef PRISON_FIELD_H
#define PRISON_FIELD_H

#include "field.h"

class PrisonField : public Field
{
public:
    static constexpr int kPrisonRansomCost = 1000;
    PrisonField(const eBrand brand, const int& index);

    bool renta(Player& player, Player& owner) override;
};

#endif // PRISON_FIELD_H
