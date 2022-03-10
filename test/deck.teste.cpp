#include <iostream>
#include "../libs/Deck.hpp"
#include "../libs/BlackJack.hpp"

int main(int argc, char const *argv[])
{
  string path = "data/baralho.txt";
  BlackJack match(path,2);
  
  match.start();
  
  return 0;
}
