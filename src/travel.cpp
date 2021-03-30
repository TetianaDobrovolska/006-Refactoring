#include "travel.hpp"

Travel::Travel(const std::string& name) : Organisation(name) {
    _value = 700;
    _rent = 250;
}

bool Travel::isForSale() const {
    return _owner.empty();
}

bool Travel::isForRent() const {
    return !_owner.empty();;
}
