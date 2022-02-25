#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>
#include <string>

using namespace std;

class Card
{
private:
    int value;
    string suit;
public:
    string getValue();
    int getIntValue();
    void setValue(string value);
    string getSuit();
    void setSuit(string suit);
};

#endif // __CARD_H__