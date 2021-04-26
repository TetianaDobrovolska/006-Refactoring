#include "field.h"

Field::Field(eBrand brand, eType type, const int& index)
    : Brand(brand), Type(type), ownerIndex(index)
{

}

const Field::eType Field::getType() const
{
    return Type;
}

const Field::eBrand Field::getBrand() const
{
    return Brand;
}

const int &Field::getOwnerIndex() const
{
    return ownerIndex;
}

void Field::setOwnerIndex(const int &index)
{
    ownerIndex = index;
}
