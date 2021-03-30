#include "bank.hpp"

Bank::Bank(const std::string& name) : Organisation(name) {
    _rent = 700;
}

bool Bank::isForSale() const {
    return false;
}

bool Bank::isForRent() const {
    return true;
}
