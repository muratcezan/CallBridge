#pragma once
#include <map>

#include "player/player.h"

class PlayerEngine : public Player
{
public:
    PlayerEngine();
    PlayerEngine(size_t);

    void engine();
    void selectTrump();
    void sortCards();
    Card *sentCard();
    void getCard(Card *);
    int sendTrumpValue(int tValue = 0);
    Types sendTrumpType();
};
