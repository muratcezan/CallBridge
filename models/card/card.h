#pragma once

#include "card_contents.h"

// Description: Card Object
class Card
{
public:
    Card();
    Card(Types, Values);

    Types type() const;
    void setType(Types);

    Values value() const;
    void setValue(Values);

    bool operator==(const Card &) const;
    bool operator!=(const Card &other) const;

private:
    Types m_type;
    Values m_value;
};