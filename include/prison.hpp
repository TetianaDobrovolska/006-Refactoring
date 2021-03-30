#ifndef PRISON_HPP
#define PRISON_HPP

#include "organisation.hpp"

class Prison : public Organisation {
public:
    Prison();
    bool isForSale() const override;
    bool isForRent() const override;
};

#endif // PRISON_HPP
