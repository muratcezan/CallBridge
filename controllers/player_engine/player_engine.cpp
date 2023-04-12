#include <algorithm>
#include <unordered_map>
#include <random>
#include <ranges>
#include <iostream>

#include "player_engine.h"

/// @brief Contructor
PlayerEngine::PlayerEngine()
{
    for (auto type = (int)Types::Empty; type <= (int)Types::Spades; type++)
    {
        std::vector<Card *> *cardList = new std::vector<Card *>;
        playerSeperatedCards.push_back(cardList);
    }
}

/// @brief
/// @param id
PlayerEngine::PlayerEngine(size_t id)
{
    setID(id);
    for (auto type = (int)Types::Empty; type <= (int)Types::Spades; type++)
    {
        std::vector<Card *> *cardList = new std::vector<Card *>;
        playerSeperatedCards.push_back(cardList);
    }
}

void PlayerEngine::engine()
{
    // sortCards();
    // selectTrump();
}

void PlayerEngine::selectTrump()
{
    std::vector<std::vector<Values>> tSizes;
    for (auto type = (int)Types::Empty; type <= (int)Types::Spades; type++)
    {
        std::vector<Values> cardList;
        tSizes.push_back(cardList);
    }
    for (auto deck : playerSeperatedCards)
    {
        for (auto card : *deck)
        {
            if (card->value() >= Values::Nine)
            {
                std::cout << "ID = " << m_id << " (int)card->type() = " << (int)card->type() << " (int)card->value() = " << (int)card->value() << std::endl;

                switch (card->type())
                {
                case Types::Hearts:
                    tSizes.at((int)Types::Hearts).push_back(card->value());
                    importantCardSize++;
                    break;
                case Types::Diamonds:
                    tSizes.at((int)Types::Diamonds).push_back(card->value());
                    importantCardSize++;
                    break;
                case Types::Clubs:
                    tSizes.at((int)Types::Clubs).push_back(card->value());
                    importantCardSize++;
                    break;
                case Types::Spades:
                    tSizes.at((int)Types::Spades).push_back(card->value());
                    importantCardSize++;
                    break;
                default:
                    break;
                }
            }
        }
    }

    for (auto i = (int)Types::Empty; i < (int)Types::Spades; i++)
    {
        switch (i)
        {
        case (int)Types::Hearts:
            if (trumpSize < tSizes.at(i).size())
            {
                trumpSize = tSizes.at(i).size();
                trumpType = Types::Hearts;
            }
            break;

        case (int)Types::Diamonds:
            if (trumpSize < tSizes.at(i).size())
            {
                trumpSize = tSizes.at(i).size();
                trumpType = Types::Diamonds;
            }
            break;

        case (int)Types::Clubs:
            if (trumpSize < tSizes.at(i).size())
            {
                trumpSize = tSizes.at(i).size();
                trumpType = Types::Clubs;
            }
            break;

        case (int)Types::Spades:
            if (trumpSize < tSizes.at(i).size())
            {
                trumpSize = tSizes.at(i).size();
                trumpType = Types::Spades;
            }
            break;

        default:
            break;
        }
    }
    std::cout << "LAST = trumpSize = " << trumpSize << std::endl;

    // if (player_deck.size() != 13 && player_deck.size() != 26)
    // {
    //     return;
    // }

    // std::map<Types, int> type_values = {{Types::Hearts, 0}, {Types::Diamonds, 0}, {Types::Clubs, 0}, {Types::Spades, 0}};

    // for (auto card : player_deck)
    // {
    //     Types type = card->type();
    //     if (card->value() >= Values::Nine)
    //     {
    //         importantCardSize += 1; // 9'dan buyuk kartlarin toplam adeti
    //         type_values[type] += 1; // her kart için değerini 1 arttırıyoruz
    //     }
    // }

    // auto max_type_value = std::max_element(
    //     type_values.begin(),
    //     type_values.end(),
    //     [](const auto &lhs, const auto &rhs)
    //     {
    //         return lhs.second < rhs.second;
    //     });

    // trumpType = max_type_value->first;
    // trumpSize = max_type_value->second;

    // seperateCardsByTrump();
}

void PlayerEngine::seperateCardsByTrump()
{
    for (auto card : player_deck)
    {
        switch (card->type())
        {
        case Types::Hearts:
            playerSeperatedCards.at((int)Types::Hearts)->push_back(std::move(card));
            break;
        case Types::Diamonds:
            playerSeperatedCards.at((int)Types::Diamonds)->push_back(std::move(card));
            break;
        case Types::Clubs:
            playerSeperatedCards.at((int)Types::Clubs)->push_back(std::move(card));
            break;
        case Types::Spades:
            playerSeperatedCards.at((int)Types::Spades)->push_back(std::move(card));
            break;
        default:
            break;
        }
    }
}

void PlayerEngine::sortCards(std::vector<Card *> *deck)
{
    std::sort(
        deck->begin(),
        deck->end(),
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

Card *PlayerEngine::sendCard()
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

Card *PlayerEngine::selectCard(std::vector<Score> *score, Types type)
{
    // TODO: TRUMPTYPE 0 GELIYOR. HALBUKI GUNCEL OLMALI!!!!!! BU HATAYI FIXLE
    std::cout << "(int)trumpType = " << (int)trumpType << std::endl;
    if (score->size() == 0)
    {
        // std::cout << (int)playerSeperatedCards.at(2)->front()->value() << std::endl;
    }
    // if (first)
    // {
    //     for (auto it = std::begin(player_deck); it != std::end(player_deck); ++it)
    //     {
    //         std::cout << (int)(*it)->type() << std::endl;
    //     }
    //     // Card *selectedCard = nullptr;
    //     // int max_value = -1;

    //     // for (auto it = player_deck.begin(); it != player_deck.end(); it++)
    //     // {
    //     //     if ((*it)->type() == trumpType && (int)(*it)->value() > max_value)
    //     //     {
    //     //         max_value = (int)(*it)->value();
    //     //         selectedCard = *it;
    //     //     }
    //     // }

    //     // if (selectedCard != nullptr)
    //     // {
    //     //     player_deck.erase(std::remove(player_deck.begin(), player_deck.end(), selectedCard), player_deck.end());
    //     // }

    //     // return selectedCard;
    // }
    // else
    // {
    // }
}

void PlayerEngine::addCardToDeck(Card *card)
{
    switch (card->type())
    {
    case Types::Hearts:
        playerSeperatedCards.at((int)Types::Hearts)->push_back(std::move(card));
        sortCards(playerSeperatedCards.at((int)Types::Hearts));
        break;
    case Types::Diamonds:
        playerSeperatedCards.at((int)Types::Diamonds)->push_back(std::move(card));
        sortCards(playerSeperatedCards.at((int)Types::Diamonds));
        break;
    case Types::Clubs:
        playerSeperatedCards.at((int)Types::Clubs)->push_back(std::move(card));
        sortCards(playerSeperatedCards.at((int)Types::Clubs));
        break;
    case Types::Spades:
        playerSeperatedCards.at((int)Types::Spades)->push_back(std::move(card));
        sortCards(playerSeperatedCards.at((int)Types::Spades));
        break;
    default:
        break;
    }
    // player_deck.push_back(card);
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
