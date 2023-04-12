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
    void sortCards(std::vector<Card *> *);
    Card *sendCard();
    Card *selectCard(std::vector<Score> *, Types type = Types::Empty);
    void seperateCardsByTrump();

    void addCardToDeck(Card *);
    int sendTrumpValue(int tValue = 0);
    Types sendTrumpType();
    bool operator==(const PlayerEngine &other) const;
};
