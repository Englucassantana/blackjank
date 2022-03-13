#include "Deck.hpp"

Deck::Deck(string path)
{
  ifstream deck(path);

  if (deck.is_open())
  {
    string tuple;
    while (getline(deck,tuple))
    {
      Card card;
      card.setValue(tuple.substr(0, tuple.find(" ")));
      tuple.erase(0, tuple.find(" ") + 1);
      card.setSuit(tuple.substr(0, tuple.find(" ")));
      this->cards.push_back(card);

      cout 
        << "Valor : "
        << card.getValue()
        << "  Naipe : "
        << card.getSuit()
        << "\n";
    }    
  } else{
    cout << "Arquivo não encontrado";
  }
  
}

void Deck::shuffle()
{
  default_random_engine generator;
  vector<Card> newCards;
  int i = 0;
  ofstream outFile;
  outFile.open("./data/shuffleDeck.txt");

  while(cards.size()>0){
    uniform_int_distribution<int> distribution(0,cards.size() - 1);
    int randomNumber = distribution(generator);
    newCards.push_back(cards.at(randomNumber));
    this->cards.erase(cards.begin()+randomNumber);

    string card;
    (this->cards.size()!=0) ? 
      card = newCards.at(i).getValue() + " " + newCards.at(i).getSuit() + "\n" :
      card = newCards.at(i).getValue() + " " + newCards.at(i).getSuit();
    
    outFile.write(card.c_str(), card.size());
    
    ++i;
  }

  outFile.close();
  this->cards = newCards;
}