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
bool Score::operator==(const Score &other) const
{
    if (type() != other.type() || value() != other.value() || scoreHistory.size() != other.scoreHistory.size())
    {
        return false;
    }
    for (int i = 0; i < scoreHistory.size(); i++)
    {
        if (*scoreHistory[i] != *other.scoreHistory[i])
        {
            return false;
        }
    }
    return true;
}
bool Score::operator!=(const Score &other) const
{
    return !(*this == other);
}