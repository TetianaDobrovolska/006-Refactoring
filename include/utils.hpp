#ifndef UTILS_HPP
#define UTILS_HPP

#include "field.hpp"
#include <map>

namespace Utils
{
    std::map<Field::Types, int> buyPrice{{Field::AUTO, 500},
                                  {Field::FOOD, 250},
                                  {Field::TRAVEL, 700},
                                  {Field::CLOTHER, 100}};

    std::map<Field::Types, int> rentPrice{{Field::AUTO, 250},
                                   {Field::FOOD, 250},
                                   {Field::TRAVEL, 250},
                                   {Field::CLOTHER, 250},
                                   {Field::PRISON, 1000},
                                   {Field::BANK, 700}};

}

#endif
