#include "food.hpp"

Food::Food(const std::string& name) : Organisation(name) {
    _value = 250;
}

bool Food::isForSale() const {
    return _owner.empty();
}

bool Food::isForRent() const {
    return false;
}
