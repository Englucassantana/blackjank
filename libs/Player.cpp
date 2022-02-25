#include "Player.hpp"


void Player::setHand(Card card)
{
    this->hand.push_back(card);
}

int Player::getCardsSum()
{
    int sum;
    for (size_t i = 0; i < this->hand.size(); i++)
    {
        sum += this->hand[i].getIntValue();
    }
    
}

string Player::getName()
{
    return this->name;
}
