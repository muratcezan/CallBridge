// Description: Create card list using Card
#pragma once

#include <vector>

#include "card/card.h"

class Deck
{
public:
    Deck();

    void createDeck();

    std::vector<Card *> list;
};