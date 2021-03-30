#ifndef AUTO_HPP
#define AUTO_HPP

#include "organisation.hpp"

class Auto : public Organisation {
public:
    Auto(const std::string& name);
    bool isForSale() const override;
    bool isForRent() const override;
};

#endif // AUTO_HPP
