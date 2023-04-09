#include "card.h"

Card::Card() : m_type(Types::Empty), m_value(Values::Empty){};
Card::Card(Types type, Values value) : m_type(type), m_value(value){};

// Card type
Types Card::type() const
{
    return m_type;
}
void Card::setType(Types type)
{
    m_type = type;
}

Values Card::value() const
{
    return m_value;
}
void Card::setValue(Values value)
{
    m_value = value;
}
bool Card::operator==(const Card &other) const
{
    return m_type == other.type() && m_value == other.value();
}
bool Card::operator!=(const Card &other) const
{
    return !(*this == other);
}