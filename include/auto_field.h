#ifndef AUTO_FIELD_H
#define AUTO_FIELD_H

#include "field.h"

class AutoField : public Field
{
public:
    static constexpr int kAutoFieldCost = 500;
    AutoField(const eBrand brand, const int& index);

    bool buy(Player& player) override;
private:
};

#endif // AUTO_FIELD_H
