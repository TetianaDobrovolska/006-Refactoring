#ifndef BANK_FIELD_H
#define BANK_FIELD_H

#include "field.h"

class BankField : public Field
{
public:
    static constexpr int kBankPaymant = 700;
    BankField(const eBrand brand, const int& index);

    bool renta(Player& player, Player& owner) override;
private:
};

#endif // BANK_FIELD_H
