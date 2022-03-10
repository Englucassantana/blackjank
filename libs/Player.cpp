#include "Player.hpp"

void Player::setHand(Card card)
{
  this->hand.push_back(card);
}

void Player::setName(string name)
{
  this->name = name;
}

int Player::getCardsSum()
{
  int sum =0;
  for (size_t i = 0; i < this->hand.size(); i++)
  {
    sum += this->hand.at(i).getIntValue();
  }
  return sum;
}

string Player::getName()
{
  return this->name;
}