#pragma once

#include <vector>

#include "card/card.h"

class Score : public Card
{
public:
    Score();
    Score(std::vector<Card *>);

    std::vector<Card *> scoreHistory;

    bool operator==(const Score &) const;
    bool operator!=(const Score &other) const;
};
