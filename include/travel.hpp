#ifndef TRAVEL_HPP
#define TRAVEL_HPP

#include "organisation.hpp"

class Travel : public Organisation {
public:
    Travel(const std::string& name);
    bool isForSale() const override;
    bool isForRent() const override;
};

#endif // TRAVEL_HPP
