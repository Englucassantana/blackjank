#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "Card.hpp"
#include <vector>

using namespace std;

class Player
{
private:
    string name;
    vector<Card> hand;
    
public:
    void setHand(Card card);
    void setName(string name);
    int getCardsSum();
    string getName();
};

#endif // __PLAYER_H__