#pragma once

#include <vector>

#include "score/score.h"

class Player
{
public:
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
    std::vector<std::vector<Card *> *> playerSeperatedCards;

    bool operator==(const Player &other) const;
    bool operator!=(const Player &other) const;
};
