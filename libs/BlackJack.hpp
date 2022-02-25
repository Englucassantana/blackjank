#ifndef __BLACKJACK_H__
#define __BLACKJACK_H__

#include <iostream>
#include <vector>
#include "Deck.hpp"
#include "Player.hpp"

using namespace std;

class BlackJack : public Deck
{
private:
    int round,
        numberOfPlayers = 0;
    vector<Player> players;

public:
    BlackJack(ifstream deck);
    BlackJack(ifstream deck, int numberOfPlayers);
    ~BlackJack();
    void setNumberOfPlayers(unsigned int number);
    string start();
    void dealCard(Player player);
};

#endif // __BLACKJACK_H__