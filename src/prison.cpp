#include "prison.hpp"

Prison::Prison() : Organisation("Prison") {
    _rent = 1000;
}

bool Prison::isForSale() const {
    return false;
}

bool Prison::isForRent() const {
    return true;
}
