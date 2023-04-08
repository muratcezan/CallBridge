// #include "card_contents.h"
#include "deck.h"

Deck::Deck() { createDeck(); }

void Deck::createDeck()
{
    for (auto type = (int)Types::Hearts; type <= (int)Types::Spades; type++)
    {
        for (auto value = (int)Values::Two; value <= (int)Values::As; value++)
        {
            Card *card;
            card = new Card(static_cast<Types>(type), static_cast<Values>(value));

            list.push_back(card);
        }
    }
}