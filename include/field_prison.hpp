#ifndef FIELD_PRISON_HPP
#define FIELD_PRISON_HPP

#include "field.hpp"

class FieldPrison: public Field
{
private:
    const int RENT_PRISON_ = 1000;
public:
    FieldPrison(const std::string& name);
    virtual bool sellTo(PlayerIterator player);
};
#endif // FIELD_PRISON_HPP
