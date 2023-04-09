#include <algorithm>
#include <unordered_map>
#include <random>
#include <iostream>

#include "player_engine.h"

PlayerEngine::PlayerEngine() {}
PlayerEngine::PlayerEngine(size_t id) { setID(id); }

void PlayerEngine::engine()
{
    sortCards();
    selectTrump();
}
void PlayerEngine::selectTrump()
{
    if (player_deck.size() != 13 && player_deck.size() != 26)
    {
        return;
    }

    std::map<Types, int> type_values = {{Types::Hearts, 0}, {Types::Diamonds, 0}, {Types::Clubs, 0}, {Types::Spades, 0}};

    for (auto card : player_deck)
    {
        Types type = card->type();
        if (card->value() >= Values::Nine)
        {
            importantCardSize += 1; // 9'dan buyuk kartlarin toplam adeti
            type_values[type] += 1; // her kart için değerini 1 arttırıyoruz
        }
    }

    auto max_type_value = std::max_element(
        type_values.begin(),
        type_values.end(),
        [](const auto &lhs, const auto &rhs)
        {
            return lhs.second < rhs.second;
        });

    trumpType = max_type_value->first;
    trumpSize = max_type_value->second;
}

void PlayerEngine::sortCards()
{
    std::sort(
        player_deck.begin(),
        player_deck.end(),
        [](const auto &card1, const auto &card2)
        {
            if (card1->type() == card2->type())
            {
                return card1->value() > card2->value();
            }
            else
            {
                return card1->type() > card2->type();
            }
        });
}

Card *PlayerEngine::sentCard()
{
    if (player_deck.empty())
    {
        return nullptr;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(0, player_deck.size() - 1);

    int index = distr(gen); // Select random index number
    Card *sent_card = (player_deck.at(index));
    player_deck.erase(player_deck.begin() + index);
    return sent_card;
}

Card *PlayerEngine::selectCard(Types type, bool first)
{
    if (first)
    {
    }
}

void PlayerEngine::getCard(Card *card)
{
    player_deck.push_back(card);
}

int PlayerEngine::sendTrumpValue(int tValue)
{
    if (tValue == 0)
    {
        return trumpSize;
    }
    if (tValue < importantCardSize)
    {
        return ++tValue;
    }
    else
    {
        return 0;
    }
}

Types PlayerEngine::sendTrumpType()
{
    return trumpType;
}
bool PlayerEngine::operator==(const PlayerEngine &other) const
{
    return m_id == other.m_id &&
           trumpType == other.trumpType &&
           trumpSize == other.trumpSize &&
           importantCardSize == other.importantCardSize &&
           scores == other.scores &&
           player_deck == other.player_deck;
}
