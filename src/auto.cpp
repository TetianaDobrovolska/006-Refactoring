#include "auto.hpp"

Auto::Auto(const std::string& name)
    : Organisation(name) {
    _value = 500;
    _rent = 250;
}

bool Auto::isForSale() const {
    return _owner.empty();
}

bool Auto::isForRent() const {
    return !_owner.empty();
}
