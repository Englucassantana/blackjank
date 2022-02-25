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
    
}
