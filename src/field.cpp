#include "field.hpp"

Field::Field(std::string name, Types type, Player *owner, bool special)
    : m_fieldName(name),
      m_fieldType(type),
      m_fieldOwner(owner),
      m_specialField(special)
{
}