
#include "player.h"

Player::Player() : trumpType(Types::Empty), trumpSize(0), importantCardSize(0) {}

Player::Player(int iid) : m_id(iid), trumpType(Types::Empty), trumpSize(0), importantCardSize(0) {}

int Player::id()
{
    return m_id;
}
void Player::setID(int id)
{
    m_id = id;
}
bool Player::operator==(const Player &other) const
{
    return m_id == other.m_id && trumpType == other.trumpType && trumpSize == other.trumpSize && importantCardSize == other.importantCardSize;
}
bool Player::operator!=(const Player &other) const
{
    return !(*this == other);
}