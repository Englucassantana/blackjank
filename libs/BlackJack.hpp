#ifndef __BLACKJACK_H__
#define __BLACKJACK_H__

#include <iostream>
#include <vector>
#include "Deck.hpp"
#include "Player.hpp"

using namespace std;

class BlackJack: public Deck
{
private:
  int round, numberOfPlayers;
  vector<Player> players;
  

public:
  BlackJack(string path, int numberOfPlayers);
  void setNumberOfPlayers(unsigned int number);
  string start();
  void dealCard(int i);
};

#endif // __BLACKJACK_H__