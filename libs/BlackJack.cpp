#include "BlackJack.hpp"

void BlackJack::setNumberOfPlayers( unsigned int number)
{
    for(unsigned int i = 0; i < number; ++i){
        Player player;
        player.setName(
            "Player" + i
        );
        this->players.push_back(player);
    }
    
}

string BlackJack::start()
{
    struct Winner
    {
        vector<int> sum;
        string winner;
    };
    
    for (size_t i = 0; i < this->numberOfPlayers; i++)
    {
        dealCard(this->players[i]);
        dealCard(this->players[i]);
    }
    
    for (size_t i = 0; i < this->numberOfPlayers; i++)
    {
        bool finish = false;
        while (!finish)
        {
            cout<< "Mais uma carta?";
            cin >> finish;
            finish &= 0;
            dealCard(this->players[i]);
        }
        
    }

    Winner winner;
    for (size_t i = 0; i < this->numberOfPlayers; i++)
    {
        Player player = players[i];
        winner.sum.push_back(player.getCardsSum());
        if(!i){
            if (winner.sum[i] > winner.sum[i -1])
            {
                winner.winner = player.getName();
            }
            
        }else{
            winner.winner = player.getName();
        }               
    }
    return winner.winner;    
}

void BlackJack::dealCard(Player player)
{
    Card card = this->cards[0];
    this->cards.erase(cards.begin());
    player.setHand(card);
}

