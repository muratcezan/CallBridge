#include "score.h"

Score::Score(/* args */)
{
}

Score::Score(std::vector<Card *> scoreCards)
{
    for (auto card : scoreCards)
    {
        scoreHistory.push_back(card);
    }
}
