#ifndef __DECK_H__
#define __DECK_H__

#include <iostream>
#include <fstream>
#include <vector>
#include "Card.hpp"

using namespace  std;

class Deck
{
protected:
    vector<Card> cards;
    fstream shuffledDeck;
public:
    Deck(string path);
    void shuffle();
};




#endif // __DECK_H__