
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
