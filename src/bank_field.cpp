#include "bank_field.h"
#include "player.h"

BankField::BankField(const eBrand brand, const int& index)
    : Field(brand, index)
{
}

bool BankField::renta(Player& player, Player& owner)
{
    player.calcBalance(-kBankPaymant);
    return true;
}
