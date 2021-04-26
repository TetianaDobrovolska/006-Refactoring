#ifndef FIELD_H
#define FIELD_H

class Field
{
public:
    enum eType
    {
        AUTO,
        FOOD,
        TRAVEL,
        CLOTHER,
        PRISON,
        BANK
    };

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
    Field(eBrand brand, eType type, const int& index);

    const Field::eBrand getBrand() const;
    const Field::eType getType() const;
    const int& getOwnerIndex() const;
    void setOwnerIndex(const int& index);
private:
    eBrand Brand;
    eType Type;
    int ownerIndex;
};

#endif // FIELD_H
