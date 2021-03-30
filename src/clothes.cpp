#include "clothes.hpp"

Clothes::Clothes(const std::string& name) : Organisation(name) {
    _value = 100;
    _rent = 250;
}

bool Clothes::isForSale() const {
    return _owner.empty();
}

bool Clothes::isForRent() const {
    return !_owner.empty();
}
