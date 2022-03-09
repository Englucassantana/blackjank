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
        string finish = "YES";
        while (finish == "YES" || finish == "Y")
        {
            dealCard(i);
            cout<< "Player " << i + 1 << " mais uma carta? (Yes/No)";
            cin >> finish;
        }
        
    }

    struct Winner
    {
        vector<int> sum;
        string winnerName;
    };
    
    Winner winner;
    for (size_t i = 0; i < this->numberOfPlayers; i++)
    {
        Player player = this->players.at(i);
        cout 
            << "O "
            << player.getName()
            << " tem "
            << player.getCardsSum()
            << endl;
        winner.sum.push_back(player.getCardsSum());
        if(!i){
            if (winner.sum[i] > winner.sum[i -1])
            {
                winner.winnerName = player.getName();
            }
            
        }else{
            winner.winnerName = player.getName();
        }               
    }
    cout << "O Ganhador foi " << winner.winnerName << endl;
    return winner.winnerName;    
}

void BlackJack::dealCard(int i)
{
    cout << "Dando as cartas..." << endl;
    cout << "Carta " << this->cards.at(0).getIntValue() << endl;
    Card card = this->cards.at(0);
    this->players.at(i).setHand(card);
    this->cards.erase(cards.begin());    
    cout << "Carta dada!" << endl;
}

BlackJack::BlackJack(string path, int numberOfPlayers): Deck(path){
    this->setNumberOfPlayers(numberOfPlayers);
}