#include "organisation.hpp"

Organisation::Organisation(const std::string& name)
    : _name(name), _owner(""), _value(-1), _rent(-1) {}
Organisation::~Organisation() {}

std::string Organisation::getName() {
    return _name;
}

std::string Organisation::getOwner() {
    return _owner;
}

void Organisation::setOwner(const std::string& owner) {
    _owner = owner;
}

int Organisation::getValue() const {
    return _value;
}

int Organisation::getRent() const {
    return _rent;
}
