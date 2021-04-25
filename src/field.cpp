#include "field.h"

Field::Field(resource::eBrand brand, resource::eType type, const int& index)
    : Brand(brand), Type(type), ownerIndex(index)
{

}

const resource::eType Field::getType() const
{
    return Type;
}

const resource::eBrand Field::getBrand() const
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
