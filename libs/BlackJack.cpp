#include "BlackJack.hpp"

void BlackJack::setNumberOfPlayers( unsigned int number)
{
  this->numberOfPlayers = number;
  for(unsigned int i = 0; i < number; ++i){
    Player player;
    player.setName(
      "Player" + to_string(i+1)
    );
    cout << player.getName() <<endl;
    this->players.push_back(player);
  }
  
}

string BlackJack::start()
{
  cout << "Iniciando o jogo com " << this->numberOfPlayers <<" Jogadores" << endl;
  
  for (size_t i = 0; i < this->numberOfPlayers; i++)
  {
    dealCard(i);
    dealCard(i);   
  }

  for (size_t i = 0; i < this->numberOfPlayers; i++)
  {
    string finish = "YES";
    while (finish == "YES" || finish == "Y")
    {
      cout<< "Player " << i + 1 << " mais uma carta? (Yes/No)";
      cin >> finish;
      if (finish == "YES" || finish == "Y")
      {
        dealCard(i);
      }
      
    }
    
  }

  unsigned int sum;
  string winner;
  for (size_t i = 0; i < this->numberOfPlayers; i++)
  {
    Player player = this->players.at(i);
    cout 
      << "O "
      << player.getName()
      << " tem "
      << player.getCardsSum()
      << endl;       
    if(i){
      if (player.getCardsSum() > sum)
      {
        winner = player.getName();
      }
      
    }else{
      sum = player.getCardsSum();
      winner = player.getName();
    }               
  }
  cout << "O Ganhador foi " << winner << endl;
  return winner;    
}

void BlackJack::dealCard(int i)
{
  Card card = this->cards.at(0);
  this->players.at(i).setHand(card);
  this->cards.erase(cards.begin());    
}

BlackJack::BlackJack(string path, int numberOfPlayers): Deck(path){
  this->setNumberOfPlayers(numberOfPlayers);
}