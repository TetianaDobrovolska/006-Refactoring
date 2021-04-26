#ifndef FIELD_H
#define FIELD_H

class Player;
class Field
{
public:
    enum eBrand
    {
        FORD,
        MCDONALD,
        LAMODA,
        AIR_BALTIC,
        NORDAVIA,
        TESLA,
        BPRISON,
        UKRSIBBANK
    };
    static constexpr int kRentCost = 250;
    Field(const eBrand brand, const int& index);

    const Field::eBrand getBrand() const;
    const int& getOwnerIndex() const;
    void setOwnerIndex(const int& index);

    virtual bool buy(Player& player);
    virtual bool renta(Player& player, Player& owner);
private:
    eBrand Brand;
    int ownerIndex;
};

#endif // FIELD_H
