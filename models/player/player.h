#pragma once

#include <vector>

// #include "card/card.h"
#include "score/score.h"

class Player
{
protected:
    int m_id;
    Types trumpType;
    int trumpSize;
    int importantCardSize;

public:
    Player();
    Player(int iid);

    int id();
    void setID(int);

    std::vector<Score> scores;
    std::vector<Card *> player_deck;
};
