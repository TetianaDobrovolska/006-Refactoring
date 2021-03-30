#ifndef FOOD_HPP
#define FOOD_HPP

#include "organisation.hpp"

class Food : public Organisation {
public:
    Food(const std::string& name);
    bool isForSale() const override;
    bool isForRent() const override;
};

#endif // FOOD_HPP
