#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "figureCommon.hpp"
#include "field.hpp"

class Controller 
{

public:
    Controller(){};
    ~Controller(){};
    void start();
    bool isCellBusy(const char& positionAlphabet, const char& positionNumber);
    void move(const char& positionAlphabet, const char& positionNumber);
};


#endif