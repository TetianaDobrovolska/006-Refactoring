#ifndef BANK_HPP
#define BANK_HPP

#include "organisation.hpp"

class Bank : public Organisation {
public:
    Bank(const std::string& name);
    bool isForSale() const override;
    bool isForRent() const override;
};

#endif // BANK_HPP
