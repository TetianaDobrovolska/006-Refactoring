#ifndef FIELD_HPP
#define FIELD_HPP

#include <vector>
#include <utility>
#include "field.hpp"

class Field 
{

public:
    Field(){};
    ~Field(){};

    std::vector<std::pair<const char, const char>> getField() const;
private:
    std::vector<std::pair<const char, const char>> cells; 
    
};


#endif