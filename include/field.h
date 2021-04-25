#ifndef FIELD_H
#define FIELD_H

#include "utils.hpp"

class Field
{
public:
    Field(resource::eBrand brand, resource::eType type, const int& index);

    const resource::eBrand getBrand() const;
    const resource::eType getType() const;
    const int& getOwnerIndex() const;
    void setOwnerIndex(const int& index);
private:
    resource::eBrand Brand;
    resource::eType Type;
    int ownerIndex;
};

#endif // FIELD_H
