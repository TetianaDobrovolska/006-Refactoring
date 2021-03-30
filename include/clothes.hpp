#ifndef CLOTHES_HPP
#define CLOTHES_HPP

#include "organisation.hpp"

class Clothes : public Organisation {
public:
    Clothes(const std::string& name);
    bool isForSale() const override;
    bool isForRent() const override;
};

#endif // CLOTHES_HPP
