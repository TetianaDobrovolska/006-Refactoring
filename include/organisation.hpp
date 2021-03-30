#ifndef ORGANISATION_H
#define ORGANISATION_H

#include <string>

class Organisation {
public:
    virtual ~Organisation() = 0;
    virtual bool isForSale() const = 0;
    virtual bool isForRent() const = 0;
    std::string getName();
    std::string getOwner();
    void setOwner(const std::string& owner);
    int getValue() const;
    int getRent() const;

protected:
    Organisation(const std::string& name);
    std::string _name;
    std::string _owner;
    int _value;
    int _rent;
};

#endif // ORGANISATION_H
